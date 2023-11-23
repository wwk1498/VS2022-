#include<iostream>
using namespace std;
int main() {
	int n,m;
	int sum=0;
	cin >> n;
	while (n>0) {
		m=n %10;
		sum += m;
		n /= 10;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}