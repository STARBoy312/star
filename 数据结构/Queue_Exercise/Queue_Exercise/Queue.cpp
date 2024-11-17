
#include<iostream>
#include<sstream>
using namespace std;

//自定义一个Node结构体
struct Node {
    string name;
    Node* next;
};

//自定义一个Queue，实现方法
class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    //判断队列是否为空
    bool isEmpty() {
        return count == 0;
    }

    //入队操作
    void enqueue(string name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = NULL;
        if (isEmpty()) {
            front = newNode;
        }
        else {
            rear->next = newNode;
        }
        rear = newNode;
        count++;
    }

    //出队操作
    string dequeue() {
        if (isEmpty()) {
            cout << "队列为空" << endl;
            return "";
        }
        string name = front->name;
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        return name;
    }
};

int main() {
    int numMale, numFeMale, rounds;
    cout << "输入有多少男生" << endl;
    cin >> numMale;
    cout << "输入有多少女生" << endl;
    cin >> numFeMale;
    cout << "输入有多少回合" << endl;
    cin >> rounds;

    //创建队列
    Queue male, female;

    //将男性的名字添加到队列中
    for (int i = 1; i <= numMale; i++) {
        male.enqueue("男的" + to_string(i));
    }

    //将女性的名字添加到队列中
    for (int i = 1; i <= numFeMale; i++) {
        female.enqueue("女的" + to_string(i));
    }

    //开始匹配舞伴
    for (int round = 1; round <= rounds; round++) {
        cout << "第" << round << "轮舞伴配对" << endl;
        //当两个人都不空，进行一个一个匹配
        while (!male.isEmpty() && !female.isEmpty()) {
            //然后出队
            cout << male.dequeue() << "------" << female.dequeue() << endl;
        }
        //某一个人空了，那就，直接出队
        if (!male.isEmpty()) {
            cout << "下一轮第一个出场的未配对男性: " << male.dequeue() << endl;
        }
        if (!female.isEmpty()) {
            cout << "下一轮第一个出场的未配对女性: " << female.dequeue() << endl;
        }
    }
    return 0;
}