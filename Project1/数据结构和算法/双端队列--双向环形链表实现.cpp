#include<iostream>
using namespace std;
//双端队列：两边都可以删除 添加
typedef struct queue {
	int data;
	struct queue* i;
	struct queue* j;
}queue;
typedef struct List {
	struct queue* head;
	struct queue* tail;
}List;

//初始化双端队列
List* initque() {
	List* list = (List*)malloc(sizeof(List));
	list->head = (queue*)malloc(sizeof(queue));
	list->tail= (queue*)malloc(sizeof(queue));
	list->head->j = list->tail;
	list->head->i = list->tail;
	list->tail->j = list->head;
	list->tail->i = list->head;
	return list;
}
//判断队列为空
bool pand1(List* p) {
	if (p->head->j == p->tail) {
		return true;
	}
	return false;
}
//在队列头部插入元素
void pushh(List* p, int val) {
	queue* tep = (queue*)malloc(sizeof(queue));
	tep->data = val;
	tep->j = p->head->j;
	tep->j->i = tep;
	tep->i = p->head;
	tep->i->j = tep;
}
//在队列尾部插入元素
void pushw(List* p, int val) {
	queue* tep = (queue*)malloc(sizeof(queue));
	tep->data = val;
	tep->j = p->tail;
	tep->i = p->tail->i;
	tep->i->j = tep;
	tep->j->i = tep;
}
//在队列头部取出元素
int poph(List* p) {
	if (pand1(p)) {
		return -1;
	}
	queue* temp = p->head->j;
	p->head->j = temp->j;
	temp->j->i = p->head;
	int index = temp->data;
	free(temp);
	return index;
}

//在队列尾部取出元素
int popw(List* p) {
	if (pand1(p)) {
		return -1;
	}
	queue* temp = p->tail->i;
	p->tail->i = temp->i;
	temp->i->j = p->tail;
	int index = temp->data;
	free(temp);
	return index;
}





int main() {
	List* w = initque();
	for (int i = 0; i < 10; i++) {//队列头部插入元素
		pushh(w, i + 1);
	}
	for (int j = 0; j < 12; j++) {//在队列头部取出元素
		int y = poph(w);
		if (y != -1) {
			cout <<y << " ";
		}
	}
	cout << endl;
	cout << "-------------------------------------"<<endl;
	List* m = initque();
	for (int i = 0; i < 10; i++) {//队列尾部插入元素
		pushw(m, i + 1);
	}
	for (int j = 0; j < 12; j++) {//在队列尾部取出元素
		int x = popw(m);
		if (x != -1) {
			cout << x << " ";
		}
		
	}
	cout << endl;

	cout << "-------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {//队列尾部插入元素
		pushw(m, i + 1);
	}
	for (int j = 0; j < 12; j++) {//在队列头部取出元素
		int s = poph(m);
		if (s != -1) {
			cout << s << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}