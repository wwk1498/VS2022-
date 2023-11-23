//�ѣ������������ݽṹ��ͨ������ȫ������ʵ�֣��ѵ�������
//1.��Ѷ��У�����ڵ�C�����ĸ��ڵ�P���� P.value>=C.value
//2.С�Ѷ��У�����ڵ�C�����ĸ��ڵ�P���� P.value<=C.value
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

/*
Floyd�����㷨������ʱ�临�Ӷȣ�O(n);

ʹ�ù���
    1.�ҵ����һ����Ҷ�ӽڵ�
    2.�Ӻ���ǰ����ÿ���ڵ�ִ����Ǳ

   1.������0��ʼ�洢���ݣ������һ����Ҷ�ӽڵ� i=(size/2)-1

*/
#include<iostream>
using namespace std;

//�������ģ���Ǵ�0��ʼ�洢Ԫ�أ������Ǵ�Ѷ� 
//�����ǣ�����ͨ����ת��Ϊ�󶥶�
typedef struct queue {
    int arr[10];
    int size;
}queue;


//��ʼ����
void init(queue* p) {
    p->size = 0;
}

//�ж϶��Ƿ��
bool pand1(queue* p) {
    if (p->size == 0) {
        return true;
    }
    return false;
}

//�ж϶��Ƿ���
bool pand2(queue* p, int maxspace) {
    if (p->size == maxspace) {
        return true;
    }
    return false;
}


//���������ӽڵ����ֵ���±�
int retup(queue* p,int a,int b) {
    if (a>=p->size||b>=p->size||p->arr[a] >= p->arr[b]) {
        return a;
    }
    return b;
}

//��������Ԫ��
void swap(queue* p,int i,int j) {
    int tep = p->arr[i];
    p->arr[i] = p->arr[j];
    p->arr[j] = tep;
}

//��Ǳ
void down(queue* p,int i) {
    int max = retup(p, 2 * i + 1, 2 * i + 2);
    while (p->arr[i] < p->arr[max]&&max<p->size) {
        swap(p, i, max);
        i = max;
        max = retup(p, 2 * i + 1, 2 * i + 2);
    }
}

//����
void initqueue(queue*p,int space) {
    for (int i = space / 2 - 1; i >= 0; i--) {
        down(p, i);
    }
}

//��ȡ�Ѷ�Ԫ��
int peek(queue* p) {
    if (pand1(p)) {
        return -1;
    }
    return p->arr[0];
}

//ɾ���Ѷ�Ԫ��
void  pull(queue* p) {
    if (pand1(p)) {
        return;
    }
    swap(p, 0, p->size-1);
    p->size--;
    down( p, 0);
}

//ɾ��ָ����������Ԫ��
void poll(queue* p,int index) {
    if (index < 0 || index >= p->size) {
        return;
    }
    swap(p, index, p->size - 1);
    p->size--;
    down(p, index);
}

//�滻�Ѷ�Ԫ��
void puld(queue* p, int val) {
    p->arr[0] = val;
    down(p,0);
}
//Ԫ��val�ϸ���ֱ��valС�ڸ�Ԫ�ػ��ߵ��Ѷ�
void up(queue* p,int val) {
    int child = p->size;
    int parent = (child - 1) / 2;
    while (p->arr[child]>p->arr[parent]&&child>0) {
        p->arr[child] = p->arr[parent];
        child = parent;
        parent = (child - 1) / 2;
    }
    p->arr[child] = val;
}

//��β�����Ԫ��
void add(queue* p,int val,int space) {
    if (pand2(p, space)) {
        return;
    }
    up(p,val);
    p->size++;
}



int main() {
    queue* w = (queue*)malloc(sizeof(queue));
    init(w);
    for (int i = 0; i < 7; i++) {
        w->arr[i] = i+1;
        w->size++;
    }

    initqueue(w, 7);

    for (int j = 0; j < 7; j++) {
        cout << w->arr[j] << " ";
    }
    system("pause");
    return 0;
}