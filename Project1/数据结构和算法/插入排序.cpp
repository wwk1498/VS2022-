/*
�����������Ϊ������[0...low-1]���ұ�Ϊδ����[low....length-1], ʱ�临�Ӷ�O(n)
ÿ��ȡ�ұ�����δ�����Ԫ�������������ҵ��������Ԫ�ضԱȣ������ڣ���λ�ò�������С�ڣ��򽻻�λ��
��ʼ����low=1,t=a[low],i=low-1;
*/

#include<iostream>
using namespace std;

//������������---ʱ�临�Ӷ�O(n2)
void charu1(int a[],int n) {//n�����鳤��
	int i, key, j;
	for (int i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j>=0&&key < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		if (j != i - 1) {
			a[j + 1] = key;
		}
	}
}

//�ݹ�ʵ�ֲ�������
void charu2(int a[],int low,int len) {//low=1��len=���鳤��
	if (low == len) {
		return;
	}
	int t = a[low];
	int i = low - 1;
	while (i>=0&&t<a[i]) {
		a[i + 1] = a[i];
		i--;
	}
	if (i != low - 1) {
		a[i + 1] = t;
	}
	charu2(a, low + 1,len);
}

int main(void) {
	int p[] = { 12,45,2,6,89,23};
	charu1(p,6);
	for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
		cout << p[i] << "  ";
	}

	system("pause");
	return 0;
}
