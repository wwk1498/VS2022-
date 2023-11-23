#include<iostream>
using namespace std;
//���ȼ����У�һ�˽�����һ�˳������ȼ��ߵ��ȳ���

//�ѣ������������ݽṹ��ͨ������ȫ������ʵ�֣��ѵ�������
//1.��Ѷ��У������        ��C�����ĸ��ڵ�	P���� P.value>=C.value
//2.С�Ѷ��У�����ڵ�C�����ĸ��ڵ�	P���� P.value<=C.value
//3.���ڵ�û�и��ף���Ϊroot���ڵ�

//����0��ʼ��һά����洢�ڵ����ݣ���i>0ʱ���ڵ�i�ĸ��ڵ�����Ϊfloor((i-1)/2),�ڵ�i�����ӽڵ�����Ϊ2i+1,���ӽڵ�����Ϊ2i+2��ǰ�������Ƕ�<size
//����1��ʼ��һά����洢�ڵ����ݣ���i>1ʱ���ڵ�i�ĸ��ڵ�����Ϊfloor(i/2),�ڵ�i�����ӽڵ�����Ϊ2i,���ӽڵ�����Ϊ2i+1��ǰ�������Ƕ�<size

/*
* �����Ԫ�أ��ӵ�����ĩβ������λ��child),���ϱȽ���Ԫ���������ף�parent)�����ȼ���
*     1.������ڵ����ȼ��ͣ��������ƶ�������һ�����ڵ�parent
*     2.ֱ�����ڵ����ȼ����߻���child==0Ϊֹ
*/

/*
* Ԫ�س��ѣ������Ѷ���β����Ԫ�أ���β��Ԫ�س���
* ����Ǳ)
*    1.�ӶѶ�Ԫ�ؿ�ʼ������Ԫ�����������ӽϴ��߽���
*    2.ֱ����Ԫ�ش����������ӣ�����û�к���Ϊֹ
* 
*/



//�������ģ���Ǵ�0��ʼ�洢Ԫ�أ������Ǵ�Ѷ� 
typedef struct queue {
	int arr[11] ;
	int size;
}queue;

//��ʼ������
void init(queue* p) {
	p->size = 0;
}

//�ж϶����Ƿ��
bool pand1(queue* p) {
	if (p->size == 0) {
		return true;
	}
	return false;
}

//�ж϶����Ƿ���
bool pand2(queue* p, int maxspace) {
	if (p->size == maxspace) {
		return true;
	}
	return false;
}

//�ж����������ӽڵ�����ֵ������
int pand3(queue* p,int a,int b) {
	if (a >= p->size|| b >= p->size||p->arr[a] >= p->arr[b]) {
		return a;
	}
	return b;
}

//����в���Ԫ��,�����������е�Ԫ��λ���������Ѷ�������
void offer(queue* p,int val, int space) {
	if (pand2(p, space)) {
		return;
	}
	p->size++;
	int child = p->size - 1;
	int parent = (child - 1) / 2;
	while (val > p->arr[parent] && child> 0) {
		p->arr[child] = p->arr[parent];
		child = parent;
		parent = (child - 1) / 2;
	}
	p->arr[child] = val;
}

//��ȡ���ȼ���ߵ�Ԫ�س��ӣ������������е�Ԫ��λ���������Ѷ�������
int pull(queue* p) {
	if (pand1(p)) {
		return -1;
	}
	int tep = p->arr[0];
	int i = 0;
	int max = pand3(p, 2 * i + 1, 2 * i + 2);
	int key = p->arr[p->size - 1];
	while (key < p->arr[max] && max < p->size) {
		p->arr[i] = p->arr[max];
		i = max;
		max = pand3(p, 2 * i + 1, 2 * i + 2);
	}
	p->arr[i] = key;
	p->size--;
	return tep;
}

int main() {
	queue* w = (queue*)malloc(sizeof(queue));
	init(w);
	offer(w,100,11);
	offer(w, 80, 11);
	offer(w, 36, 11);
	offer(w, 53, 11);
	offer(w,28, 11);
	offer(w, 18, 11);
	offer(w, 3, 11);
	offer(w, 15, 11);
	offer(w, 24, 11);
	offer(w, 21, 11);
	offer(w, 8, 11);

	cout << pull(w) << " ";
	for (int i = 0; i < 10; i++) {
		cout << w->arr[i] << " "; 
	}

	system("pause");
	return 0;
}