#include<iostream>
using namespace std;

void printsour(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j + 1] < a[j]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int printmax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int printmin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

int main() {
	//int n;
	//int s[10001];
	//cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin >> s[i];
	//}
	//cout << printmax(s, n) << " ";
	//
	//printsour(s, n);
	//if (n % 2 != 0) {
	//	cout << s[n / 2] << " ";
	//}
	//else {
	//	if ((s[n / 2 - 1] + s[n / 2]) % 2 == 0) {
	//		//int tep = (s[n / 2 - 1] + s[n / 2]) >>1;
	//		int tep = s[n / 2 - 1] + ((s[n / 2] - s[n / 2 - 1]) >> 1);
	//		cout << tep << " ";
	//	}
	//	else {
	//		int tep = (s[n / 2 - 1] + s[n / 2]) >> 1;
	//		int tep=
	//		cout << tep + 0.5<<" ";
	//	}
	//}
	//cout << printmin(s, n);
	cout<<
	system("pause");
	return 0;
}