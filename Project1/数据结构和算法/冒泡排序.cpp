#include<iostream>
using namespace std;
/*
* �ݹ�ð������

1.������ֳ�������  [0......j][j+1.....length-1]
2.�����δ���򲿷֣��ұ��������򲿷֣���δ���������ڣ���������Ԫ�رȽϣ����ǰһ�����ں�һ�����򽻻�λ��
* 
* 
*
* ð������: 
  �������Ϊ��ߣ�δ�������飬�ұߣ�����������
* �����鳤��len=n; ����Ҫѭ�� i=n-1 �Σ�ÿһ��ѭ����� δ�������� �ģ����ֵ����Сֵ���Ƶ� ����������
* ��ÿһ��ѭ����Ҫ��������Ԫ�ؽ��жԱ� j=n-1-i ��,Ȼ�󽻻�λ�ã�
*/

//����ð������-------ʱ�临�Ӷ�O(n^2)(������Ҫ�ã�
void fun(int a[],int end) {//end---�������һ��Ԫ�ص�����
	for (int i = 0; i < end ; i++) {
		for (int j = 0; j < end - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


//�ǵݹ�ð������---j=a.length-1
void bubble(int a[],int j) {

	while (true) {
		int x = 0;
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				x = i;
			}
		}
		j = x;
		if (j == 0) {
			break;
		}
	}
}




//һ��ݹ�ʵ��ð������---j=a.length-1
void digui(int a[], int j) {
	if (j == 0) {
		return;
	}
	for (int i = 0; i < j; i++) {
		if (a[i] > a[i + 1]) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
	digui(a,j-1);
}

//�Ľ��ĵݹ�ʵ��ð������(������Ѿ�����ʱ���������жϣ�����ѭ������)---j=a.length-1
void diguix(int a[], int j) {
	if (j == 0) {
		return;
	}
	int x = 0;
	for (int i = 0; i < j; i++) {
		if (a[i] > a[i + 1]) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
			x = i;
		}
	}
	diguix(a, x);
}



int main() {
	
	int arry[] = { 12,4,2,78,35,9 };

	digui(arry,5);

	for (int i = 0; i < 6; i++) {
		cout << arry[i] << "  ";
	}

	cout << endl;
	cout << "--------------------------" << endl;

	int appy[] = { 102,4,2,78,3,9 };

	diguix(appy, 5);

	for (int j = 0; j < 6; j++) {
		cout << appy[j] << "  ";
	}

	cout << endl;
	cout << "--------------------------" << endl;


	int cs[] = { 34,56,2,9,789,29 };
	bubble(cs,5);
	for (int e : cs) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}
