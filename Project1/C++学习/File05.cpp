#include<iostream>
using namespace std;


class fk {
	//friend class person;
	friend  void person::visit();
public:
	string name;
	fk() {
		name = "wp";
		np = "eee";
	}

private:
	string np;
};


class person {

public :
	fk* p;
	person() {
		p = new fk;
	}
	void visit() {
		cout << "kkk:" << p->name << endl;
		cout << "kkk:" << p->np<< endl;
	}
	void visit2() {
		cout << "kkk:" << p->name << endl;
		//cout << "kkk:" << p->np << endl;
	}

};



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