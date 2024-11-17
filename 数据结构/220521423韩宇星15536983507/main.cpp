#include<iostream>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status; // Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; // ElemType Ϊ�ɶ�����������ͣ�����Ϊ int ����

#define MAXSIZE 100    // ˳�����ܴﵽ����󳤶�

struct Book {
    string id;         // ���
    string name;       // ����
    string author;     // ������
    int currentStock;  // �ִ���
    int totalStock;    // �����
};

//���ڴ洢ͼ���˳������а����˴洢�ռ�Ļ���ַ�͵�ǰ����
typedef struct {
    Book* elem; // �洢�ռ�Ļ���ַ
    int length; // ��ǰ����
} SqList;

//���ڹ�������������������ź���˳����е�����
typedef struct {
    string id;     // ���
    int index;     // ��˳����е�����
} IndexItem;

//���ڴ洢������Ľṹ���������������������������
typedef struct {
    IndexItem* items;  // ����������
    int length;        // ��������
} IndexTable;

Status InitList_Sq(SqList& L) { // ˳���ĳ�ʼ��
    // ����һ���յ�˳��� L
    L.elem = new Book[MAXSIZE]; // Ϊ˳������һ����СΪ MAXSIZE ������ռ�
    if (!L.elem)    //���ָ��null
        exit(OVERFLOW); // �洢����ʧ���˳�
    L.length = 0; // �ձ���Ϊ 0
    return OK;
}

Status InitIndexTable(IndexTable& T, int size) { // ��ʼ��������
    // ����һ���յ������� T
    T.items = new IndexItem[size]; // Ϊ���������һ����СΪ size ������ռ�
    if (!T.items)
        exit(OVERFLOW); // �洢����ʧ���˳�
    T.length = 0; // �ձ���Ϊ 0
    return OK;
}

Status GetElem(SqList L, int i, Book& e) {// ˳����ȡֵ
    if (i < 1 || i > L.length)
        return ERROR; // �ж� i ֵ�Ƿ���������������� ERROR
    e = L.elem[i - 1]; // elem[i-1] ��Ԫ�洢�� i ������Ԫ��
    return OK;
}

int LocateElem_Sq(SqList L, string id) { // ˳���Ĳ���
    // ˳���Ĳ���
    for (int i = 0; i < L.length; i++)
        if (L.elem[i].id == id)
            return i + 1; // ���ҳɹ���������� i+1
    return 0; // ����ʧ�ܣ����� 0
}

Status ListInsert_Sq(SqList& L, int i, Book e) { // ˳���Ĳ���
    // ��˳��� L �е� i ��λ��֮ǰ�����µ�Ԫ�� e
    // i ֵ�ĺϷ���Χ�� 1<=i<=L.length+1
    if ((i < 1) || (i > L.length + 1))
        return ERROR; // i ֵ���Ϸ�
    if (L.length == MAXSIZE)
        return ERROR; // ��ǰ�洢�ռ�����
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j]; // ����λ�ü�֮���Ԫ�غ���
    L.elem[i - 1] = e; // ����Ԫ�� e ����� i ��λ��
    ++L.length; // ����1
    return OK;
}

Status ListDelete_Sq(SqList& L, int i, Book*& e) {
    if (i < 1 || i > L.length)
        return ERROR; // �ж� i ֵ�Ƿ�Ϸ�
    e = &(L.elem[i - 1]); // ����ɾ����Ԫ�صĵ�ַ��ֵ�� e
    for (int j = i; j < L.length; j++)
        L.elem[j - 1] = L.elem[j]; // ��ɾ��Ԫ��֮���Ԫ��ǰ��
    --L.length; // ����1
    return OK;
}

void DisplayBook(Book book) {
    cout << "��ţ�" << book.id << endl;
    cout << "������" << book.name << endl;
    cout << "�����ߣ�" << book.author << endl;
    cout << "�ִ�����" << book.currentStock << endl;
    cout << "�������" << book.totalStock << endl;
    cout << endl;
}

