#include <iostream>
using namespace std;

// ��������ڵ�ṹ��
struct Node {
    int data;           // ������
    Node* next;         // ָ����
    Node(int d) : data(d), next(NULL) {}
};

// Լɪ������
int josephus(int n, int m) {
    // ����ѭ������
    Node* head = new Node(1);       // ͷ�ڵ�
    Node* prev = head;              // ��һ���ڵ�
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);    // �����½ڵ�
        prev->next = newNode;           // ��һ���ڵ�ָ���½ڵ�
        prev = newNode;                 // ������һ���ڵ�Ϊ�½ڵ�
    }
    prev->next = head;              // �����һ���ڵ��nextָ��ͷ�ڵ㣬�γ�ѭ������

    Node* current = head;           // ��ǰ�ڵ�
    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            current = current->next;    // �ƶ�m-1��
        }
        Node* temp = current->next;     // ��ɾ���Ľڵ�
        current->next = temp->next;     // ��ǰ�ڵ�ָ���ɾ���ڵ����һ���ڵ�
        delete temp;                    // �ͷŴ�ɾ���ڵ���ڴ�ռ�
        current = current->next;        // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
    }

    int u = current->data;   // ���ʣ�µĽڵ�ı��
    delete current;          // �ͷ����ʣ�µĽڵ���ڴ�ռ�
    return u;
}

int main() {
    int n, m;
    cout << "������n��m��ֵ��";
    cin >> n >> m;

    if (m >= n) {
        cout << "���벻�Ϸ���m����С��n��" << endl;
        return 0;
    }

    int u = josephus(n, m);
    cout << "ʣ�����һ���˵ı��Ϊ��" << u << endl;

    return 0;
}
