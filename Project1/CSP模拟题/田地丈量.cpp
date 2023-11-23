#include<iostream>
using namespace std;
int main() {
	int n,a,b,x1,y1,x2,y2,x,y;
	int num[101][4];
	int sum = 0;
	cin >> n;
	cin >> a;
	cin >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin>>num[i][j];
		}
	}

	for (int p = 0; p < n; p++) {
		for (int v = 0; v < 4; v++) {
			if (v==0) {
				x1= num[p][v];
			}
			else if (v == 1) {
				y1= num[p][v];
			}
			else if (v == 2) {
				x2 = num[p][v];;
			}
			else if (v == 3) {
				y2= num[p][v];
			}
		}

		if (a <= x1 || x2 <= 0) {
			x = 0;
		}
		else if (x1>=0&&x2<=a) {
			x = x2 - x1;
		}
		else if (x1 < 0 && x2>0 && x2 <= a) {
			x = x2 - 0;
		}
		else if (x1>=0&&x1<a&&x2>a) {
			x = a - x1;
		}

		if (b <= y1 || y2 <= 0) {
			y = 0;
		}
		else if (y1 >= 0 && y2 <= b) {
			y = y2 - y1;
		}
		else if (y1 < 0 && y2>0 && y2 <= b) {
			y= y2 - 0;
		}
		else if (y1 >= 0 && y1<b && y2>b) {
			y = b - y1;
		}
		sum += x * y;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}