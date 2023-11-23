#include<iostream>
using namespace std;
int main() {
	int n,sum=1;
	int num[1001];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int temp=num[0];
	for (int j = 1; j < n; j++) {
		if (temp == num[j]) {
			temp = num[j];
		}
		else {
			temp = num[j];
			sum += 1;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}