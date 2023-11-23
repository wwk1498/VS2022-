#include<iostream>
using namespace std;
int main() {
	int n, tep, sum = 0, count = 1;
	cin >> n;
	while (n != 0) {
		if (n == 1) {
			tep = 1;
			sum += 1;
			count++;
		}
		else if (n == 2) {
			if (count == 1 || tep == 1) {
				tep = 2;
				sum += tep;
				count++;
			}
			else {
				tep += 2;
				sum += tep;
				count++;
			}
		}
		cin >> n;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}