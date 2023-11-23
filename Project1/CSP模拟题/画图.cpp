#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x1, y1, x2, y2, s1;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	s1 = (x2 - x1) * (y2 - y1);
	for (int i = 0; i < n; i++) {
		int x3, y3, x4, y4,s2;
		cin >> x3;
		cin >> y3;
		cin >> x4;
		cin >> y4;
		s2 = (x4 - x3) * (y4 - y3);
		
	}

	system("pause");
	return 0;
}