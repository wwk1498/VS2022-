#include<iostream>
using namespace std;

class person1 {
public:
	int a;
	person1() {
		a = 12;
	}
};

class person2 {
public:
	int a;
	person2() {
		a= 112;
	}
};

class son :public person1, public person2 {
public:
	int c;
	int d;
	son() {
		c = 13;
		d = 15;
	}
};

void  test01() {
	son s;
	cout << s.person1::a << endl;
}
int main(void) {
	test01();
	system("pause");
	return 0;
}