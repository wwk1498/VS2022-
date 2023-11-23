#include<iostream>
using namespace std;

class CPU {
public:
	virtual void cpujisaun() = 0;
};

class  xianka {
public:
	virtual void xainsshi() = 0;
};

class  neicuntiao {
public:
	virtual void neicun() = 0;
};


class computer {
private:
	CPU* cpu;
	xianka* xik;
	neicuntiao* nct;
public:
	computer(CPU* cpu, xianka* xik, neicuntiao* nct) {
		this->cpu = cpu;
		this->nct = nct;
		this->xik = xik;
	}
	~computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		
		if (nct != NULL) {
			delete nct;
			nct = NULL;
		}
		if (xik != NULL) {
			delete xik;
			xik = NULL;
		}
	}
	void work() {
		cpu->cpujisaun();
		xik->xainsshi();
		nct->neicun();
	}
};

//inter
class Intercup :public CPU {
public:
	void cpujisaun() {
		cout << "InterCPU开始计算了" << endl;
	}
};
class Interxainka :public xianka {
public:
	void xainsshi() {
		cout << "Interxianka开始计算了" << endl;
	}
};
class Interneicuntiao:public neicuntiao{
public:
	void neicun() {
		cout << "Interneicun开始计算了" << endl;
	}
};

//lenovo
class Lenovocpu :public CPU {
public:
	void cpujisaun() {
		cout << "LenovoCPU开始计算了" << endl;
	}
};
class Lenovoxainak :public  xianka {
public:
	void xainsshi() {
		cout << "Lenovoxianka开始计算了" << endl;
	}
};
class Lenovoneicuntiao: public neicuntiao{
public:
	void neicun() {
		cout << "Lenovoneicun开始计算了" << endl;
	}
};


void  test01() {

	CPU* Interlcpu = new Intercup();
	xianka* Interlxainka = new  Interxainka();
	neicuntiao* Interlnct = new Interneicuntiao();

	computer* com = new computer(Interlcpu, Interlxainka, Interlnct);
	com->work();
	delete com;

	CPU* Lenovcpu = new Lenovocpu();
	xianka* Lenovxainka = new Lenovoxainak();
	neicuntiao* Lenovnct = new Lenovoneicuntiao();

	computer* con = new computer(Lenovcpu, Lenovxainka, Lenovnct);
	con->work();
	delete con;
}
int main(void) {
	test01();
	system("pause");
	return 0;
}