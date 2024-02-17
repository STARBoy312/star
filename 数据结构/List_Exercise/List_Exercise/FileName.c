#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int data; //存放数据 
    struct node* next; //创建一个指针 
}Node;

//生成两个非递减次序排列的单链表 len代表长度 
Node* merge(Node* head1, Node* head2, int* len)
{
    Node* p1 = head1->next; //指向链表1的第一个结点 
    Node* p2 = head2->next; //指向链表2的第一个结点
    Node* newHead = (Node*)malloc(sizeof(Node)); //创建一个新的头结点
    newHead->next = NULL; //新链表的头结点指向NULL

    Node* p = newHead; //指向新链表的当前结点

    while (p1 && p2) { //判断链表1和链表2是否都遍历完
        if (p1->data <= p2->data) { //如果链表1的当前结点的值小于等于链表2的当前结点的值
            p->next = p1; //将链表1的当前结点添加到新链表中
            p1 = p1->next; //链表1的指针向后移动一位
        }
        else { //如果链表2的当前结点的值小于链表1的当前结点的值
            p->next = p2; //将链表2的当前结点添加到新链表中
            p2 = p2->next; //链表2的指针向后移动一位
        }
        p = p->next; //新链表的指针向后移动一位
        (*len)++; //新链表的长度加1
    }

    //将剩余的结点添加到新链表中
    if (p1) { //如果链表1还有剩余结点
        p->next = p1; //将链表1剩余的结点添加到新链表中
        while (p1) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
            (*len)++;
        }
    }

    if (p2) { //如果链表2还有剩余结点
        p->next = p2; //将链表2剩余的结点添加到新链表中
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

    return newHead; //返回新链表的头结点

}
    int main()
    {
        Node* head1 = (Node*)malloc(sizeof(Node));
        //创建链表1的头结点 
        head1->next = NULL;
        //链表1的头结点指向NULL 
        Node* p1 = head1;
        //指向链表1的当前结点 
        int num; printf("链表1（以-1结束）：");
        scanf_s("%d", &num);
        while (num != -1)
        {
            Node* node = (Node*)malloc(sizeof(Node));
            //创建一个新的结点 
            node->data = num;
            //将输入的元素赋值给结点的data 
            node->next = NULL;
            //新结点的next指针指向NULL 
            p1->next = node;
            //将新结点添加到链表1中 
            p1 = p1->next;
            //链表1的指针向后移动一位 
            scanf_s("%d", &num);
            //继续输入下一个元素 
        }
        Node* head2 = (Node*)malloc(sizeof(Node)); //创建链表2的头结点
        head2->next = NULL; //链表2的头结点指向NULL
        Node* p2 = head2; //指向链表2的当前结点
        printf("链表2（以-1结束）：");
        scanf_s("%d", &num);
        while (num != -1) {
            Node* node = (Node*)malloc(sizeof(Node)); //创建一个新的结点
            node->data = num; //将输入的元素赋值给结点的data
            node->next = NULL; //新结点的next指针指向NULL
            p2->next = node; //将新结点添加到链表2中
            p2 = p2->next; //链表2的指针向后移动一位
            scanf_s("%d", &num); //继续输入下一个元素
        }

        printf("链表1: ");
        Node* curr = head1->next; //指向链表1的第一个结点
        while (curr) { //遍历链表1并打印元素
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");

        printf("链表2: ");
        curr = head2->next; //指向链表2的第一个结点
        while (curr) { //遍历链表2并打印元素
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");

        int len = 0; //新链表的长度
        Node* mergedHead = merge(head1, head2, &len); //合并链表1和链表2
        printf("新表: ");
        curr = mergedHead->next; //指向新链表的第一个结点
        while (curr) { //遍历新链表并打印元素
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");

        printf("长度: %d\n", len); //打印新链表的长度

        return 0;
    }