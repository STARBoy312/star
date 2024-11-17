#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 定义图书信息的结构体
struct Book {
    int book_id;
    std::string title;
    std::string author;
    int current_stock;
    int total_stock;
};

// 用户信息结构体
struct User {
    std::string username;
    std::string password;
};

// 图书管理系统类
class LibrarySystem {
private:
    std::unordered_map<int, Book> bookMap; // 用于存储图书信息的哈希表
    std::vector<int> bookIndex; // 书号索引表
    std::unordered_map<std::string, User> users; // 用户信息

public:
    // 添加用户
    void addUser(const std::string &username, const std::string &password) {
        User newUser = {username, password};
        users[username] = newUser;
    }

    // 用户登录
    bool loginUser(const std::string &username, const std::string &password) {
        if (users.find(username) != users.end() && users[username].password == password) {
            std::cout << "Login successful" << std::endl;
            return true;
        } else {
            std::cout << "Invalid username or password" << std::endl;
            return false;
        }
    }

    // 新书入库
    void addBook(int id, const std::string &title, const std::string &author, int total) {
        if (bookMap.find(id) != bookMap.end()) {
            bookMap[id].total_stock += total;
            bookMap[id].current_stock += total;
        } else {
            Book newBook = {id, title, author, total, total};
            bookMap[id] = newBook;
            bookIndex.push_back(id);
        }
    }

    // 图书借阅
    void borrowBook(int id) {
        if (bookMap.find(id) != bookMap.end() && bookMap[id].current_stock > 0) {
            bookMap[id].current_stock--;
            std::cout << "Book with ID " << id << " borrowed successfully" << std::endl;
        } else {
            std::cout << "Book with ID " << id << " is not available for borrowing" << std::endl;
        }
    }

    // 图书归还
    void returnBook(int id) {
        if (bookMap.find(id) != bookMap.end()) {
            bookMap[id].current_stock++;
            std::cout << "Book with ID " << id << " returned successfully" << std::endl;
        } else {
            std::cout << "Book with ID " << id << " was not borrowed" << std::endl;
        }
    }

    // 显示所有图书
    void displayBooks() {
        for (int id : bookIndex) {
            Book book = bookMap[id];
            std::cout << "Book ID: " << book.book_id << ", Title: " << book.title << ", Author: " << book.author
                      << ", Current Stock: " << book.current_stock << ", Total Stock: " << book.total_stock << std::endl;
        }
    }
};

int main() {
    LibrarySystem library;

    // 添加初始用户
    library.addUser("root", "123456");

    // 登录
    std::string username, password;
    std::cout << "这是一个图书管理系统" << std::endl;
    std::cout << "输入你的用户名: ";
    std::cin >> username;
    std::cout << "输入密码: ";
    std::cin >> password;

    if (library.loginUser(username, password)) {
        // 示例：添加一些初始图书
        library.addBook(1, "Book1", "Author1", 5);
        library.addBook(2, "Book2", "Author2", 3);
        library.addBook(3, "Book3", "Author3", 7);

        // 示例：借阅和归还图书
        library.borrowBook(1);
        library.borrowBook(1);
        library.returnBook(1);

        // 示例：显示所有图书
        library.displayBooks();
    }

    return 0;
}
