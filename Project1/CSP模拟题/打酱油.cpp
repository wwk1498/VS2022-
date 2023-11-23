#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 30) {
		cout << n / 10 << endl;
	}
	else if (n < 50) {
		cout << 5 << endl;
	}
	else if (n >=50) {
		if (n % 50 < 30) {
			cout << (n / 50) * 7 + (n % 50) / 10 << endl;
		}
		else if (n % 50 >= 30) {
			cout << (n / 50) * 7 + (n % 50) / 30 * 4 + (n % 50) % 30 / 10 << endl;
		}
	}

	system("pause");
	return 0;
}