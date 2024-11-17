#include <iostream>
using namespace std;

// 定义链表节点结构体
struct Node {
    int data;           // 数据域
    Node* next;         // 指针域
    Node(int d) : data(d), next(NULL) {}
};

// 约瑟夫环问题
int josephus(int n, int m) {
    // 创建循环链表
    Node* head = new Node(1);       // 头节点
    Node* prev = head;              // 上一个节点
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);    // 创建新节点
        prev->next = newNode;           // 上一个节点指向新节点
        prev = newNode;                 // 更新上一个节点为新节点
    }
    prev->next = head;              // 将最后一个节点的next指向头节点，形成循环链表

    Node* current = head;           // 当前节点
    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            current = current->next;    // 移动m-1次
        }
        Node* temp = current->next;     // 待删除的节点
        current->next = temp->next;     // 当前节点指向待删除节点的下一个节点
        delete temp;                    // 释放待删除节点的内存空间
        current = current->next;        // 更新当前节点为下一个节点
    }

    int u = current->data;   // 最后剩下的节点的编号
    delete current;          // 释放最后剩下的节点的内存空间
    return u;
}

int main() {
    int n, m;
    cout << "请输入n和m的值：";
    cin >> n >> m;

    if (m >= n) {
        cout << "输入不合法，m必须小于n。" << endl;
        return 0;
    }

    int u = josephus(n, m);
    cout << "剩下最后一个人的编号为：" << u << endl;

    return 0;
}
