#include<iostream>
using namespace std;
#include <cstdlib>
int main() {
	int n;
	int s[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int max = 0;
	for (int j = 0; j < n-1; j++) {
		int tep = abs(s[j + 1] - s[j]);
		if ( tep> max) {
			max = tep;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}