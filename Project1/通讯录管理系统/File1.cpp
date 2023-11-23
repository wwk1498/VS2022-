#include<iostream>
using namespace std;
int main() {
	int* temp;
	temp = new int[2];
	temp[1] = 8;
	cout << temp[1];
	system("pause");
	return 0;
}