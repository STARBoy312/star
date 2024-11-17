#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <ctime>
#include <fstream>
#include <random>
using namespace std;

struct Book {
    string title;
    string author;
    int quantity;
    int stock;

    Book() : quantity(0), stock(0) {}
    Book(const string& t, const string& a, int q, int s) : title(t), author(a), quantity(q), stock(s) {}
};

struct User {
    string username;
    string password;
    string readerId;

};

class LibrarySystem {
private:
    unordered_map<int, Book> books;
    unordered_map<int, list<pair<string, time_t>>> borrowers;
    string booksFileName;

public:



   
    //增加图书
    void addBook(int bookId, const string& title, const string& author, int quantity) {
        if (books.find(bookId) != books.end()) {
            // 图书已存在，增加库存
            books[bookId].stock += quantity;
            books[bookId].quantity += quantity;
            cout << "成功增加库存。" << endl;
        }
        else {
            // 图书不存在，添加新书
            Book book(title, author, quantity, quantity);
            books[bookId] = book;
            borrowers[bookId] = list<pair<string, time_t>>(); // 初始化借阅者列表
            cout << "成功添加新书。" << endl;
        }
    }

    //借阅图书
    void borrowBook(int bookId, const string& borrower) {
        if (books.find(bookId) != books.end()) {
            Book& book = books[bookId];
            if (book.stock > 0) {
                book.stock--;
                time_t returnDate = time(nullptr) + 604800; // 一周后归还
                borrowers[bookId].push_back(make_pair(borrower, returnDate));
                cout << "成功借阅图书。" << endl;
            }
            else {
                cout << "库存不足，无法借阅图书。" << endl;
            }
        }
        else {
            cout << "未找到该图书。" << endl;
        }
    }


    //归还图书
    void returnBook(int bookId, const string& borrower) {
        if (books.find(bookId) != books.end()) {
            Book& book = books[bookId];
            auto& borrowerList = borrowers[bookId];
            auto it = find_if(borrowerList.begin(), borrowerList.end(),
                [&](const pair<string, time_t>& p) { return p.first == borrower; });
            if (it != borrowerList.end()) {
                borrowerList.erase(it);
                book.stock++;
                cout << "成功归还图书。" << endl;
            }
            else {
                cout << "借阅者未借阅该图书。" << endl;
            }
        }
        else {
            cout << "未找到该图书。" << endl;
        }
    }

    //展示图书
    void displayBooks() {
        if (books.empty()) {
            cout << "图书馆目前没有任何图书，请添加图书。" << endl;
        }
        else {
            cout << "图书列表：" << endl;
            for (const auto& pair : books) {
                int bookId = pair.first;
                const Book& book = pair.second;
                cout << "图书编号：" << bookId << "，标题：" << book.title << "，作者：" << book.author
                    << "，可借数量：" << book.quantity << "，库存：" << book.stock << endl;
            }
        }
    }

    //保存图书信息到文件
void saveBooksToFile() {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (const auto& pair : books) {
            int bookId = pair.first;
            const Book& book = pair.second;
            file << "图书编号：" << bookId << "，标题：" << book.title << "，作者：" << book.author
                << "，可借数量：" << book.quantity << "，库存：" << book.stock << endl;
        }
        file.close();
        cout << "图书信息已成功保存到文件。" << endl;
    }
    else {
        cout << "无法打开文件以保存图书信息。" << endl;
    }
}

// 查询借阅信息
void displayBorrowedBooks() {
    if (borrowers.empty()) {
        cout << "目前没有任何借阅信息。" << endl;
    }
    else {
        cout << "借阅信息：" << endl;
        for (const auto& entry : borrowers) {
            int bookId = entry.first;
            const list<pair<string, time_t>>& borrowerList = entry.second;
            if (!borrowerList.empty()) {
                cout << "图书编号：" << bookId << endl;
                for (const auto& borrower : borrowerList) {
                    const string& borrowerName = borrower.first;
                    time_t returnDate = borrower.second;
                    char buffer[26];
                    ctime_s(buffer, sizeof(buffer), &returnDate);
                    cout << "借阅者：" << borrowerName << "，应归还时间：" << buffer;
                }
                cout << endl;
            }
        }
    }
}

//登录
bool login() {
    string username;
    string password;

    cout << "这是一个图书管理系统" << endl;
    cout << "******* 登录 *******" << endl;
    cout << "请输入用户名: ";
    cin >> username;
    cout << "请输入密码: ";
    cin >> password;

    // 进行登录验证
    // 初始用户名和密码都是 "root"
    if (username == "root" && password == "root") {
        cout << "登录成功" << endl;
        return true;
    }
    else {
        cout << "登录名或密码错误，登录失败" << endl;
        cout << "是否继续登录？（Y/N）";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            return login(); // 递归调用登录函数，继续登录
        }
        else {
            return false; // 不登录，退出程序
        }
    }
}


};

int main() {

    LibrarySystem library("books.txt");
    //登录
    if (!library.login()) {
        return 0;
    }
    //登录成功
    int choice;
    do {
        cout << "***************************" << endl;
        cout << "图书馆管理系统" << endl;
        cout << "1. 显示图书列表" << endl;
        cout << "2. 添加新图书" << endl;
        cout << "3. 借阅图书" << endl;
        cout << "4. 归还图书" << endl;
        cout << "5. 查看借阅信息" << endl;
        cout << "0. 退出" << endl;
        cout << "***************************" << endl;
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
        case 1:
            //library.openBooksFile();
            library.displayBooks();
            break;
        case 2: {
            int bookId, quantity;
            string title, author;
            cout << "输入图书编号：";
            cin >> bookId;
            cout << "输入标题：";
            cin.ignore();
            getline(cin, title);
            cout << "输入作者：";
            getline(cin, author);
            cout << "输入数量：";
            cin >> quantity;
            library.addBook(bookId, title,author,quantity);
            library.saveBooksToFile(); // 添加新图书后保存图书信息到文件
            break;
        }
        case 3: {
            int borrowBookId;
            string borrowerName;
            cout << "输入要借阅的图书编号：";
            cin >> borrowBookId;
            cout << "输入借阅者姓名：";
            cin.ignore();
            getline(cin, borrowerName);
            library.borrowBook(borrowBookId, borrowerName);
            library.saveBooksToFile(); // 添加新图书后保存图书信息到文件
            break;
        }
        case 4: {
            int returnBookId;
            string returnBorrowerName;
            cout << "输入要归还的图书编号：";
            cin >> returnBookId;
            cout << "输入借阅者姓名：";
            cin.ignore();
            getline(cin, returnBorrowerName);
            library.returnBook(returnBookId, returnBorrowerName);
            library.saveBooksToFile(); // 添加新图书后保存图书信息到文件
            break;
        }
        case 5: {
            library.displayBorrowedBooks();
            break;
        }
        case 0:
            cout << "感谢使用图书馆管理系统！再见！" << endl;
            break;
        default:
            cout << "无效的选择，请重试。" << endl;
            break;
        }
    } while (choice != 0);

    library.saveBooksToFile(); // 添加新图书后保存图书信息到文件

    return 0;
}

