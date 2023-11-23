
/*
堆（Heap）是一种特殊的数据结构，它是一个完全二叉树（或者是近似完全二叉树），并且满足堆属性（Heap Property）。堆被广泛应用于优先队列、排序算法等领域。

堆有两种主要类型：最大堆（Max Heap）和最小堆（Min Heap）。最大堆的堆属性是：对于任何节点i，其父节点的值都大于或等于节点i的值。最小堆则相反，对于任何节点i，其父节点的值都小于或等于节点i的值。

堆具有以下特点：

由于堆是一棵完全二叉树，所以可以使用数组来表示堆。如果节点的下标为i，则其左孩子的下标为2i，右孩子的下标为2i+1，父节点的下标为i/2。（这里假设数组下标从1开始，如果从0开始，可以稍作调整）。
在最大堆中，根节点的元素是整个堆中最大的元素；在最小堆中，根节点的元素是整个堆中最小的元素。
堆可以使用一些操作来维护其性质，如插入一个元素到堆中、删除堆中的根节点等。
堆的应用领域包括：

优先队列：使用最大堆或最小堆来实现高效的元素优先级管理；
堆排序（Heap Sort）：利用堆的性质进行排序操作；
任务调度：根据任务优先级使用最小堆来进行任务调度等。
总之，堆是一种具有特定性质的完全二叉树，可以通过数组或其他数据结构来表示，并用于解决一些与优先级相关的问题。
*/

#include<iostream>
#include <algorithm>
#include <vector>

//需要同时使用<algorithm>和容器来实现堆

using namespace std;

int main() {

	//创建堆
	vector<int> vec = { 4, 2, 7, 1, 5 };

	//less<int>()--->创建大顶堆，greater<int>()---->创建小顶堆
	make_heap(vec.begin(), vec.end(),less<int>());// 现在 vec 是一个堆，它的元素按照堆的性质排列
	
	make_heap(vec.begin(), vec.end());


	//push_heap() : 将元素添加到堆中
	vector<int> vec = { 4, 2, 7, 1, 5 };
	vec.push_back(3);
	push_heap(vec.begin(), vec.end());
	// 现在 vec 中的元素 3 已被添加到堆中，并保持堆的性质



	//pop_heap() : 弹出堆顶元素
	vector<int> vec = { 4, 2, 7, 1, 5 };
	pop_heap(vec.begin(), vec.end());
	vec.pop_back();
	int s = vec.front();//获取堆顶元素
	// 现在 vec 中的元素按照堆的性质排列，且堆顶元素已被弹出


	//sort_heap() : 将堆中的元素排序
	vector<int> vec = { 4, 2, 7, 1, 5 };
	sort_heap(vec.begin(), vec.end());//升序排序

	// 现在 vec 中的元素已被排序，不再是一个堆







	system("pause");
	return 0;
}