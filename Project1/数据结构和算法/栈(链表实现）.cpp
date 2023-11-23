#include<iostream>
using namespace std;
//栈：只能在其一端添加和移除数据，不能操作的一端为栈底，另一端为栈顶；
//只能在一端删除和添加（栈顶）
typedef struct node {
	int data;
	struct node* next;
}node;
typedef struct List {
	struct node* head;
	struct node* tail;
}List;

//初始化栈
List* initlist() {
	List* list = (List*)malloc(sizeof(List));
	list->head = (node*)malloc(sizeof(node));
	list->tail = (node*)malloc(sizeof(node));
	list->head->next = list->tail;
	list->tail->next = list->head;
	return list;
}
//判断栈空
bool pand1(List*p) {
	if (p->head->next == p->tail) {
		return true;
	}
	return false;
}
//入栈
void push(List*p,int i) {
	node* tep = (node*)malloc(sizeof(node));
	tep->data = i;
	tep->next = p->head->next;
	p->head->next = tep;
}
//出栈
int pop(List*p) {
	if (pand1(p)) {
		cout << "栈空了！" << endl;
		return -1;
	}
	node* temp = p->head->next;
	int index = temp->data;
	p->head->next = temp->next;
	free(temp);
	return index;
}

int main() {
	List* f = (List*)malloc(sizeof(List));
	f = initlist();
	for (int i = 0; i < 10; i++) {
		push(f, i + 1);
	}
	for (int j = 0; j < 15; j++) {
		cout << pop(f) << " ";
	}
	system("pause");
	return 0;
}