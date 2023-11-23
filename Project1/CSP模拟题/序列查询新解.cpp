#include<iostream>
using namespace std;
#include <cstdlib>
int funj(int arry[], int targe, int size) {
	int i = 0, j = size - 1;
	while (i <= j) {
		int  m = i + ((j - i) >> 1);
		if (targe < arry[m]) {
			j = m - 1;
		}
		else {
			i = m + 1;
		}
	}
	return i - 1;
}

int main() {
	int n, N,sum=0;
	int arry[100001];
	cin >> n;
	cin >> N;
	arry[0] = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> arry[i];
	}
	for (int j = 0; j < N; j++) {
		int f,g,r;
		f= funj(arry, j, n+1);
		r = N / (n + 1);
		g = j / r;
		sum += abs(f - g);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}