#include<iostream>
using namespace std;
int main() {
	int n, sum = 0;
	int s[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int j = 0; j < n; j++) {
		if (j == 0) {
			cout << (s[j] + s[j + 1]) / 2 <<" ";
		}
		else if (j == n - 1) {
			cout << (s[j] + s[j - 1]) / 2 << endl;
		}
		else {
			cout << (s[j] + s[j - 1] + s[j + 1]) / 3 << " " ;
		}
	}
	system("pause");
	return 0;
}