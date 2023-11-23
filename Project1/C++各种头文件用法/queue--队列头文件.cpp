/*
queue 和 deque 在C++中都属于容器，但它们有一些区别和相同之处。

相同之处：

都是C++标准库提供的容器。
都支持在尾部添加元素和在头部删除元素的操作。
都提供了用于查询容器大小的方法，即 size()。
都支持迭代器的使用。

区别：

底层实现不同：queue 基于 deque 或 list 实现；而 deque 是基于分段数组的实现。
功能不同：queue 是队列，只能在队尾添加元素，在队头删除元素,不能进行随机访问元素；deque 是双端队列，可以在首尾两端进行插入删除操作，还可以在中间插入或删除元素。
接口不同：queue 提供了 push()、pop()、front()、back()、empty() 和 size() 等操作用于队列的基本操作；deque 则提供了更丰富的接口，除了队列的基本操作外，还可以像 vector 一样使用迭代器、随机访问和动态调整容器大小。
迭代器失效：在使用 deque 进行元素插入和删除操作时，除了在首尾进行的操作外，插入或删除元素可能引起迭代器失效；而 queue 只能从一端插入和删除元素，不会引起迭代器失效。
根据需求选择合适的容器，如果只需要实现队列的功能，可以使用 queue。如果需要在首尾两端进行插入和删除操作，以及随机访问元素，可以使用 deque。
*/


#include<iostream>
#include<queue>
using namespace std;

class Vertex {
public:
	int disk;
	Vertex(int _disk):disk(_disk){}
};


class CompareVertex {
public:
	bool operator()(const Vertex* v1, const Vertex* v2) const {
		return v1->disk < v2->disk;
	}
};



int main() {
	
	//1.优先队列
	
	//创建默认情况下(元素从大到小)的优先队列
	priority_queue<int> my;//定义优先队列
	my.push(12);
	my.push(3);
	my.push(67);
	while (!my.empty()) {
		cout << my.top() << " ";
		my.pop();
	}
	//输出67 12 3


	//创建(元素从小到大)的优先队列
	priority_queue<int,vector<int>,greater<int>> my;//定义优先队列,
	my.push(12);
	my.push(3);
	my.push(67);
	while (!my.empty()) {
		cout << my.top() << " ";
		my.pop();
	}
	//输出 3 12 67


	/*
	
	priority_queue：这是一个标准库中的优先队列容器模板类。
	<Vertex*, vector<Vertex*>, CompareVertex>：这是模板类 priority_queue 的模板参数。它指定了优先队列中元素的类型、底层容器的类型和比较器的类型。
	Vertex* ：这是优先队列中元素的类型。在这里，指针类型 Vertex* 被用作节点的类型，即指向 Vertex 类型的指针。
	vector<Vertex*>：这是优先队列的底层容器类型。我们选择了 vector 作为底层容器来存储元素。
	CompareVertex：这是比较器的类型。我们使用前面定义的 CompareVertex 结构体作为节点比较器。

	*/

	priority_queue<Vertex*, vector<Vertex*>, CompareVertex> pq;

	pq.push(new Vertex(5));
	pq.push(new Vertex(1));
	pq.push(new Vertex(10));
	pq.push(new Vertex(3));

	while (!pq.empty()) {
		cout << pq.top()->disk << " ";
		pq.pop();
	}
	//输出 1 3 5 10









//----------------------------------------------------------------
    //正常队列
	
	//push() : 向queue尾部添加一个元素。
	queue<int> q;
	q.push(10);
	q.push(20);


	//pop() : 移除queue头部的一个元素。
	queue<int> q;
	q.push(10);
	q.push(20);
	q.pop();


	//front() : 返回queue的第一个元素，但并不删除它。
	queue<int> q;
	q.push(10);
	q.push(20);
	int frontElement = q.front();


	//back() : 返回queue的最后一个元素，但并不删除它。在queue容器中，back()函数返回的元素就是最后入队的元素，而不是和std::deque一样的最后一个元素。
	queue<int> q;
	q.push(10);
	q.push(20);
	int backElement = q.back();


	//empty() : 检查queue是否为空，返回布尔值。
	queue<int> q;
	bool isEmpty = q.empty();


	//size() : 返回当前queue中的元素数量。
	queue<int> q;
	q.push(10);
	q.push(20);
	int size = q.size();

	system("pause");
	return 0;
}