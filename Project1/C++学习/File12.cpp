#include<iostream>
using namespace std;

class person {
public:
	void operator()(string t) {
		cout << t << endl;
	}
};

void  test01() {
	person()("2222");
	
}
int main(void) {
	test01();
	system("pause");
	return 0;
}