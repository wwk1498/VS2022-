/*

ѡ������ÿһ��ѡ����������С����Ԫ�أ����������������ʵ�λ��
         ѡ��������length-1
		 ����������λ�ã���ʼ��length-1,ÿ�εݼ�
*/

#include<iostream>
using namespace std;

//�ǵݹ�---->j=length-1
void xaunze(int a[], int j) {

	for (int right = j; right > 0; right--) {
		int max = right;
		for (int i = 0; i < right; i++) {
			if (a[i] > a[max]) {
				max =i;
			}
		}

		//�ҵ����ֵ����������Ԫ��������right��Ӧ��Ԫ�ؽ���
		if (max != right) {//�����ֵ�������䣬����Ҫ����
			int tep = a[max];
			a[max] = a[right];
			a[right] = tep;
		}
		
	}
}


int main() {

	int arr[] = { 4,56,1,234,9,89,41,8,398 };
	xaunze(arr,8);
	for (int e : arr) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}