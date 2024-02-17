#include <iostream>
using namespace std;
#include <string>
int main() {
	string arr[] = { "elephant", "tiger" , "cat","mouse " };
	string a = "ewhr", b = "djf";
	cin >> a >> b;
	int m = 0;

	while (a != arr[m] || b != arr[m]) { m++; }
	cout << m;
	for (int i = 0; (i < 3) && (m != 4); i++)
	{

		if (a == arr[i + 1], b == arr[i])
		{
			cout << "tiangou txdy" << endl;
			break;
		}

		else {
			cout << "tiangou yiwusuoyou" << endl;
			break;
		}
	}



	return 0;
}


