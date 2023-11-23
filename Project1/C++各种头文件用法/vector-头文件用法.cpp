#include<iostream>
#include<vector>
using namespace std;



int main() {

	/*
	* vector<pair<double, double>> k_r(n) 是一个创建了一个大小为 n 的 pair<double, double> 类型的向量 k_r。
	  pair<double, double> 是一个用于存储两个值的容器，其中第一个值的类型是 double，第二个值的类型也是 double。
	  在这种情况下，k_r 是一个存储了 n 对 (double, double) 值的向量
	*/
	//创建一个存储一对元素的对象，其大小为10
	vector<pair<double, double>> k_r;
	//添加数据
	k_r.push_back(make_pair(1.4,2.7));//或者：k_r.push_back({2.6,5.9});
	k_r.push_back({ 2.6,5.9 });


	//初始化数组vector元素为0
	vector<int> vec(5,0);//大小为5，每个元素都为0

	//初始化二维数组vector元素为0
	vector<vector<int>> vec(5, vector < int>(4,0));//大小为5，每个元素大小为5，元素的元素的大小都为4，且值为0

	//push_back(): 向vector尾部添加一个元素
	vector<int> vec;
	vec.push_back(10); // {10}
	vec.push_back(20); // {10, 20}

	//pop_back(): 移除vector尾部的一个元素。
	vector<int> vec = { 10, 20, 30 };
	vec.pop_back(); // {10, 20}

	//size(): 返回当前vector中的元素数量。
	vector<int> vec = { 10, 20, 30 };
	int size = vec.size(); // 3

	//empty(): 检查vector是否为空，返回布尔值。
	vector<int> vec = { 10, 20, 30 };
	bool isEmpty = vec.empty(); // false

	//clear(): 清空vector中的所有元素。
	vector<int> vec = { 10, 20, 30 };
	vec.clear(); // {}

	//resize(): 调整vector的大小，可以增加或减少元素数量。
	vector<int> vec = { 10, 20, 30 };
	vec.resize(5); // {10, 20, 30, 0, 0}
	vec.resize(2); // {10, 20}

	//at(): 访问指定位置的元素，带有边界检查。
	vector<int> vec = { 10, 20, 30 };
	int element = vec.at(1); // 20

	//front(): 返回vector的第一个元素。
	vector<int> vec = { 10, 20, 30 };
	int firstElement = vec.front(); // 10

	//back(): 返回vector的最后一个元素。
	vector<int> vec = { 10, 20, 30 };
	int lastElement = vec.back(); // 30

	//erase() : 移除指定位置或指定范围的元素。
	vector<int> vec = { 10, 20, 30, 40, 50 };
	vec.erase(vec.begin() + 2); // {10, 20, 40, 50}
	vec.erase(vec.begin() + 1, vec.begin() + 3); // {10, 50}

	//insert(): 在指定位置插入一个或多个元素。
	vector<int> vec = { 10, 20, 30 };
	vec.insert(vec.begin() + 1, 15); // {10, 15, 20, 30}
	vec.insert(vec.begin() + 2, 2, 25); // {10, 15, 25, 25, 20, 30}

	//查找指定的元素的迭代器并返回
	vector<int> vec = { 10, 20, 30 };
	auto it = find(vec.begin(),vec.end(),20);
	if (it!=vec.end()) {
		vec.erase(it);//移除第一个元素后，第二个元素会向前移动填补第一个元素的位置，并设置索引为0
	}

	system("pause");
	return 0;
}