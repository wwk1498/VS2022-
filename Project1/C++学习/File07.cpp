#include<iostream>
using namespace std;

class person {
public:
	int a;
	int b;
	person operator+(person& k) {
		person temp;
		temp.a = this->a+ k.a;
		temp.b = this->b+ k.b;
		return temp;
	}
	

};

person operator+(person& k, int num) {
	person temp;
	temp.a = num + k.a;
	temp.b = num + k.b;
	return temp;
}
/*person operator+(person& k, person& M) {
	person temp;
	temp.a = M.a + k.a;
	temp.b = M.b + k.b;
	return temp;
}*/

void test01() {
	person p1;
	p1.a = 12;
	p1.b = 13;
	person p2;
	p2.a = 12;
	p2.b = 13;

	//person p3 = p1 + p2;
	//person p3 = operator+(p1, p2);
	person p3 = p1 + p2;
	person p4= p1 + 12;
	cout << p3.a << p3.b << endl;
	cout << p4.a << p4.b << endl;
}



int main(void) {

	test01();
	system("pause");
	return 0;
}