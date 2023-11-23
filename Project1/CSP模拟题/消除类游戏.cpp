#include<iostream>
using namespace std;
int main() {
	int n, m;
	int s[901];
	int arry[901];
	for (int i = 0; i < n * m; i++) {
		cin >> s[i];
	}
	
	int p = 1;
	int max = 0;
	int tep = s[0];
	int count = 1;
	int d = 0;
	arry[d++] = 0;
	while (count < n * m) {
		if (s[count] - tep == 0) {
			arry[d++] = count;
			p++;
			max = p;
			tep = s[count];
		}
		else {
			d = 0;
			arry[d++] = 0;
			p = 1;
			max = p;
			tep = s[count];
		}
		if (max >= 3) {

		}
		if ((count + 1) % m == 0) {
			int p = 1;
			int max = 0;
			count++;
			int tep = s[count];
		}
		
		count++;
	}


	system("pause");
	return 0;
}