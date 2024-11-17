#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义图书信息的结构体
typedef struct {
    int book_id;
    char title[100];
    char author[100];
    int current_stock;
    int total_stock;
} Book;

// 定义图书节点的结构体
typedef struct Node {
    Book book;
    struct Node *next;
} Node;

// 全局变量，代表图书链表的头节点
Node *head = NULL;

// 函数声明
void addBook(int id, const char *title, const char *author, int total);
void borrowBook(int id);
void returnBook(int id);
void displayBooks();

int main() {
    // 在这里可以编写图形用户界面（GUI）的代码

    // 示例：添加一些初始图书
    addBook(1, "Book1", "Author1", 5);
    addBook(2, "Book2", "Author2", 3);
    addBook(3, "Book3", "Author3", 7);

    // 示例：借阅和归还图书
    borrowBook(1);
    borrowBook(1);
    returnBook(1);

    // 示例：显示所有图书
    displayBooks();

    return 0;
}

// 添加新书或增加库存
void addBook(int id, const char *title, const char *author, int total) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->book.book_id == id) {
            temp->book.total_stock += total;
            temp->book.current_stock += total;
            return;
        }
        temp = temp->next;
    }

    // 创建新节点
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->book.book_id = id;
    strcpy(newNode->book.title, title);
    strcpy(newNode->book.author, author);
    newNode->book.current_stock = total;
    newNode->book.total_stock = total;
    newNode->next = head;
    head = newNode;
}

// 借阅图书
void borrowBook(int id) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->book.book_id == id && temp->book.current_stock > 0) {
            temp->book.current_stock--;
            printf("Book with ID %d borrowed successfully\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d is not available for borrowing\n", id);
}

// 归还图书
void returnBook(int id) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->book.book_id == id) {
            temp->book.current_stock++;
            printf("Book with ID %d returned successfully\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d was not borrowed\n", id);
}

// 显示所有图书
void displayBooks() {
    Node *temp = head;
    while (temp != NULL) {
        printf("Book ID: %d, Title: %s, Author: %s, Current Stock: %d, Total Stock: %d\n",
               temp->book.book_id, temp->book.title, temp->book.author, temp->book.current_stock, temp->book.total_stock);
        temp = temp->next;
    }
}
