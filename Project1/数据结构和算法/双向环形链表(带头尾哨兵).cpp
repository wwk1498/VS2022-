#include<iostream>
using namespace std;

typedef struct node {
	struct node* left;//上一个节点指针
	int data;
	struct node* right;//下一个节点指针
}node;

typedef struct List {
	struct node* head;//头哨兵
	struct node* tail;//尾哨兵
}List;

//初始化双向环形链表
List* initlist() {

	List* list =(List*)malloc(sizeof(List));
	list->head= (node*)malloc(sizeof(node));
	list->tail= (node*)malloc(sizeof(node));

	list->head->left = list->tail;
	list->head->right= list->tail;

	list->tail->left = list->head;
	list->tail->right = list->head;
	return list;
}

int main() {


	system("pause");
	return 0;
}