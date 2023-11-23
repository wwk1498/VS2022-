#include<iostream>
using namespace std;
/*
* 在C++中，父类不能直接使用new关键字来创建子类对象。
但是可以通过父类指针指向子类对象，然后使用虚函数来实现多态。
* class Parent {
  public:
    virtual void doSomething() {
        // 父类的操作
    }
};

class Child : public Parent {
  public:
    void doSomething() {
        // 子类的操作
    }
};

int main() {
    Parent* obj = new Child();  // 通过父类指针指向子类对象

    obj->doSomething();  // 调用子类对象的虚函数

    delete obj;

    return 0;
}
*/




//多态计算器
class person {
public:
	int a;
	int b;
	virtual int add() {
		return 0;
	}
};
class ma :public person {
public:
	int add() {
		return a+b;
	}
};

void  test01() {
	person  *ab=new ma() ;
	ab->a = 12;
	ab->b= 13;
	cout << ab->add() << endl;

}
int main(void) {
	test01();
	system("pause");
	return 0;
}

