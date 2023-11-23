#include<iostream>
using namespace std;

class person {
public:
	int a;
	person() {
		a = 12;
     }
	void k() {
		cout << "person1111" << endl;
	}
	void k(int a) {
		cout << "person  int 1111" << endl;
	}
};
class mam :public person {
public:
	int a;
	mam() {
		a = 13;
	}
	void k() {
		cout << "mam1111" << endl;
	}
};


void  test01() {
	mam p;
	cout << p.a << endl;
	cout << p.person::a << endl;
}
void  test02() {
	mam p;
	p.k();
	p.person::k();
	p.person::k(122);
}

int main(void) {
	//test01();
	test02();
	system("pause");
	return 0;
}