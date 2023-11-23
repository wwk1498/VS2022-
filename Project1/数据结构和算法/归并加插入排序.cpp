/*
�ʺ��������ϴ�����ݽṹ����ʱʱ�临�ӶȽϵ�
*/
#include<iostream>
using namespace std;


//������������---ʱ�临�Ӷ�O(n2)  //left=0,right=size-1
void charu1(int a[],int left,int right) {//n�����鳤��
	int i, key, j;
	for (i = left+1; i <=right; i++) {
		key = a[i];
		j = i - 1;
		while (j >= left && key < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		if (j != i - 1) {
			a[j + 1] = key;
		}
	}
}


//�ϲ�������������---�ǵݹ�     a1--ԭ���飬a2--�����飬k--����������
//i--ԭ�����󲿷���ʼ������iend--ԭ�����󲿷����������j--ԭ�����Ҳ�����ʼ������jend--ԭ�����Ҳ����������

void merge(int a1[], int i, int iend, int j, int jend, int a2[], int k) {
	while (i <= iend && j <= jend) {
		if (a1[i] < a1[j]) {
			a2[k] = a1[i];
			i++;
		}
		else {
			a2[k] = a1[j];
			j++;
		}
		k++;
	}
	//iû����
	while (i <= iend) {
		a2[k] = a1[i];
		i++;
		k++;
	}
	//jû����
	while (j <= jend) {
		a2[k] = a1[j];
		j++;
		k++;
	}
}



//�鲢����--�ݹ飨���϶��£�---left=0,right=size-1,k=0
void split(int a1[], int left, int right, int a2[], int k) {

	//��
	if (right-left<=4) {
		charu1(a1, left, right);
		return;
	}

	//��
	int mid = (left + right) / 2;

	split(a1, left, mid, a2, k);
	split(a1, mid + 1, right, a2, k);

	//��
	merge(a1, left, mid, mid + 1, right, a2, k);
}


int main() {
	int s[10] = { 1,3,6,8,9,4,7,13,20,60 };
	int w[10];
	split(s, 0, 9,w, 0);
	for (int e : w) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}