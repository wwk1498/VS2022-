#include<iostream>
#include<random>
using namespace std;

/*
�ʺϴ�������
*/


//������������---ʱ�临�Ӷ�O(n2)
void charu1(int a[], int left, int right) {//n�����鳤��
	int i, key, j;
	for (i = left + 1; i <= right; i++) {
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
void swap(int a1[], int a, int b) {
	int tep = a1[a];
	a1[a] = a1[b];
	a1[b] = tep;
}


//���������ػ�׼��Ԫ������
int partition(int a[], int left, int right) {

	//�������������Ϊ��׼��
	int index = random1(left, right);
	swap(a, left, index);//����left��index


	int pv = a[left];//��׼��Ԫ��ֵ��leftΪ��׼������
	int i = left + 1;//�Ҵ��ڵ���pv��Ԫ��ֵ
	int j = right;//��С�ڵ���pv��Ԫ��ֵ
	while (i <= j) {
		//j��������
		while (i <= j && a[j] > pv) {
			j--;
		}
		//i��������
		while (i <= j && a[i] < pv) {
			i++;
		}
		if (i <= j) {
			swap(a, i, j);
			i++;
			j--;
		}

	}
	swap(a, j, left);
	return j;//��ʱiΪ��׼������
}


//����--left=0,right=size-1
void quicksort(int a[], int left, int right) {

	//��left>=rightʱ��
	if (right-left<=5) {
		charu1(a,left,right);
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