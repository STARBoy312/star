#include <iostream>
#include <string>
using namespace std;
int main() {
    string arr[] = { "elephant", "tiger", "cat", "mouse" };
    string a, b;
    cout << "请输入两个动物名称：" << endl;
    cin >> a >> b;
    int m = 0;

    while (m < 4 && (a != arr[m] && b != arr[m])) {
        m++;
    }
    cout << m << endl;

    if (m < 3 && a == arr[m + 1] && b == arr[m]) {
        cout << "tiangou txdy" << endl;
    }
    else {
        cout << "tiangou yiwusuoyou" << endl;
    }

    return 0;
}
