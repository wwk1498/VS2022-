#include<iostream>
using namespace std;
int main() {
	int n, k,sum=0,num=0;
	int s[1001];
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int j = 0; j < n; j++) {
		if (sum<k&&j!=n-1) {
			sum += s[j];
		}
		else if (sum < k && j == n - 1) {
			num++;
		}
		else if(sum>=k) {
			sum = 0;
			j--;
			num++;
		}
	}
	cout << num << endl;
	system("pause");
	return 0;
}