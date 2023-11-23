#include<iostream>
using namespace std;

class person {

public:
	int a;
protected:
	int b;
private:
	int c;
};

class man :public person {
public:
	void s() {
		a = 12;
		b = 6;
		//c = 34; 
	}
};
class many :protected person {
public:
	void s() {
		a = 12;
		b = 6;
		//c = 34; 
	}
};
class mank :private person {
public:
	void s() {
		a = 12;
		b = 6;
		//c = 34; 
	}
};

void  test01() {

	man A;
	A.a = 12;
	//A.b = 17;类外不可访问
	//A.c = 12;不可访问
	many B;
	//B.a = 12;类外不可访问
	//B.b= 12;类外不可访问
	//B.c = 56;不可访问
	mank C;
	//C.a = 34;不可访问
	//C.b= 34;不可访问
	//C.c = 34;不可访问

}
int main(void) {

	test01();
	system("pause");
	return 0;
}