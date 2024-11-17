#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f; // 表示无穷大
const int MAXN = 100; // 最大顶点数

// 定义图的结构体，包含顶点数，边数和邻接矩阵
struct Graph {
    int n, m; // n为顶点数，m为边数
    int matrix[MAXN][MAXN]; // matrix[i][j]表示顶点i到顶点j的边的权值，如果没有边则为INF
};

// 输入图的信息，初始化邻接矩阵
void input_graph(Graph& g) {
    cout << "输入顶点数和边数" << endl;
    cin >> g.n >> g.m; // 输入顶点数和边数
    // 初始化邻接矩阵，对角线元素为0，其他元素为INF
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            if (i == j) g.matrix[i][j] = 0;
            else g.matrix[i][j] = INF;
        }
    }
    // 输入每条边的起点，终点和权值，更新邻接矩阵
    for (int i = 0; i < g.m; i++) {
        int u, v, w; // u为起点，v为终点，w为权值
        cout << "输入起点，终点，权值" << endl;
        cin >> u >> v >> w;
        g.matrix[u][v] = w; // 有向图只需更新一个方向的权值
    }
}

// 找出未访问过的顶点中距离源点最近的顶点
int find_min_dist(const Graph& g, const vector<int>& dist, const vector<bool>& visited) {
    int min_dist = INF; // 最小距离，初始为无穷大
    int min_index = -1; // 最小距离顶点的下标，初始为-1
    for (int i = 0; i < g.n; i++) { // 遍历所有顶点
        // 如果顶点i未访问过，且距离小于当前最小距离
        if (!visited[i] && dist[i] < min_dist) {
            min_dist = dist[i]; // 更新最小距离
            min_index = i; // 更新最小距离顶点的下标
        }
    }
    return min_index; // 返回最小距离顶点的下标
}

// 输出最短路径
void print_path(const vector<int>& path, int v) {
    if (path[v] == -1) { // 递归边界，到达源点
        cout << v << " "; // 输出源点
        return; // 结束递归
    }
    print_path(path, path[v]); // 递归输出v的前驱顶点
    cout << v << " "; // 输出v
}

//使用迪杰斯特拉算法完成最短路径
void dijiesitela(const Graph& g, int s) {
    vector<int> dist(g.n, INF); // dist[i]表示源点到顶点i的最短距离，初始为INF
    vector<bool> visited(g.n, false); // visited[i]表示顶点i是否已访问过，初始为false
    vector<int> path(g.n, -1); // path[i]表示顶点i的前驱顶点，初始为-1

    dist[s] = 0; // 源点到自身的距离为0
    for (int i = 0; i < g.n; i++) { // 循环n次
        int u = find_min_dist(g, dist, visited); // 找出未访问过的顶点中距离源点最近的顶点u
        if (u == -1) break; // 如果没有找到，说明剩下的顶点都不可达，退出循环
        visited[u] = true; // 标记u已访问过
        for (int v = 0; v < g.n; v++) { // 遍历所有顶点
            // 如果v未访问过，且u能到达v，且经过u到达v的距离比之前的距离更短
            if (!visited[v] && g.matrix[u][v] < INF && dist[u] + g.matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g.matrix[u][v]; // 更新源点到v的最短距离
                path[v] = u; // 更新v的前驱顶点为u
            }
        }
    }

    // 输出结果
    for (int i = 0; i < g.n; i++) {
        if (i != s) { // 排除源点
            if (dist[i] == INF) { // 如果不可达
                cout << s << "到" << i << "的最短距离为无穷大，无最短路径" << endl;
            }
            else { // 如果可达
                cout << s << "到" << i << "的最短距离为" << dist[i] << "，最短路径为";
                print_path(path, i); // 输出最短路径
                cout << endl;
            }
        }
    }
}
int main() {
    Graph g; // 定义图g
    input_graph(g); // 输入图的信息
    int s; // 定义源点s
    cout << "输入源点" << endl;
    cin >> s; // 输入源点
    dijiesitela(g, s); // 调用迪杰斯特拉算法
    return 0;
}
