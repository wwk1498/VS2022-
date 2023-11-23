#include<iostream>
using namespace std;
int main() {
	int n,k,count=1,size=0,s=0;
	int num[1001];
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
		size++;
	}
	while (size != 1) {
		if (num[s%n]!=0&&(count % k == 0 || count % 10 == k)) {
			num[s%n] = 0;
			size--;
		}
		else if (num[s % n] == 0) {
			count--;
		}
		s++;
		count++;
	}

	for (int j = 0; j < n; j++) {
		if (num[j] != 0) {
			cout << num[j] << endl;
		}
	}
	system("pause");
	return 0;
}