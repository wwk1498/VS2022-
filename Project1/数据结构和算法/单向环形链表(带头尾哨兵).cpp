#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct List {
	struct node* head;//头哨兵
	struct node* tail;//尾哨兵
}List;

//初始化单向环形链表
List* initlist() {

	List *list=(List*)malloc(sizeof(List));
	list->head= (node*)malloc(sizeof(node));
	list->tail= (node*)malloc(sizeof(node));

	list->head->next = list -> tail;
	list->tail->next = list->head;

	return list;
}


int main(void) {
	
	system("pause");
	return 0;
}