/*
* 
ϣ������:
   1.����ʵ�ֲ��룬ÿ��Ԫ�ؼ�϶��Ϊgap
2.ÿ�������gap�𽥼�С��ֱ��gapΪ1�������
3.�Բ���������Ż�����Ԫ�ظ���Ľ���������λ��

*/

#include<iostream>
using namespace std;

//gapÿ�ζ�/2
void sort1(int a[],int size) {
	
	for (int gap = size / 2; gap >= 1;gap/=2) {
		int i, key, j;
		for (int i = gap; i < size; i++) {
			key = a[i];
			j = i - gap;
			while (j >= 0 && key < a[j]) {
				a[j + gap] = a[j];
				j -= gap;
			}

			if (j!= i - gap) {
				a[j + gap] = key;
			}
			
		}
	}
}




int main() {
	int s[5] = { 34,56,1,23,9 };
	sort1(s,5);
	for (int e : s) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}