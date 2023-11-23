#include<iostream>
using namespace std;
typedef struct node {
	int arry[10];
	int front;
	int rear;
	int size;//元素个数
}node;

// 初始化队列
void initque(node* p) {
	p->front = 0;
	p->rear = 0;
	p->size = 0;
}
bool pandauanque(node* p) {//判断队列是否为空
	if (p->size==0) {
		return true;
	}
	return false;
}

bool pandauanquem(node* p,int max) {//判断队列是否已满
	if (p->size==max) {
		return true;
	}
	return false;
}

void enqueue(node* p, int index,int max) {// 入队
	if (pandauanquem(p,max)) {
		cout << "队列满了！" << endl;
		return;
	}
	p->arry[p->rear] = index;
	p->rear = (p->rear + 1) % 10;
	p->size++;
}

int dequeue(node* p) {// 出队
	if (pandauanque(p)) {
		cout << "队列空了！" << endl;
		return -1;
	}
	int i = p->arry[p->front];
	p->front = (p->front + 1) % 10;
	p->size--;
	return i;
}

// 清空队列
void clearQueue(node* p) {
	p->front = 0;
	p->rear = 0;
	p->size = 0;
}


int main() {
	node* w = (node*)malloc(sizeof(node));
	initque(w);
	for (int i = 0; i < 15; i++) {
		enqueue(w, i + 1,10);
	}
	for (int j = 0; j <15; j++) {
		int m = dequeue(w);
		if (m != -1) {
			cout << m<< " ";
		}
	}
	system("pause");
	return 0;
}