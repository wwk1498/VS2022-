/*
����ѭ�����ţ�lomuto  �����з���������

����˼��:ÿ���ҵ�һ����׼��Ԫ�أ��ѱ���С�ķŵ�����ߣ�������ķŵ����ұߣ����ֳ�Ϊ����
  1.ѡ������Ԫ����Ϊ��׼��Ԫ��
  2.jָ�븺���ҵ��Ȼ�׼��С��Ԫ�أ�һ���ҵ�����i���н���
  3.iָ��ָ����ڻ�׼��Ԫ�ص���߽磬Ҳ��ÿ�ν�����Ŀ������
  4.����׼����i������i��Ϊ����λ��

����Ҫ�㣺
   1.ѡ�����Ҳ�Ԫ����Ϊ��׼��
   2.j�ұȻ�׼��С�ģ�i�ұȻ�׼���ģ�һ���ҵ������߽��н���
   3.����׼����i������i��Ϊ��׼����������
*/

#include<iostream>
#include<random>
using namespace std;


//���������
int random1(int a, int b) {

	// ���������������
	random_device rd;
	mt19937 gen(rd());

	// �������ȷֲ�����
	uniform_int_distribution<> dis(a, b);

	// ���������
	int randomNum = dis(gen);
	return randomNum;
}


//��������Ԫ��ֵ
void swap(int a1[],int a,int b) {
	int tep = a1[a];
	a1[a] = a1[b];
	a1[b] = tep;
}

//���������ػ�׼��Ԫ������
int partition(int a[], int left, int right) {

	//�������������Ϊ��׼��
	int index = random1(left, right);
	swap(a, right, index);//����right��index

	int pv = a[right];//��׼��Ԫ��ֵ��rightΪ��׼������
	int i = left;//�ұ�pv���Ԫ��ֵ
	int j = left;//�ұ�pvС��Ԫ��ֵ
	while (j<right) {
		if (a[j]<pv) {//j�ҵ��Ȼ�׼��Ԫ��С���ˣ�û�ҵ����
			if (i != j) {
				swap(a, i, j);
			}
			i++;
		}
		j++;
	}
	swap(a, i, right);
	return i;//��ʱiΪ��׼������
}


//����--left=0,right=size-1
void quicksort(int a[],int left,int right) {

	//��left==rightʱ��
	if (left >= right) {
		return;
	}
	//�ɵĻ�׼��Ԫ������Ϊright
	int p = partition(a,left,right);//p�����ص��µĻ�׼��Ԫ������
	quicksort(a, left, p - 1);
	quicksort(a, p + 1, right);
}


int main() {
	int s[8] = { 3,45,1,38,89,29,21,90 };
	quicksort(s, 0,7);
	for (int e : s) {
		cout << e << " ";
	}




	system("pause");
	return 0;
}