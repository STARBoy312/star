#include<iostream>
using namespace std;
int main() {
	int xuekaibo[] = { 351,6846,468,6846,6846,41684,1,2,5 };
	int c = sizeof(xuekaibo) / sizeof(xuekaibo[0]);
	cout << "³õÊ¼Ë³ÐòÎª" << endl;
	for (int i = 0; i < c; i++) {

		cout << xuekaibo[i] << "  ";

	}
	cout << endl;
	for (int i = 1; i < c; i++) {

		for (int j = 0; j < c - i; j++)
		{
			if (xuekaibo[j] > xuekaibo[j + 1]) {
				int temp = xuekaibo[j];
				xuekaibo[j] = xuekaibo[j + 1];
				xuekaibo[j + i] = temp;
			}

		}

	}

	for (int i = 0; i < c; i++) {

		cout << xuekaibo[i] << "  ";

	}
	return 0;
}

