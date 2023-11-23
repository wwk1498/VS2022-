#include<iostream>
using namespace std;



class fk;
class person {
	
public:
	fk* p;
	person();
	void visit();
	void visit2();

};

class fk {
	friend void person::visit();
public:
	string name;
	fk();

private:
	string np;
};


person::person() {
	p = new fk;
}

void person::visit() {
	cout << "kkk:" << p->name << endl;
	cout << "kkk:" << p->np << endl;
}
void person::visit2() {
	cout << "kkk:" << p->name << endl;
	//cout << "kkk:" << p->np << endl;
}
fk::fk() {
	name = "wp";
	np = "eee";
}



void test01() {
	person ps;
	ps.visit();
	ps.visit2();
}



int main(void) {

	test01();
	system("pause");
	return 0;
}