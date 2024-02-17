#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int data; //������� 
    struct node* next; //����һ��ָ�� 
}Node;

//���������ǵݼ��������еĵ����� len������ 
Node* merge(Node* head1, Node* head2, int* len)
{
    Node* p1 = head1->next; //ָ������1�ĵ�һ����� 
    Node* p2 = head2->next; //ָ������2�ĵ�һ�����
    Node* newHead = (Node*)malloc(sizeof(Node)); //����һ���µ�ͷ���
    newHead->next = NULL; //�������ͷ���ָ��NULL

    Node* p = newHead; //ָ��������ĵ�ǰ���

    while (p1 && p2) { //�ж�����1������2�Ƿ񶼱�����
        if (p1->data <= p2->data) { //�������1�ĵ�ǰ����ֵС�ڵ�������2�ĵ�ǰ����ֵ
            p->next = p1; //������1�ĵ�ǰ�����ӵ���������
            p1 = p1->next; //����1��ָ������ƶ�һλ
        }
        else { //�������2�ĵ�ǰ����ֵС������1�ĵ�ǰ����ֵ
            p->next = p2; //������2�ĵ�ǰ�����ӵ���������
            p2 = p2->next; //����2��ָ������ƶ�һλ
        }
        p = p->next; //�������ָ������ƶ�һλ
        (*len)++; //������ĳ��ȼ�1
    }

    //��ʣ��Ľ����ӵ���������
    if (p1) { //�������1����ʣ����
        p->next = p1; //������1ʣ��Ľ����ӵ���������
        while (p1) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
            (*len)++;
        }
    }

    if (p2) { //�������2����ʣ����
        p->next = p2; //������2ʣ��Ľ����ӵ���������
        while (p2) {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
            (*len)++;
        }
    }

    p->next = NULL;
    Node* prev = NULL;
    Node* curr = newHead->next;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    newHead->next = prev;

    return newHead; //�����������ͷ���

}
    int main()
    {
        Node* head1 = (Node*)malloc(sizeof(Node));
        //��������1��ͷ��� 
        head1->next = NULL;
        //����1��ͷ���ָ��NULL 
        Node* p1 = head1;
        //ָ������1�ĵ�ǰ��� 
        int num; printf("����1����-1��������");
        scanf_s("%d", &num);
        while (num != -1)
        {
            Node* node = (Node*)malloc(sizeof(Node));
            //����һ���µĽ�� 
            node->data = num;
            //�������Ԫ�ظ�ֵ������data 
            node->next = NULL;
            //�½���nextָ��ָ��NULL 
            p1->next = node;
            //���½����ӵ�����1�� 
            p1 = p1->next;
            //����1��ָ������ƶ�һλ 
            scanf_s("%d", &num);
            //����������һ��Ԫ�� 
        }
        Node* head2 = (Node*)malloc(sizeof(Node)); //��������2��ͷ���
        head2->next = NULL; //����2��ͷ���ָ��NULL
        Node* p2 = head2; //ָ������2�ĵ�ǰ���
        printf("����2����-1��������");
        scanf_s("%d", &num);
        while (num != -1) {
            Node* node = (Node*)malloc(sizeof(Node)); //����һ���µĽ��
            node->data = num; //�������Ԫ�ظ�ֵ������data
            node->next = NULL; //�½���nextָ��ָ��NULL
            p2->next = node; //���½����ӵ�����2��
            p2 = p2->next; //����2��ָ������ƶ�һλ
            scanf_s("%d", &num); //����������һ��Ԫ��
        }

        printf("����1: ");
        Node* curr = head1->next; //ָ������1�ĵ�һ�����
        while (curr) { //��������1����ӡԪ��
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");

        printf("����2: ");
        curr = head2->next; //ָ������2�ĵ�һ�����
        while (curr) { //��������2����ӡԪ��
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");

        int len = 0; //������ĳ���
        Node* mergedHead = merge(head1, head2, &len); //�ϲ�����1������2
        printf("�±�: ");
        curr = mergedHead->next; //ָ��������ĵ�һ�����
        while (curr) { //������������ӡԪ��
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");

        printf("����: %d\n", len); //��ӡ������ĳ���

        return 0;
    }