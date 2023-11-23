#include<iostream>
using namespace std;
bool fun(int m) {
	while (m != 0) {
		if (m%10 == 7) {
			return true;
		}
		m /= 10;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	int a = 0,b=0,c=0,d=0,number=1,count = 0;
	while (count!=n) {
		if (fun(number) || number % 7 == 0) {
			if (number % 4 == 1) {
				a++;
			}
			if (number % 4 == 2) {
				b++;
			}
			if (number % 4 == 3) {
				c++;
			}
			if (number % 4 == 0) {
				d++;
			}
			count--;
		}
		count++;
		number++;
	}
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	system("pause");
	return 0;
}