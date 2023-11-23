#include<iostream>
using namespace std;
int main() {
	int n,summin=0,summax=0;
	int num[101];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	summin += num[0];
	summax += num[0];
	for (int j = 1; j < n; j++) {
		if (num[j] <= num[j - 1]) {
			summin += 0;
			summax += num[j];
		}
		else {
			summin += num[j];
			summax += num[j];
		}
	}
	cout << summax << endl;
	cout << summin<< endl;
	system("pause");
	return 0;
}