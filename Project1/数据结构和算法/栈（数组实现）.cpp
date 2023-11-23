#include<iostream>
using namespace std;
typedef struct node {
	int s[10];
	int i;
}node;
//≥ı ºªØ ˝◊È
void initnod(node*p) {
	p->i = 0;
}
//≈–∂œ’ªø’
bool pand(node*p) {
	if (p->i == 0) {
		return true;
	}
	return false;
}
//≈–∂œ’ª¬˙
bool panduan(node*p) {
	if (p->i == 10) {
		return true;
	}
	return false;
}
//»Î’ª
void  push(node* p, int val) {
	if (panduan(p)) {
		cout << "’ª¬˙" << endl;
		return;
	}
	p->s[p->i++] = val;
}

//≥ˆ’ª
int pop(node* p) {
	if (pand(p)) {
		cout << "’ªø’" << endl;
		return -1;
	}
	int index = p->s[p->i - 1];
	p->i--;
	return index;
}



int main() {
	node* a = (node*)malloc(sizeof(node));
	initnod(a);
	for (int i = 0; i < 13; i++) {
		push(a, i + 1);
	}
	for (int j = 0; j < 15; j++) {
		cout << pop(a) << " ";
	}
	system("pause");
	return 0;
}