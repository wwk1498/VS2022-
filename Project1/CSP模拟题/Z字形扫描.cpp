#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int num[250001];
	for (int i = 0; i < n * n; i++) {
		cin >> num[i];
	}
	int w = 0;
	int count = 0;
	while (w!=n*n-1) {
		if (count == 2) {
			w += 2;
			count = 0;
		}
		cout << num[w] << " ";
		if (w % n != 0) {
			count++;
		}
		else {
			count++;
			if (count == 2) {
				w -= n;
			}
			else {
				w += n - 1;
			}
		}
		w++;
	}











	int s[501][501];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	int k = 0, u = 0;
	int count = 0;
	int num1 = 0;
	while (k != n - 1 && u != n - 1) {
		if (count == 2) {
			k++;
			u -= 2;
			count = 0;
		}
		
		cout << s[k][u] << " ";
		

		count++;
		if (k==0|| k % n != 0) {
			u++;
		}
	}




	for (int k = 0; k < n; k++) {
		for (int u = 0; u < n; u++) {
			if (k == 0&&u==0) {
				
			}
		}
	}





	system("pause");
	return 0;
}