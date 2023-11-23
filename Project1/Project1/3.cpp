#include<iostream>
using namespace std;
int main() {
	int n,p,num=0;
	char v;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p;
		
		if (p%4==0) {
			cout << p / 4 <<" ";
			cout << p / 2 << endl;
		}
		else if (p % 2 == 0) {
			while (p % 4 != 0) {
				p -= 2;
				num++;
			}
			cout << num + p / 4 << " ";
			cout << p / 2<< endl;
		}
		else {
			cout << 0 << " ";
			cout << 0 << endl;
		}
	}

	system("pause");
	return 0;
}