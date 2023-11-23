#include<iostream>
using namespace std;
int main() {
	int n, k, t, x1, y1, x2, y2;
	int sum1 = 0;
	int sum2 = 0;
	cin >> n;
	cin >> k;
	cin >> t;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	while (n != 0) {
		int index = 0;
		int sum3[1001] = { 0 };
		for (int i = 0; i < t; i++) {
			int x, y;
			cin >> x;
			cin >> y;
			if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
				sum3[index++] = i;
			}
		}
		if (index > 0) {
			sum1++;
			if (index > 1&&index>=k) {
				int p = 1;
				int max = 0;
				int tep = sum3[0];
				for (int f = 1; f < index; f++) {
					if (sum3[f] - tep != 1) {
						tep = sum3[f];
						max = p;
						p = 1;
					}
					else {
						p++;
						max = p;
					}
				}
				if (max >= k) {
					sum2++;
				}
			}
		}
		n--;
	}
	cout << sum1 << endl;
	cout << sum2 << endl;
	system("pause");
	return 0;
}