#include<iostream>
using namespace std;

class person {
public:
	virtual void function() = 0;
};
class man :public person{
public:
	void function() {
		cout << "111" << endl;
	}
};
void  test01() {
	person* p = new man();
	p->function();
}
int main(void) {
	test01();
	system("pause");
	return 0;
}