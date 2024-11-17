#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f; // ��ʾ�����
const int MAXN = 100; // ��󶥵���

// ����ͼ�Ľṹ�壬�������������������ڽӾ���
struct Graph {
    int n, m; // nΪ��������mΪ����
    int matrix[MAXN][MAXN]; // matrix[i][j]��ʾ����i������j�ıߵ�Ȩֵ�����û�б���ΪINF
};

// ����ͼ����Ϣ����ʼ���ڽӾ���
void input_graph(Graph& g) {
    cout << "���붥�����ͱ���" << endl;
    cin >> g.n >> g.m; // ���붥�����ͱ���
    // ��ʼ���ڽӾ��󣬶Խ���Ԫ��Ϊ0������Ԫ��ΪINF
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            if (i == j) g.matrix[i][j] = 0;
            else g.matrix[i][j] = INF;
        }
    }
    // ����ÿ���ߵ���㣬�յ��Ȩֵ�������ڽӾ���
    for (int i = 0; i < g.m; i++) {
        int u, v, w; // uΪ��㣬vΪ�յ㣬wΪȨֵ
        cout << "������㣬�յ㣬Ȩֵ" << endl;
        cin >> u >> v >> w;
        g.matrix[u][v] = w; // ����ͼֻ�����һ�������Ȩֵ
    }
}

// �ҳ�δ���ʹ��Ķ����о���Դ������Ķ���
int find_min_dist(const Graph& g, const vector<int>& dist, const vector<bool>& visited) {
    int min_dist = INF; // ��С���룬��ʼΪ�����
    int min_index = -1; // ��С���붥����±꣬��ʼΪ-1
    for (int i = 0; i < g.n; i++) { // �������ж���
        // �������iδ���ʹ����Ҿ���С�ڵ�ǰ��С����
        if (!visited[i] && dist[i] < min_dist) {
            min_dist = dist[i]; // ������С����
            min_index = i; // ������С���붥����±�
        }
    }
    return min_index; // ������С���붥����±�
}

// ������·��
void print_path(const vector<int>& path, int v) {
    if (path[v] == -1) { // �ݹ�߽磬����Դ��
        cout << v << " "; // ���Դ��
        return; // �����ݹ�
    }
    print_path(path, path[v]); // �ݹ����v��ǰ������
    cout << v << " "; // ���v
}

//ʹ�õϽ�˹�����㷨������·��
void dijiesitela(const Graph& g, int s) {
    vector<int> dist(g.n, INF); // dist[i]��ʾԴ�㵽����i����̾��룬��ʼΪINF
    vector<bool> visited(g.n, false); // visited[i]��ʾ����i�Ƿ��ѷ��ʹ�����ʼΪfalse
    vector<int> path(g.n, -1); // path[i]��ʾ����i��ǰ�����㣬��ʼΪ-1

    dist[s] = 0; // Դ�㵽����ľ���Ϊ0
    for (int i = 0; i < g.n; i++) { // ѭ��n��
        int u = find_min_dist(g, dist, visited); // �ҳ�δ���ʹ��Ķ����о���Դ������Ķ���u
        if (u == -1) break; // ���û���ҵ���˵��ʣ�µĶ��㶼���ɴ�˳�ѭ��
        visited[u] = true; // ���u�ѷ��ʹ�
        for (int v = 0; v < g.n; v++) { // �������ж���
            // ���vδ���ʹ�����u�ܵ���v���Ҿ���u����v�ľ����֮ǰ�ľ������
            if (!visited[v] && g.matrix[u][v] < INF && dist[u] + g.matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g.matrix[u][v]; // ����Դ�㵽v����̾���
                path[v] = u; // ����v��ǰ������Ϊu
            }
        }
    }

    // ������
    for (int i = 0; i < g.n; i++) {
        if (i != s) { // �ų�Դ��
            if (dist[i] == INF) { // ������ɴ�
                cout << s << "��" << i << "����̾���Ϊ����������·��" << endl;
            }
            else { // ����ɴ�
                cout << s << "��" << i << "����̾���Ϊ" << dist[i] << "�����·��Ϊ";
                print_path(path, i); // ������·��
                cout << endl;
            }
        }
    }
}
int main() {
    Graph g; // ����ͼg
    input_graph(g); // ����ͼ����Ϣ
    int s; // ����Դ��s
    cout << "����Դ��" << endl;
    cin >> s; // ����Դ��
    dijiesitela(g, s); // ���õϽ�˹�����㷨
    return 0;
}
