#include <iostream>
#include <stack>
using namespace std;


/*
Ϊ�˽�ÿ���ַ�������ʶ������Ҫ����һ���������Բ�ͬ��
�ַ�������ʶ�����
*/
int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;       //����������1����
    }
    else if (op == '*' || op == '/') {
        return 2;   //�˳��ֿ���2����
    }
    return 0;
}

//���ж�ջ�Ĳ���
/*
    ������������ַ������飬
    ����������ֱ��¼��׺���ʽ�ͺ�׺

*/
void convertInfixToPostfix(char infixExpression[], char postfixExpression[]) {
    int i = 0, j = 0;
    stack<char> operatorStack;    //ջ�ĳ�ʼ��

    while (infixExpression[i] != '\0') {    //��ʼ����
        char c = infixExpression[i];    //��c��¼ÿ����׺��Ԫ��
        if (c == ' ') {
            i++;
            continue;   //�����ո�
        }
        else if (isdigit(c) || isalpha(c)) {    //isdigit�����ǣ����������ж��ַ��Ƿ�Ϊ����
            postfixExpression[j] = c;// �����ֺ���ĸֱ����ӵ���׺���ʽ��
            j++;
        }
        else if (c == '(') {
            operatorStack.push(c);  //��������ջ
        }
        else if (c == ')') {    //���Ѿ�ƥ��
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression[j] = operatorStack.top();// ��ջ������������׺���ʽ
                j++;
                operatorStack.pop();    //����ջ��Ԫ��
            }
            operatorStack.pop();    //������
        }
        else {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfixExpression[j] = operatorStack.top();
                j++;
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        i++;
    }

    while (!operatorStack.empty()) {
        postfixExpression[j] = operatorStack.top(); // ��ջ��ʣ�������������׺���ʽ
        j++;
        operatorStack.pop();
    }
    postfixExpression[j] = '\0';    //��0��β
}

int main() {
    char infixExpression[100];  //���Ƴ���
    cout << "���������׺���ʽ�� ";
    cin.getline(infixExpression, 100);

    char postfixExpression[100];
    convertInfixToPostfix(infixExpression, postfixExpression);
    cout << "���ת����ĺ�׺���ʽ�� " << postfixExpression << endl;

    return 0;
}
