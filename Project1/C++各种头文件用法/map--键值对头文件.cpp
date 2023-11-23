/*
map是C++标准库中的一个关联容器，它以键-值对(key-value pairs)的形式存储数据。在map中，每个键都是唯一的，且键和值是一一对应的。
map可以根据键的值进行快速的查找、插入和删除操作。它内部使用红黑树(Red-Black Tree)作为数据结构，保证了元素的有序性，并且各种操作的平均时间复杂度为O(logN)，其中N是map中的元素数量。
使用map可以实现高效的键值查找和排序功能。它常用于需要快速查找、插入和删除键值对的场景，比如字典、索引等。

以下是map的特点：

键唯一：每个键在map中只能存在一次。
自动排序：map会根据键的值自动进行排序，保持元素的有序性。
红黑树实现：map内部使用红黑树数据结构来存储元素，保证了高效的查找和插入操作。
动态大小：map可以动态调整存储空间大小，根据需要自动分配和释放内存。

*/

#include<iostream>
#include<map>
using namespace std;


int main() {
	

	//插入元素：map::insert()  
	map<int, string> myMap;
	myMap.insert(make_pair(1, "v")); // 插入一对键值对, make_pair(1, "v")--> 创建并返回一个包含 1和"v" 的 pair对象（临时对象）



	//访问元素：map::operator[]
	map<int, string> myMap;
	
	myMap[1] = "e"; // 通过键访问或赋值元素


	//删除元素：map::erase()
	map<int, string> myMap;
	myMap.erase(2); // 删除指定键的元素


	//查找元素：map::find()
	map<int, string> myMap;
	auto it = myMap.find(3); // 查找指定键的元素，it是map的迭代器
	if (it != myMap.end()) {
		// 元素存在
	}
	else {
		// 元素不存在
	}



	//获取元素个数：map::size()
	map<int, string> myMap;
	cout << "元素个数：" << myMap.size() <<endl;



	//清空map：map::clear()
	map<int, string> myMap;
	myMap.clear(); // 清空所有元素



	//遍历map：使用迭代器
	map<int, string> myMap;
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		// 遍历所有元素
		int key = it->first;//返回it对应的键
		string value = it->second;//返回it对应的值
	}

	system("pause");
	return 0;
}