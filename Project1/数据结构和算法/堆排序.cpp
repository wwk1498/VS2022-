
/*
������
    1.�����󶥶�
	2.ÿ�ν��Ѷ�Ԫ�أ����ֵ��������ĩβ�������ѽṹ�Է��ϴ󶥶�����

*/

#include<iostream>
using namespace std;



//���������ӽڵ����ֵ���±�
int retup(int p[], int a, int b,int size) {
    if (a >=size || b >= size|| p[a] >= p[b]) {
        return a;
    }
    return b;
}

//��������Ԫ��
void swap(int p[], int i, int j) {
    int tep = p[i];
    p[i] = p[j];
    p[j] = tep;
}

//��Ǳ
void down(int p[], int i,int size) {
    int max = retup(p, 2 * i + 1, 2 * i + 2,size);
    while (p[i] < p[max] && max <size) {
        swap(p, i, max);
        i = max;
        max = retup(p, 2 * i + 1, 2 * i + 2,size);
    }
}

//����
void initqueue(int p[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        down(p, i,size);
    }
}

//���������
void heapflf(int p[],int size) {
    
    initqueue(p, size);//����
    for (int right = size - 1; right > 0; right--) {
        swap(p, 0, right);
        down(p, 0,right);
    }
}




int main() {
    int d[8] = { 34,19,2,80,345,56,39,29 };
    heapflf(d, 8);

    for (int e : d) {
        cout << e << " ";
    }
	system("pause");
	return 0;
}