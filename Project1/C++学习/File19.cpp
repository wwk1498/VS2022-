#include<iostream>
using namespace std;

//动态多态满足条件：
//1.有继承关系
//2.子类重写父类虚函数

//动态多态使用：
//父类的指针或者引用执行子类对象

class animal {
public:
	virtual void speak() {
		cout << "dw在说话" << endl;
	}
};

class cat :public animal {
public:
	 void speak() override{
		cout << "m在说话" << endl;
	}
};
class dog :public animal {
public:
	void speak() override {
		cout << "g在说话" << endl;
	}
};

void  dospeak(animal & anim) {
	anim.speak();
}
void  test01() {
	cat c;
	dospeak(c);
	dog d;
	dospeak(d);
}
int main(void) {
	test01();
	system("pause");
	return 0;
}