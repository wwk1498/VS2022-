#include<iostream>
using namespace std;
typedef struct node {
	int arry[10];
	int i;
	int j;
}node;
//队列特点：一端删除（头），另一端添加（尾）
//
//求模运算：(条件：除数是2的n次方）判断某数m是2的n次方：若m&(m-1)=0;则m是2的n次方
//i%j=k;
// 如果j是2的n次方
//则i的后n位即为余数(模）
//求i的后n位的方法：与2^n-1按位与
//若：N/m=p.......q;同时m是2的n次方，则商：p=N>>n,   余数：q=N&(2^n-1)
//好处：性能更高，不用考虑符号位的影响



//初始化队列
void initnode(node*p) {
	p->i = 0;
	p->j = 0;
}
bool pandauanque(node* p) {//判断队列是否为空
	if (p->i == 10) {
		return true;
	}
	return false;
}
bool pandauanquem(node* p) {//判断队列是否已满
	if (p->j==10) {
		return true;
	}
	return false;
}
void enqueue(node* p, int index) {// 入队
	if (pandauanquem(p)) {
		cout << "队列满了！" << endl;
		return;
	}
	p->arry[p->j % 10] = index;
	p->j++;
}
int dequeue(node* p) {// 出队
	if (pandauanque(p)) {
		cout << "队列空了！" << endl;
		return -1;
	}
	int i = p->arry[p->i%10];
	p->i++;
	return i;
}


int main() {
	/*node* w = (node*)malloc(sizeof(node));
	initnode(w);
	for (int i = 0; i < 20; i++) {
		enqueue(w, i + 1);
	}
	for (int j = 0; j < 20; j++) {
		cout << dequeue(w) << " ";
	}*/
	int num = 7;
	num = num >> 1;//商
	int p = num & 1;//余数
	cout << p<< endl;
	system("pause");
	return 0;
}