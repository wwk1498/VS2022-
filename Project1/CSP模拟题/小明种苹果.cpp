#include<iostream>
#include <cstdlib>
using namespace std;
int main() {
	int n, m,sum,count,	T=0,K=1;
	cin >> n;
	cin >> m;
	int num[1001];
	for (int i = 0; i < n; i++) {
		cin >> sum;
		int total = 0;
		int tep = m;
		while (tep != 0) {
			cin >> count;
			total += abs(count);
			tep--;
		}
		T += sum - total;
		num[i] = total;
	}
	int max = num[0];
	for (int s = 0; s < n; s++) {
		if (num[s] > max) {
			max = num[s];
			K = s+1;
		}
	}
	cout << T << " " << K << " " << max << endl;
	system("pause");
	return 0;
}