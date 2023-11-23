#include<iostream>
#include <list>//链表头文件
using namespace std;

bool compare(int a, int b) {
	// 自定义比较函数，按照绝对值进行排序
	return std::abs(a) < std::abs(b);
}

int main() {

	//1.创建链表对象：使用std::list模板类创建一个链表对象，并指定元素类型
	list<int> myList;  // 创建一个存储 int 类型元素的链表对象


	//在链表末尾插入元素。
	myList.push_back(10);


	//在链表开头插入元素。
	myList.push_front(20);


	//删除链表末尾的元素。
	myList.push_back(10);
	myList.push_back(20);
	myList.pop_back();


	//删除链表开头的元素。
	myList.push_back(10);
	myList.push_back(20);
	myList.pop_front();

	//在指定位置插入元素。
	list<int>::iterator it = myList.begin();
	myList.insert(it, 30);  // 在开头插入元素

	//删除指定位置或范围内的元素。
	list<int>::iterator it = myList.begin();
	myList.erase(it);  // 删除迭代器指向的元素

	//返回链表中元素的数量。
	myList.push_back(10);
	myList.push_back(20);
	cout << myList.size();  // 输出 2

	//检查链表是否为空。
	if (myList.empty()) {
		cout << "链表为空";
	}

	//访问链表的第一个元素
	myList.push_back(10);
	cout << myList.front();  // 输出 10


	//访问链表的最后一个元素。
	myList.push_back(10);
	myList.push_back(20);
	cout << myList.back(); // 输出 20

	//清空链表中的所有元素
	myList.push_back(10);
	myList.clear();

	//遍历链表的常用方法是使用迭代器（iterator）
	myList.push_back(10);
	myList.push_back(20);
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";  // 输出链表中的元素
	}


	//sort()函数用于对链表进行升序排序，默认使用元素的小于比较运算符 < 进行排序。
	myList.push_back(10);
	myList.push_back(30);
	myList.push_back(20);

	myList.sort();  // 对链表进行排序

	for (const auto& element : myList) {
		cout << element << " ";
	}
	// 输出：10 20 30


	
	//如果需要使用自定义的比较函数进行排序，可以提供一个自定义的比较函数作为sort()函数的参数。
	list<int> myList;
	myList.push_back(-10);
	myList.push_back(30);
	myList.push_back(-20);

	myList.sort(compare);  // 使用自定义比较函数对链表进行排序

	for (const auto& element : myList) {
		cout << element << " ";
	}
	// 输出：-10 -20 30



	//reverse()函数用于将链表中的元素反转。
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);

	myList.reverse();  // 反转链表中的元素

	for (const auto& element : myList) {
		cout << element << " ";
	}
	// 输出：30 20 10



	system("pause");
	return 0;
}
