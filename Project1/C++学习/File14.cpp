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
	//A.b = 17;���ⲻ�ɷ���
	//A.c = 12;���ɷ���
	many B;
	//B.a = 12;���ⲻ�ɷ���
	//B.b= 12;���ⲻ�ɷ���
	//B.c = 56;���ɷ���
	mank C;
	//C.a = 34;���ɷ���
	//C.b= 34;���ɷ���
	//C.c = 34;���ɷ���

}
int main(void) {

	test01();
	system("pause");
	return 0;
}