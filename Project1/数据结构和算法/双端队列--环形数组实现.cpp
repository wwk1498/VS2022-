#include<iostream>
using namespace std;
//方法1：若数组空间为n,则只能存储n-1个元素；
//优化：若存储的是非数字元素，考虑取出元素后进行清空为null，释放内存
typedef struct queue {
	int  arry[10];
	int i;
	int j;
}queue;

//初始化队列
void initque(queue*p) {
	p->i = 0;
	p->j = 0;
}
//判断队列是否空
bool pand1(queue* p) {
	if (p->i == p->j) {
		return true;
	}
	return false;
}

//索引换算j
int pullj(int j, int maxspace) {
	if (j>= maxspace) {
		return 0;
	}
	return j + 1;
}

//索引换算i
int pulli(int i, int maxspace) {
	if (i <= 0) {
		return maxspace - 1;
	}
	return i - 1;
}

//判断队列是否满
bool pand(int i, int j,int maxspace) {
	if (i < j) {
		return j - i == maxspace - 1;
	}
	else if (j < i) {
		return i - j == 1;
	}
	else {
		return false;
	}
}
//在队列头部插入元素
void offerfirst(queue*p,int space,int val) {
	if (pand(p->i, p->j, space)) {
		cout << "满了" << endl;
		return;
	}
	p->i= pulli(p->i, space);
	p->arry[p->i] = val;
}
//在队列尾部插入元素
void offerlist(queue* p, int space, int val) {
	if (pand(p->i, p->j, space)) {
		cout << "满了" << endl;
		return;
	}
	p->arry[p->j] = val;
	p->j= pullj(p->j, space);
}
//在队列头部取出元素
int pollfirst(queue* p, int space) {
	if (pand1(p)) {
		cout << "空了" << endl;
		return -1;
	}
	int e = p->arry[p->i];
	p->i = pullj(p->i, space);
	return e;
}
//在队列尾部取出元素
int polllist(queue* p, int space) {
	if (pand1(p)) {
		cout << "空了" << endl;
		return -1;
	}
	p->j = pulli(p->j, space);
	return p->arry[p->j];
}
int main() {
	queue* w = (queue*)malloc(sizeof(queue));
	initque(w);
	for (int i = 0; i < 9; i++) {//注意循环个数要比实际容量少一才不会出错
		offerfirst(w, 9, i+1);
	}

	for (int j = 0; j < 9; j++) {
		int em = pollfirst(w, 9);//这里输出有些问题
		if (em != -1) {
			cout << em << " ";
		}
	}
	
	system("pause");
	return 0;
}