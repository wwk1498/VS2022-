/*
deque:双端队列。
deque是一个动态数组，可以在两端进行高效的插入和删除操作。
与vector相比，deque在首尾两端都可以进行插入和删除操作，
而vector只能在尾部进行。


使用deque可以在需要在两端频繁插入和删除元素的情况下提供较高的性能。
需要注意的是，与vector相比，由于deque的内部实现更为复杂，可能会导致稍微慢一些的访问速度。

*/

#include<iostream>
#include<deque>
using namespace std;


int main() {

	//push_back() : 向deque尾部添加一个元素。
	deque<int> dq;
	dq.push_back(10); // {10}
	dq.push_back(20); // {10, 20}


	//push_front() : 向deque头部添加一个元素。
	deque<int> dq;
	dq.push_front(10); // {10}
	dq.push_front(20); // {20, 10}


	//pop_back() : 移除deque尾部的一个元素。
	deque<int> dq = { 10, 20, 30 };
	dq.pop_back(); // {10, 20}


	//pop_front() : 移除deque头部的一个元素。
	deque<int> dq = { 10, 20, 30 };
	dq.pop_front(); // {20, 30}


	//size() : 返回当前deque中的元素数量。
	deque<int> dq = { 10, 20, 30 };
	int size = dq.size(); // 3


	//empty() : 检查deque是否为空，返回布尔值。
	deque<int> dq = { 10, 20, 30 };
	bool isEmpty = dq.empty(); // false


	//clear() : 清空deque中的所有元素。
	deque<int> dq = { 10, 20, 30 };
	dq.clear(); // {}


	//resize() : 调整deque的大小，可以增加或减少元素数量。
	deque<int> dq = { 10, 20, 30 };
	dq.resize(5); // {10, 20, 30, 0, 0}
	dq.resize(2); // {10, 20}


	//at() : 访问指定位置的元素，带有边界检查。
	deque<int> dq = { 10, 20, 30 };
	int element = dq.at(1); // 20


	//front() : 返回deque的第一个元素。
	deque<int> dq = { 10, 20, 30 };
	int firstElement = dq.front(); // 10


	//back() : 返回deque的最后一个元素。
	deque<int> dq = { 10, 20, 30 };
	int lastElement = dq.back(); // 30


	//erase() : 移除指定位置或指定范围的元素。
	deque<int> dq = { 10, 20, 30, 40, 50 };
	dq.erase(dq.begin() + 2); // {10, 20, 40, 50}
	dq.erase(dq.begin() + 1, dq.begin() + 3); // {10, 50}


	//insert() : 在指定位置插入一个或多个元素。
	deque<int> dq = { 10, 20, 30 };
	dq.insert(dq.begin() + 1, 15); // {10, 15, 20, 30}
	dq.insert(dq.begin() + 2, 2, 25); // {10, 15, 25, 25, 20, 30}


	//反转容器内的元素
	deque<int> dq = { 1, 2, 3, 4, 5 };
	reverse(dq.begin(), dq.end());
	for (const auto& element : dq) {
		std::cout << element << " ";
	}//5,4,3,2,1



	system("pause");
	return 0;
}