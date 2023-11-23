#include<iostream>
using namespace std;
int main() {
	int n, a=0,b=0,c=0,d=0,sum = 0;
	cin >> n;
	while (n >= 20) {
		sum++;
		if (n >= 70) {
			a++;
		}
		else if (n>=60&&n<=69) {
			b++;
		}
		else if (n >= 50 && n <= 59) {
			c++;
		}
		else if (n<50) {
			d++;
		}
		cin >> n;
	}
	cout << sum << endl;
	cout << a << " " << b << " " << c << " " << d;
	system("pause");
	return 0;
}