#include<iostream>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status; // Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; // ElemType 为可定义的数据类型，此设为 int 类型

#define MAXSIZE 100    // 顺序表可能达到的最大长度

struct Book {
    string id;         // 书号
    string name;       // 书名
    string author;     // 著作者
    int currentStock;  // 现存量
    int totalStock;    // 库存量
};

//用于存储图书的顺序表，其中包括了存储空间的基地址和当前长度
typedef struct {
    Book* elem; // 存储空间的基地址
    int length; // 当前长度
} SqList;

//用于构建索引表的项，包括了书号和在顺序表中的索引
typedef struct {
    string id;     // 书号
    int index;     // 在顺序表中的索引
} IndexItem;

//用于存储索引表的结构，包括了索引项数组和索引表长度
typedef struct {
    IndexItem* items;  // 索引项数组
    int length;        // 索引表长度
} IndexTable;

Status InitList_Sq(SqList& L) { // 顺序表的初始化
    // 构造一个空的顺序表 L
    L.elem = new Book[MAXSIZE]; // 为顺序表分配一个大小为 MAXSIZE 的数组空间
    if (!L.elem)    //如果指向null
        exit(OVERFLOW); // 存储分配失败退出
    L.length = 0; // 空表长度为 0
    return OK;
}

Status InitIndexTable(IndexTable& T, int size) { // 初始化索引表
    // 构造一个空的索引表 T
    T.items = new IndexItem[size]; // 为索引表分配一个大小为 size 的数组空间
    if (!T.items)
        exit(OVERFLOW); // 存储分配失败退出
    T.length = 0; // 空表长度为 0
    return OK;
}

Status GetElem(SqList L, int i, Book& e) {// 顺序表的取值
    if (i < 1 || i > L.length)
        return ERROR; // 判断 i 值是否合理，若不合理，返回 ERROR
    e = L.elem[i - 1]; // elem[i-1] 单元存储第 i 个数据元素
    return OK;
}

int LocateElem_Sq(SqList L, string id) { // 顺序表的查找
    // 顺序表的查找
    for (int i = 0; i < L.length; i++)
        if (L.elem[i].id == id)
            return i + 1; // 查找成功，返回序号 i+1
    return 0; // 查找失败，返回 0
}

Status ListInsert_Sq(SqList& L, int i, Book e) { // 顺序表的插入
    // 在顺序表 L 中第 i 个位置之前插入新的元素 e
    // i 值的合法范围是 1<=i<=L.length+1
    if ((i < 1) || (i > L.length + 1))
        return ERROR; // i 值不合法
    if (L.length == MAXSIZE)
        return ERROR; // 当前存储空间已满
    for (int j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j]; // 插入位置及之后的元素后移
    L.elem[i - 1] = e; // 将新元素 e 放入第 i 个位置
    ++L.length; // 表长增1
    return OK;
}

Status ListDelete_Sq(SqList& L, int i, Book*& e) {
    if (i < 1 || i > L.length)
        return ERROR; // 判断 i 值是否合法
    e = &(L.elem[i - 1]); // 将被删除的元素的地址赋值给 e
    for (int j = i; j < L.length; j++)
        L.elem[j - 1] = L.elem[j]; // 被删除元素之后的元素前移
    --L.length; // 表长减1
    return OK;
}

void DisplayBook(Book book) {
    cout << "书号：" << book.id << endl;
    cout << "书名：" << book.name << endl;
    cout << "著作者：" << book.author << endl;
    cout << "现存量：" << book.currentStock << endl;
    cout << "库存量：" << book.totalStock << endl;
    cout << endl;
}

void DisplayAllBooks(SqList L) {
    if (L.length == 0) {
        cout << "没有图书" << endl;
    }
    else {
        for (int i = 0; i < L.length; i++) {
            cout << "第" << i + 1 << "本书：" << endl;
            DisplayBook(L.elem[i]);
        }
    }
}


void AddBook(SqList& L) {
    Book newBook;
    cout << "请输入书号：";
    cin >> newBook.id;
    cout << "请输入书名：";
    cin >> newBook.name;
    cout << "请输入著作者：";
    cin >> newBook.author;
    cout << "请输入现存量：";
    cin >> newBook.currentStock;
    cout << "请输入库存量：";
    cin >> newBook.totalStock;

    int index = LocateElem_Sq(L, newBook.id);
    if (index != 0) {
        cout << "书号已存在，无法添加新书！" << endl;
        return;
    }

    if (ListInsert_Sq(L, L.length + 1, newBook) == OK) {
        cout << "成功添加新书！" << endl;
    }
    else {
        cout << "添加新书失败！" << endl;
    }
}

void BorrowBook(SqList& L, IndexTable& T) {
    string bookId;
    cout << "请输入要借阅的书号：";
    cin >> bookId;

    int index = LocateElem_Sq(L, bookId);
    if (index == 0) {
        cout << "未找到该书！" << endl;
        return;
    }

    Book& book = L.elem[index - 1];
    if (book.currentStock <= 0) {
        cout << "该书已借完！" << endl;
        return;
    }

    book.currentStock--;

    cout << "成功借阅书籍：" << endl;
    DisplayBook(book);

    // 更新索引表
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
    cout << "请输入要归还的书号：";
    cin >> bookId;

    int index = LocateElem_Sq(L, bookId);
    if (index == 0) {
        cout << "未找到该书！" << endl;
        return;
    }

    Book& book = L.elem[index - 1];
    if (book.currentStock >= book.totalStock) {
        cout << "该书已满库存！" << endl;
        return;
    }

    book.currentStock++;

    cout << "成功归还书籍：" << endl;
    DisplayBook(book);

    // 更新索引表
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
    InitList_Sq(bookList); // 初始化书籍列表

    IndexTable indexTable;
    InitIndexTable(indexTable, 100); // 初始化索引表，假设最多可以存储 100 本书的索引

    int choice = 0;
    while (true) {
        cout << "请选择功能：" << endl;
        cout << "1. 添加书籍" << endl;
        cout << "2. 显示所有书籍" << endl;
        cout << "3. 借阅书籍" << endl;
        cout << "4. 归还书籍" << endl;
        cout << "5. 退出程序" << endl;
        cout << "请输入数字选择功能：";
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
                cout << "程序已退出。" << endl;
                return 0;
            default:
                cout << "无效的选择，请重新输入。" << endl;
                break;
        }
    }

    return 0;
}
