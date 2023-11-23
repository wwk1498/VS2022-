#include<iostream>
using namespace std;
//队列 :先进先出
typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct List {
	struct node* head;//头哨兵
	struct node* tail;//尾哨兵
	int size;//结点个数
	int capacity;//容量
}List;

List* initlist() {//创建带头尾哨兵的队列
	List* list = (List*)malloc(sizeof(List));
	list->head = (node*)malloc(sizeof(node));
	list->tail = (node*)malloc(sizeof(node));
	list->size = 0;
	list->capacity = 5;
	list->head->next = list->tail;
	list->tail->next = list->head;
	return list;
}


bool  pandaun(List* p) {//判断队列是否为空
	if (p->head->next == p->tail) {
		return true;
	}
	else {
		return false;
	}
}

bool panduanlit(List* p) {//判断队列是否满
	if (p->size == p->capacity) {
		return true;
	}
	else {
		return false;
	}
}

List* addlist(List* p, int i) {//向队列添加元素
	if (panduanlit(p)) {
		cout << "队列满了！" << endl;
		return p;
	}
	node* tep = (node*)malloc(sizeof(node));
	tep->data = i;
	tep->next = p->head->next;
	p->head->next = tep;
	p->size++;
	return  p;
}

int printlist(List* p) {//获取队列元素值,并在队列中删除该值
	if (pandaun(p)) {
		return NULL;
	}
	node* left = p->head;
	node* tep= p->head->next;
	while (tep->next != p->tail) {
		left = tep;
		tep = tep->next;
	}
	int index = tep->data;
	left->next = p->tail;
	free(tep);
	tep = NULL;
	return index;
}
void prinlit(List* p) {//循环输出队列中的值

	while(p->head->next != p->tail) {
		cout << printlist(p) << " ";
	}
}


int main() {
	List* Q = initlist();
	Q = addlist(Q, 8);
	Q = addlist(Q, 5);
	Q = addlist(Q, 9);
	Q = addlist(Q, 2);
	Q = addlist(Q, 8);
	Q = addlist(Q, 67);
	prinlit(Q);


	system("pause");
	return 0;
}