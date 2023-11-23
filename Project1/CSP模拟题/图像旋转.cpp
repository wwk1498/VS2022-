#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int s[1001][1001] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}

	for (int k = m-1; k >=0; k--) {
		for (int y = 0; y < n; y++) {
			cout << s[y][k]<<" ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}