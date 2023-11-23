#include<iostream>
using namespace std;

void digui(string a,int len) {
	cout << a[len] << "  " ;
	if (len == a.length() - 1) {
		return;
	}
	digui(a,len+1);
}

void digui2(string a, int len) {
	if (len == a.length()) {
		return;
	}
	digui2(a, len + 1);
	cout << a[len] << "  ";
}

int fun(int arry[],int target,int i,int j) {
	if (i > j) {
		return -1;
	}
	int m = i + ((j - i) >> 1) ;
	if (target < arry[m]) {
		return fun(arry, target, i, m - 1);
	}
	else if (arry[m] < target) {
		return fun(arry, target, m + 1, j);
	}
	else {
		return m;
	}

}

int main(void) {

	string arry = "abcdefg";
	int p[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num = fun(p, 100, 0, sizeof(p) / sizeof(p[0]) - 1);

	digui(arry, 0);
	cout << endl;
	cout << "----------------------------" << endl;

	digui2(arry, 0);
	cout << endl;
	cout << "----------------------------" << endl;

	
	cout <<num<< endl;
	cout << "----------------------------" << endl;

	system("pause");
	return 0;
}

