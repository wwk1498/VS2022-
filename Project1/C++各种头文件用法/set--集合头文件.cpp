/*
"Set"是一种数据结构，表示一组互不相同的元素的集合。它遵循集合的数学概念，即集合中的每个元素是唯一的，没有重复。

Set通常提供以下特性：

唯一性：Set中的元素是唯一的，不存在重复元素。
无序性：Set并没有特定的顺序，元素的存储顺序不重要。
快速查找：Set支持快速的查找操作，可以快速判断一个元素是否存在于Set中。
插入和删除：Set支持高效的插入和删除操作。

在编程语言中，Set是一种常见的数据结构类型，并且通常提供了对集合的常见操作，例如将元素插入到Set中、从Set中删除元素、查找元素、判断Set是否为空等。在C++中，std::set是C++标准库中实现的一种Set容器。
Set的使用场景广泛，例如可以用于去重、检查元素是否存在、计算交集和并集等操作。
*/

#include<iostream>
#include<set>
using namespace std;

int main() {

	//insert() : 用于将元素插入set中。
	set<int> mySet;
	mySet.insert(10); //插入元素10


	//erase() : 用于删除元素。
	set<int> mySet;
	mySet.erase(10); //删除元素10


	//clear() : 用于清空set中的所有元素。
	set<int> mySet;
	mySet.clear(); //清空set


	//find() : 用于查找元素，返回指向找到元素的迭代器，如果没找到则返回end()。
	set<int> mySet;
	set<int>::iterator it = mySet.find(10); //查找元素10
	if (it != mySet.end()) {
		//找到了元素
	}
	else {
		//未找到元素
	}


	//count() : 用于统计set中特定元素的个数（不是 0 就是 1 ）--->主要用于判断元素是否存在于set中
	set<int> mySet;
	int count = mySet.count(10); //统计元素10的个数



	//size() : 用于返回set中元素的个数。
	set<int> mySet;
	int size = mySet.size(); //获取set中元素的个数



	//empty() : 用于判断set是否为空，为空返回true，否则返回false。
	set<int> mySet;
	bool isEmpty = mySet.empty(); //判断set是否为空


	//begin() 和 end() : 用于获取指向set开头和结尾的迭代器。
	set<int> mySet;
	set<int>::iterator it = mySet.begin(); //获取迭代器指向set开头
	set<int>::iterator end = mySet.end(); //获取迭代器指向set结尾


	//lower_bound() 和 upper_bound() : 用于返回指向大于等于 / 大于某个值的第一个元素的迭代器，如果没有这样的元素，则返回end()。
	set<int> mySet;
	set<int>::iterator it = mySet.lower_bound(10); //返回大于等于10的第一个元素的迭代器
	set<int>::iterator it = mySet.upper_bound(10); //返回大于10的第一个元素的迭代器



	//equal_range() : 用于返回指向某个值的元素范围的迭代器对(equal_range)。
	set<int> mySet;
	pair<set<int>::iterator, set<int>::iterator> range = mySet.equal_range(10); //返回指向值为10的元素范围的迭代器对
	set<int>::iterator lower = range.first; //返回指向范围的第一个元素的迭代器
	set<int>::iterator upper = range.second; //返回指向范围的最后一个元素的下一个位置的迭代器
	













	system("pause");
	return 0;
}