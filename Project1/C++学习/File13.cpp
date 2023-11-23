#include<iostream>
using namespace std;


class Bagep {
public:
	void m1() {
		cout << "2222" << endl;
	}
	void m2() {
		cout << "3333" << endl;
	}
	void m3() {
		cout << "4444" << endl;
	}
};

class JAVA:public Bagep {
public:
	void a1() {
		cout << "1111" << endl;
	}
};

class python:public Bagep {
public:
	void c1() {
		cout << "5555" << endl;
	}
};

void  test01() {
	JAVA m1;
	m1.a1();
	m1.m1();
	m1.m2();
	m1.m3();
	cout << "-----------------------" << endl;
	python p;
	p.c1();
	p.m1();
	p.m2();
	p.m3();
}
int main(void) {
	test01();
	system("pause");
	return 0;
}