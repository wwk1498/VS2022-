#include<iostream>
using namespace std;
//基于有序数组的优先级队列：一端进，另一端出（优先级高的先出）
typedef struct queue {
	int arr[7];
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

//在队列尾部插入元素，并使用插入排序进行排序
void  offer(queue* p, int val,int space) {
	if (pand2(p,space)) {
		return;
	}
	p->size++;
	p->arr[p->size - 1] = val;
	int i, key, j;
	for (int i = 1; i < p->size; i++) {
		key = p->arr[i];
		j = i - 1;
		while (j >= 0 && key < p->arr[j]) {
			p->arr[j + 1] = p->arr[j];
			j--;
		}
		p->arr[j + 1] = key;
	}
}

//出队
int peek(queue* p) {
	if (pand1(p)) {
		return -1;
	}

	int e= p->arr[p->size - 1];
	p->size--;
	return e;
}

int main() {
	queue* w = (queue*)malloc(sizeof(queue));
	init(w);

	offer(w, 2,7);
	offer(w, 5,7);
	offer(w, 8,7);
	offer(w, 9,7);
	offer(w, 15,7);
	offer(w, 25,7);
	offer(w, 23, 7);

	for (int j = 0; j < 7; j++) {
		cout << peek(w) << " ";
	}
	system("pause");
	return 0;
}