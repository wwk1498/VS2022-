#include<iostream>
using namespace std;
int main() {
	int n,m,L;
	int s[250001];
	int l[257];
	cin >> n;
	cin >> m;
	cin >> L;
	for (int i = 0; i < n * m;i++) {
		cin >> s[i];
	}
	for (int y = 0; y < L; y++) {
		l[y] = 0;
	}
	for (int j = 0; j < n * m; j++) {
		for (int e = 0; e < L; e++) {
			if (s[j] == e) {
				l[e]++;
			}
		}
	}
	for (int k = 0; k < L; k++) {
		if (k != L - 1) {
			cout << l[k] << " ";
		}
		else {
			cout << l[k];
		}
	}
	system("pause");
	return 0;
}