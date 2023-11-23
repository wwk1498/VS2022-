/*
* 
˫��ѭ��Ҫ��:
1.ѡ�������Ԫ����Ϊ��׼��
2.j�ұȻ�׼��С�ģ�i�ұȻ�׼���ģ�һ���ҵ������߽��н���
  i��������
  j��������
3.����׼����i������i��Ϊ��׼����������


ע��:
  1.�ڲ�ѭ����i<j
  2.�ȴ���j���ٴ���i
  3.���Ԫ����Ϊ��׼�㣨���������������������Ӱ�죩
  4.����д����ظ�Ԫ��

*/

#include<iostream>
#include<random>
using namespace std;


//���������
int random1(int a,int b) {
	
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
void swap(int a1[], int a, int b) {
	int tep = a1[a];
	a1[a] = a1[b];
	a1[b] = tep;
}


//���������ػ�׼��Ԫ������
int partition(int a[], int left, int right) {

	//�������������Ϊ��׼��
	int index = random1(left, right);
	swap(a,left,index);//����left��index


	int pv = a[left];//��׼��Ԫ��ֵ��leftΪ��׼������
	int i = left;//�ұ�pv���Ԫ��ֵ
	int j = right;//�ұ�pvС��Ԫ��ֵ
	while (i < j) {
		//j i ���ܸ�˳�򣬷������
		//j��������
		while (i<j && a[j]>=pv) {
			j--;
		}
		//i��������
		while (i < j && a[i] <= pv) {
			i++;
		}
		if (i < j) {
			swap(a, i, j);
		}
	}
	swap(a, i, left);
	return i;//��ʱiΪ��׼������
}


//����--left=0,right=size-1
void quicksort(int a[], int left, int right) {

	//��left==rightʱ��
	if (left >= right) {
		return;
	}
	//�ɵĻ�׼��Ԫ������Ϊright
	int p = partition(a, left, right);//p�����ص��µĻ�׼��Ԫ������
	quicksort(a, left, p - 1);
	quicksort(a, p + 1, right);
}


int main() {

	int s[8] = { 3,45,1,38,89,29,21,90 };
	quicksort(s, 0, 7);
	for (int e : s) {
		cout << e << " ";
	}


	system("pause");
	return 0;
}