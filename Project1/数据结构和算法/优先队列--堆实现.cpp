#include<iostream>
using namespace std;
//优先级队列：一端进，另一端出（优先级高的先出）

//堆：基于树的数据结构，通常用完全二叉树实现，堆的特征：
//1.大堆顶中，任意节        点C与他的父节点	P符合 P.value>=C.value
//2.小堆顶中，任意节点C与他的父节点	P符合 P.value<=C.value
//3.最顶层节点没有父亲，称为root根节点

//若从0开始用一维数组存储节点数据：当i>0时，节点i的父节点索引为floor((i-1)/2),节点i的左子节点索引为2i+1,右子节点索引为2i+2，前提是他们都<size
//若从1开始用一维数组存储节点数据：当i>1时，节点i的父节点索引为floor(i/2),节点i的左子节点索引为2i,右子节点索引为2i+1，前提是他们都<size

/*
* 入堆新元素：加到数组末尾（索引位置child),不断比较新元素与它父亲（parent)的优先级：
*     1.如果父节点优先级低，则向下移动，找下一个父节点parent
*     2.直至父节点优先级更高或者child==0为止
*/

/*
* 元素出堆：交换堆顶和尾部的元素，让尾部元素出堆
* （下潜)
*    1.从堆顶元素开始，将父元素与两个孩子较大者交换
*    2.直到父元素大于两个孩子，或者没有孩子为止
* 
*/



//假设这次模拟是从0开始存储元素，并且是大堆顶 
typedef struct queue {
	int arr[11] ;
	int size;
}queue;

//初始化队列
void init(queue* p) {
	p->size = 0;
}

//判断队列是否空
bool pand1(queue* p) {
	if (p->size == 0) {
		return true;
	}
	return false;
}

//判断队列是否满
bool pand2(queue* p, int maxspace) {
	if (p->size == maxspace) {
		return true;
	}
	return false;
}

//判断两个左右子节点的最大值的索引
int pand3(queue* p,int a,int b) {
	if (a >= p->size|| b >= p->size||p->arr[a] >= p->arr[b]) {
		return a;
	}
	return b;
}

//向堆中插入元素,并调整数组中的元素位置以满足大堆顶的条件
void offer(queue* p,int val, int space) {
	if (pand2(p, space)) {
		return;
	}
	p->size++;
	int child = p->size - 1;
	int parent = (child - 1) / 2;
	while (val > p->arr[parent] && child> 0) {
		p->arr[child] = p->arr[parent];
		child = parent;
		parent = (child - 1) / 2;
	}
	p->arr[child] = val;
}

//获取优先级最高的元素出队，并调整数组中的元素位置以满足大堆顶的条件
int pull(queue* p) {
	if (pand1(p)) {
		return -1;
	}
	int tep = p->arr[0];
	int i = 0;
	int max = pand3(p, 2 * i + 1, 2 * i + 2);
	int key = p->arr[p->size - 1];
	while (key < p->arr[max] && max < p->size) {
		p->arr[i] = p->arr[max];
		i = max;
		max = pand3(p, 2 * i + 1, 2 * i + 2);
	}
	p->arr[i] = key;
	p->size--;
	return tep;
}

int main() {
	queue* w = (queue*)malloc(sizeof(queue));
	init(w);
	offer(w,100,11);
	offer(w, 80, 11);
	offer(w, 36, 11);
	offer(w, 53, 11);
	offer(w,28, 11);
	offer(w, 18, 11);
	offer(w, 3, 11);
	offer(w, 15, 11);
	offer(w, 24, 11);
	offer(w, 21, 11);
	offer(w, 8, 11);

	cout << pull(w) << " ";
	for (int i = 0; i < 10; i++) {
		cout << w->arr[i] << " "; 
	}

	system("pause");
	return 0;
}