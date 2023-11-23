#include<iostream>
#include <cstdlib>
using namespace std;
int main() {
	int n, sum, count, T = 0, D = 0, E = 0;
	int arry[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		int total = 0;
		bool flag = false;
		cin >> num;
		num--;
		cin >> sum;
		int tepsum = sum;
		while (num != 0) {
			cin >> count;
			if (count <= 0) {
				total += abs(count);
			}
			else if(count > 0) {
				sum = count;
				if (tepsum - total > sum&&!flag) {
					arry[D] = i + 1;
					D++;
					flag = true;
				}
				tepsum = sum;
				total= 0;
			}
			num--;
		}
		T += sum - total;
	}

	if (D >= 3) {
		int tp=0,md=0,pf=0;
		for (int s = 0; s < D; s++) {
			if (arry[s] == arry[s + 1] - 1 == arry[s + 2] - 2 || arry[s] + arry[s + 1] + arry[0] == 2 * n || arry[s] + arry[0] + arry[1] == n + 3) {
				E++;
			}
		}
	}
	cout << T << " " << D << " " << E << endl;
	system("pause");
	return 0;
}