#include<iostream>
using namespace std;
int main() {
	int n,sum=0;
	int s[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int tep = s[0];
	for (int j = 1; j < n-1; j++) {
		if ((s[j] > tep && s[j + 1] > s[j])||(s[j] < tep && s[j + 1] < s[j])) {
			tep = s[j];
		}
		else {
			tep= s[j];
			sum++;
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}