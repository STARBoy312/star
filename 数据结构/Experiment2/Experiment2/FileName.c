#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
typedef struct Node {
    int data;           // ������
    struct Node* next;  // ָ����
} Node;

// �����½ڵ�   ��ʼ������
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));    //�����ڴ�ռ�
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Լɪ������
int josephus(int n, int m) {
    // ����ѭ������
    Node* head = createNode(1);     // ͷ�ڵ�
    Node* prev = head;              // ��һ���ڵ�
    for (int i = 2; i <= n; i++) {
        Node* newNode = createNode(i);   // �����½ڵ�
        prev->next = newNode;            // ��һ���ڵ�ָ���½ڵ�
        prev = newNode;                  // ������һ���ڵ�Ϊ�½ڵ�
    }
    prev->next = head; // �����һ���ڵ��nextָ��ͷ�ڵ㣬�γ�ѭ������

    Node* current = head;   // ��ǰ�ڵ�
    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            current = current->next;    // �ƶ�m-1��
        }
        Node* temp = current->next;     // ��ɾ���Ľڵ�
        current->next = temp->next;     // ��ǰ�ڵ�ָ���ɾ���ڵ����һ���ڵ�
        free(temp);                     // �ͷŴ�ɾ���ڵ���ڴ�ռ�
        current = current->next;        // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
    }

    int u = current->data;   // ���ʣ�µĽڵ�ı��
    free(current);          // �ͷ����ʣ�µĽڵ���ڴ�ռ�
    return u;
}

int main() {
    int n, m;
    printf("������n��m��ֵ��");
    scanf("%d %d", &n, &m);

    if (m >= n) {
        printf("���벻�Ϸ���m����С��n��\n");
        return 0;
    }

    int u = josephus(n, m);
    printf("ʣ�����һ���˵ı��Ϊ��%d\n", u);

    return 0;
}