void DisplayAllBooks(SqList L) {
    if (L.length == 0) {
        cout << "û��ͼ��" << endl;
    }
    else {
        for (int i = 0; i < L.length; i++) {
            cout << "��" << i + 1 << "���飺" << endl;
            DisplayBook(L.elem[i]);
        }
    }
}


void AddBook(SqList& L) {
    Book newBook;
    cout << "��������ţ�";
    cin >> newBook.id;
    cout << "������������";
    cin >> newBook.name;
    cout << "�����������ߣ�";
    cin >> newBook.author;
    cout << "�������ִ�����";
    cin >> newBook.currentStock;
    cout << "������������";
    cin >> newBook.totalStock;

    int index = LocateElem_Sq(L, newBook.id);
    if (index != 0) {
        cout << "����Ѵ��ڣ��޷�������飡" << endl;
        return;
    }

    if (ListInsert_Sq(L, L.length + 1, newBook) == OK) {
        cout << "�ɹ�������飡" << endl;
    }
    else {
        cout << "�������ʧ�ܣ�" << endl;
    }
}

void BorrowBook(SqList& L, IndexTable& T) {
    string bookId;
    cout << "������Ҫ���ĵ���ţ�";
    cin >> bookId;

    int index = LocateElem_Sq(L, bookId);
    if (index == 0) {
        cout << "δ�ҵ����飡" << endl;
        return;
    }

    Book& book = L.elem[index - 1];
    if (book.currentStock <= 0) {
        cout << "�����ѽ��꣡" << endl;
        return;
    }

    book.currentStock--;

    cout << "�ɹ������鼮��" << endl;
    DisplayBook(book);

    // ����������
    int i = T.length;
    while (i > 0 && T.items[i - 1].id > bookId) {
        T.items[i] = T.items[i - 1];
        i--;
    }
    T.items[i].id = bookId;
    T.items[i].index = index;
    T.length++;
}

void ReturnBook(SqList& L, IndexTable& T) {
    string bookId;
    cout << "������Ҫ�黹����ţ�";
    cin >> bookId;

    int index = LocateElem_Sq(L, bookId);
    if (index == 0) {
        cout << "δ�ҵ����飡" << endl;
        return;
    }

    Book& book = L.elem[index - 1];
    if (book.currentStock >= book.totalStock) {
        cout << "����������棡" << endl;
        return;
    }

    book.currentStock++;

    cout << "�ɹ��黹�鼮��" << endl;
    DisplayBook(book);

    // ����������
    int i = 0;
    while (i < T.length && T.items[i].id < bookId) {
        i++;
    }
    while (i < T.length && T.items[i].id == bookId) {
        if (T.items[i].index == index) {
            for (int j = i; j < T.length - 1; j++) {
                T.items[j] = T.items[j + 1];
            }
            T.length--;
            break;
        }
        i++;
    }
}


int main() {
    SqList bookList;
    InitList_Sq(bookList); // ��ʼ���鼮�б�

    IndexTable indexTable;
    InitIndexTable(indexTable, 100); // ��ʼ�����������������Դ洢 100 ���������

    int choice = 0;
    while (true) {
        cout << "��ѡ���ܣ�" << endl;
        cout << "1. ����鼮" << endl;
        cout << "2. ��ʾ�����鼮" << endl;
        cout << "3. �����鼮" << endl;
        cout << "4. �黹�鼮" << endl;
        cout << "5. �˳�����" << endl;
        cout << "����������ѡ���ܣ�";
        cin >> choice;

        switch (choice) {
            case 1:
                AddBook(bookList);
                break;
            case 2:
                DisplayAllBooks(bookList);
                break;
            case 3:
                BorrowBook(bookList, indexTable);
                break;
            case 4:
                ReturnBook(bookList, indexTable);
                break;
            case 5:
                cout << "�������˳���" << endl;
                return 0;
            default:
                cout << "��Ч��ѡ�����������롣" << endl;
                break;
        }
    }

    return 0;
}
