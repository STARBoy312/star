
#include<iostream>
#include<sstream>
using namespace std;

//�Զ���һ��Node�ṹ��
struct Node {
    string name;
    Node* next;
};

//�Զ���һ��Queue��ʵ�ַ���
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

    //�ж϶����Ƿ�Ϊ��
    bool isEmpty() {
        return count == 0;
    }

    //��Ӳ���
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

    //���Ӳ���
    string dequeue() {
        if (isEmpty()) {
            cout << "����Ϊ��" << endl;
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
    cout << "�����ж�������" << endl;
    cin >> numMale;
    cout << "�����ж���Ů��" << endl;
    cin >> numFeMale;
    cout << "�����ж��ٻغ�" << endl;
    cin >> rounds;

    //��������
    Queue male, female;

    //�����Ե�������ӵ�������
    for (int i = 1; i <= numMale; i++) {
        male.enqueue("�е�" + to_string(i));
    }

    //��Ů�Ե�������ӵ�������
    for (int i = 1; i <= numFeMale; i++) {
        female.enqueue("Ů��" + to_string(i));
    }

    //��ʼƥ�����
    for (int round = 1; round <= rounds; round++) {
        cout << "��" << round << "��������" << endl;
        //�������˶����գ�����һ��һ��ƥ��
        while (!male.isEmpty() && !female.isEmpty()) {
            //Ȼ�����
            cout << male.dequeue() << "------" << female.dequeue() << endl;
        }
        //ĳһ���˿��ˣ��Ǿͣ�ֱ�ӳ���
        if (!male.isEmpty()) {
            cout << "��һ�ֵ�һ��������δ�������: " << male.dequeue() << endl;
        }
        if (!female.isEmpty()) {
            cout << "��һ�ֵ�һ��������δ���Ů��: " << female.dequeue() << endl;
        }
    }
    return 0;
}