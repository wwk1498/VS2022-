#include<iostream>
using namespace std;
int main() {
	int n,sum=0;
	cin >> n;
	while (n != 0) {
		int a, b;
		cin >> a;
		cin >> b;
		sum += a*b;
		n--;
	}
	if (sum <= 0) {
		sum = 0;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}