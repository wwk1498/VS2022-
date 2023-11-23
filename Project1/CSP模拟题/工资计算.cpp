#include<iostream>
using namespace std;
int main() {
	long t,s;
	cin >> t;
	if (t <= 3500) {
		s = t;
	}
	else if (t>3500&&t<=4955) {
		s = 3500 + (t - 3500) / 0.97;
	}
	else if (t>4955&&t<=7655) {
		s = 5000+ (t - 4955) / 0.9;
	}
	else if (t>7655&&t<=11255) {
		s = 8000+(t - 7655) / 0.8;
	}
	else if (t>11255&&t<=30755) {
		s = 12500+(t - 11255) / 0.75;
	}
	else if (t>30755&&t<=44755) {
		s = 38500+(t - 30755) / 0.7;
	}
	else if (t>44755&&t<=61005) {
		s =58500+ (t - 44755) / 0.65;
	}
	else if (t>61005) {
		s = 83500+(t -61005) / 0.55;
	}
	cout << s << endl;
	system("pause");
	return 0;
}