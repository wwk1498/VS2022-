#include<iostream>
using namespace std;

/*int* func() {
	int *p=new int(100);
	return p;
}*/

/*int* fknc() {
	int a = 10;
	return &a;
}*/

/*int* funb() {
	int* w = new int[10];
	return w;
}


void fy(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


int& sd() {
	int a = 13;
	return a;
}
*/
//int  add(int a = 12, int b = 34);
/*int  add(int a, int b = 23, int c = 1, int d = 5) {
	return a + b+c+d;
}*/

/*void sdf(int& a) {
	cout << "int &a" << endl;
}
void sdf(const int & a) {
	cout << "const int &a" << endl;
}*/


class AS {
	int a;
	string name;
};




class Easd {

private:
	string m_Name;
	int m_Id;

public:

	void setName(string name) {
		m_Name = name;
	}
	void setId(int id) {
		m_Id = id;
	}

	string getName() {
		return m_Name;
	}

	int getId() {
		return m_Id;
	}

	void prit() {
		cout << getName() << "  " << getId() << endl;
	}

	bool isSame( Easd& s2) {
		if (getId() == s2.getId() && getName() == s2.getName()) {
			return true;
		}
		else {
			return false;
		}
	}



};


bool isSame(Easd& s1, Easd& s2) {
	if (s1.getId() == s2.getId() && s1.getName() == s2.getName()) {
		return true;
	}
	else {
		return false;
	}
}


int main(void) {


	//struct AS asd;
	Easd as;
	as.setName("ww");
	as.setId(4);
	//cout << as.getName() << endl;

	Easd as2;
	as2.setName("ww");
	as2.setId(7);
	bool flag=isSame(as, as2);
	//bool flag =as. isSame(as2);
	if (flag) {
		cout << "相同" << endl;
	}
	else {
		cout << "不相同" << endl;
	}
	

	/*Easd sd;
	sd.setName("李四");
	sd.setId(3);
	//cout << sd.m_Id << sd.m_Name << endl;
	sd.prit();
	sd.prit();*/

	/*int* y = func();
	cout << *y << endl;
	cout << *y << endl;*/

	/*int* w = fknc();
	cout << *w << endl;
	cout<< *w << endl;*/
	//cout << sizeof(void*) << endl;

	/*int* arry = funb();

	for (int i = 0; i < 10; i++) {
		*(arry+i) = 100 + i;
		//arry[i]= 100 + i;

	}

	for (int j = 0; j < 10; j++) {
		cout << *(arry + j) << endl;
	}

	//delete[] arry;*/

	/*int a = 10;
	int & b = a;

	cout << a << endl;
	cout << b << endl;

	int c = 90;
	b =c;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;*/

	/*int a = 12;
	int b = 45;

	cout << a << endl;
	cout << b << endl;

	fy(a, b);

	cout << a << endl;
	cout << b<< endl;*/

	/*int& s = sd();
	cout << s << endl;

	sd() = 1234;
	cout << s << endl;
	cout << s << endl;
	cout << s << endl;*/
	//cout << add(1)<< endl;

	/*int s = 10;
	sdf(s);
	sdf(23);*/

	system("pause");
	return 0;

}