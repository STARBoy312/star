#include <iostream>
#include <stack>
using namespace std;


/*
为了将每个字符串进行识别，所以要设置一个函数来对不同的
字符串进行识别操作
*/
int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;       //基础运算用1返回
    }
    else if (op == '*' || op == '/') {
        return 2;   //乘除分开用2返回
    }
    return 0;
}

//进行对栈的操作
/*
    传入的是两个字符串数组，
    用两个数组分别记录中缀表达式和后缀

*/
void convertInfixToPostfix(char infixExpression[], char postfixExpression[]) {
    int i = 0, j = 0;
    stack<char> operatorStack;    //栈的初始化

    while (infixExpression[i] != '\0') {    //开始遍历
        char c = infixExpression[i];    //用c记录每个中缀的元素
        if (c == ' ') {
            i++;
            continue;   //跳过空格
        }
        else if (isdigit(c) || isalpha(c)) {    //isdigit函数是：可以用来判断字符是否为数字
            postfixExpression[j] = c;// 将数字和字母直接添加到后缀表达式中
            j++;
        }
        else if (c == '(') {
            operatorStack.push(c);  //（进行入栈
        }
        else if (c == ')') {    //）已经匹配
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression[j] = operatorStack.top();// 将栈顶运算符加入后缀表达式
                j++;
                operatorStack.pop();    //弹出栈顶元素
            }
            operatorStack.pop();    //弹出（
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
        postfixExpression[j] = operatorStack.top(); // 将栈中剩余的运算符加入后缀表达式
        j++;
        operatorStack.pop();
    }
    postfixExpression[j] = '\0';    //以0结尾
}

int main() {
    char infixExpression[100];  //限制长度
    cout << "输入你的中缀表达式： ";
    cin.getline(infixExpression, 100);

    char postfixExpression[100];
    convertInfixToPostfix(infixExpression, postfixExpression);
    cout << "输出转换后的后缀表达式： " << postfixExpression << endl;

    return 0;
}
