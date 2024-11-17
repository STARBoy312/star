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



   
    //����ͼ��
    void addBook(int bookId, const string& title, const string& author, int quantity) {
        if (books.find(bookId) != books.end()) {
            // ͼ���Ѵ��ڣ����ӿ��
            books[bookId].stock += quantity;
            books[bookId].quantity += quantity;
            cout << "�ɹ����ӿ�档" << endl;
        }
        else {
            // ͼ�鲻���ڣ��������
            Book book(title, author, quantity, quantity);
            books[bookId] = book;
            borrowers[bookId] = list<pair<string, time_t>>(); // ��ʼ���������б�
            cout << "�ɹ�������顣" << endl;
        }
    }

    //����ͼ��
    void borrowBook(int bookId, const string& borrower) {
        if (books.find(bookId) != books.end()) {
            Book& book = books[bookId];
            if (book.stock > 0) {
                book.stock--;
                time_t returnDate = time(nullptr) + 604800; // һ�ܺ�黹
                borrowers[bookId].push_back(make_pair(borrower, returnDate));
                cout << "�ɹ�����ͼ�顣" << endl;
            }
            else {
                cout << "��治�㣬�޷�����ͼ�顣" << endl;
            }
        }
        else {
            cout << "δ�ҵ���ͼ�顣" << endl;
        }
    }


    //�黹ͼ��
    void returnBook(int bookId, const string& borrower) {
        if (books.find(bookId) != books.end()) {
            Book& book = books[bookId];
            auto& borrowerList = borrowers[bookId];
            auto it = find_if(borrowerList.begin(), borrowerList.end(),
                [&](const pair<string, time_t>& p) { return p.first == borrower; });
            if (it != borrowerList.end()) {
                borrowerList.erase(it);
                book.stock++;
                cout << "�ɹ��黹ͼ�顣" << endl;
            }
            else {
                cout << "������δ���ĸ�ͼ�顣" << endl;
            }
        }
        else {
            cout << "δ�ҵ���ͼ�顣" << endl;
        }
    }

    //չʾͼ��
    void displayBooks() {
        if (books.empty()) {
            cout << "ͼ���Ŀǰû���κ�ͼ�飬�����ͼ�顣" << endl;
        }
        else {
            cout << "ͼ���б�" << endl;
            for (const auto& pair : books) {
                int bookId = pair.first;
                const Book& book = pair.second;
                cout << "ͼ���ţ�" << bookId << "�����⣺" << book.title << "�����ߣ�" << book.author
                    << "���ɽ�������" << book.quantity << "����棺" << book.stock << endl;
            }
        }
    }

    //����ͼ����Ϣ���ļ�
void saveBooksToFile() {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (const auto& pair : books) {
            int bookId = pair.first;
            const Book& book = pair.second;
            file << "ͼ���ţ�" << bookId << "�����⣺" << book.title << "�����ߣ�" << book.author
                << "���ɽ�������" << book.quantity << "����棺" << book.stock << endl;
        }
        file.close();
        cout << "ͼ����Ϣ�ѳɹ����浽�ļ���" << endl;
    }
    else {
        cout << "�޷����ļ��Ա���ͼ����Ϣ��" << endl;
    }
}

// ��ѯ������Ϣ
void displayBorrowedBooks() {
    if (borrowers.empty()) {
        cout << "Ŀǰû���κν�����Ϣ��" << endl;
    }
    else {
        cout << "������Ϣ��" << endl;
        for (const auto& entry : borrowers) {
            int bookId = entry.first;
            const list<pair<string, time_t>>& borrowerList = entry.second;
            if (!borrowerList.empty()) {
                cout << "ͼ���ţ�" << bookId << endl;
                for (const auto& borrower : borrowerList) {
                    const string& borrowerName = borrower.first;
                    time_t returnDate = borrower.second;
                    char buffer[26];
                    ctime_s(buffer, sizeof(buffer), &returnDate);
                    cout << "�����ߣ�" << borrowerName << "��Ӧ�黹ʱ�䣺" << buffer;
                }
                cout << endl;
            }
        }
    }
}

//��¼
bool login() {
    string username;
    string password;

    cout << "����һ��ͼ�����ϵͳ" << endl;
    cout << "******* ��¼ *******" << endl;
    cout << "�������û���: ";
    cin >> username;
    cout << "����������: ";
    cin >> password;

    // ���е�¼��֤
    // ��ʼ�û��������붼�� "root"
    if (username == "root" && password == "root") {
        cout << "��¼�ɹ�" << endl;
        return true;
    }
    else {
        cout << "��¼����������󣬵�¼ʧ��" << endl;
        cout << "�Ƿ������¼����Y/N��";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            return login(); // �ݹ���õ�¼������������¼
        }
        else {
            return false; // ����¼���˳�����
        }
    }
}


};

int main() {

    LibrarySystem library("books.txt");
    //��¼
    if (!library.login()) {
        return 0;
    }
    //��¼�ɹ�
    int choice;
    do {
        cout << "***************************" << endl;
        cout << "ͼ��ݹ���ϵͳ" << endl;
        cout << "1. ��ʾͼ���б�" << endl;
        cout << "2. �����ͼ��" << endl;
        cout << "3. ����ͼ��" << endl;
        cout << "4. �黹ͼ��" << endl;
        cout << "5. �鿴������Ϣ" << endl;
        cout << "0. �˳�" << endl;
        cout << "***************************" << endl;
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
        case 1:
            //library.openBooksFile();
            library.displayBooks();
            break;
        case 2: {
            int bookId, quantity;
            string title, author;
            cout << "����ͼ���ţ�";
            cin >> bookId;
            cout << "������⣺";
            cin.ignore();
            getline(cin, title);
            cout << "�������ߣ�";
            getline(cin, author);
            cout << "����������";
            cin >> quantity;
            library.addBook(bookId, title,author,quantity);
            library.saveBooksToFile(); // �����ͼ��󱣴�ͼ����Ϣ���ļ�
            break;
        }
        case 3: {
            int borrowBookId;
            string borrowerName;
            cout << "����Ҫ���ĵ�ͼ���ţ�";
            cin >> borrowBookId;
            cout << "���������������";
            cin.ignore();
            getline(cin, borrowerName);
            library.borrowBook(borrowBookId, borrowerName);
            library.saveBooksToFile(); // �����ͼ��󱣴�ͼ����Ϣ���ļ�
            break;
        }
        case 4: {
            int returnBookId;
            string returnBorrowerName;
            cout << "����Ҫ�黹��ͼ���ţ�";
            cin >> returnBookId;
            cout << "���������������";
            cin.ignore();
            getline(cin, returnBorrowerName);
            library.returnBook(returnBookId, returnBorrowerName);
            library.saveBooksToFile(); // �����ͼ��󱣴�ͼ����Ϣ���ļ�
            break;
        }
        case 5: {
            library.displayBorrowedBooks();
            break;
        }
        case 0:
            cout << "��лʹ��ͼ��ݹ���ϵͳ���ټ���" << endl;
            break;
        default:
            cout << "��Ч��ѡ�������ԡ�" << endl;
            break;
        }
    } while (choice != 0);

    library.saveBooksToFile(); // �����ͼ��󱣴�ͼ����Ϣ���ļ�

    return 0;
}

