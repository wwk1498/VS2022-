#include<iostream>
using namespace std;

//�ݹ�ʵ���������  ʱ�临�Ӷȣ�O(2^n)
int element(int i,int j) {//������ǵ������ֵ�ֵ
	if (j == 0 || i == j) {
		return 1;
	}
	return element(i - 1, j - 1) + element(i - 1, j);
}

void test1() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {//  i--->���� 0,1,2,3......   j--->���� 0,1,2,3......
		for (int k = 0; k < (n - 1 - i) * 2; k++) {//  n--->�иߣ�
			cout << " "; //��ӡ�ո���
		}
		for (int j = 0; j <= i; j++) {
			cout << element(i, j)<<"   ";
		}
		cout << endl;
	}
}

//�Ż��ݹ�ʵ���������   ʱ�临�Ӷ�ΪO(n^2)
int element1(int s[100][100], int i, int j) {//������ǵ������ֵ�ֵ
	if (s[i][j] > 0) {
		return s[i][j];
	}
	if (j == 0 || i == j) {
		s[i][j] = 1;
		return 1;
	}
	s[i][j]= element1(s, i - 1, j - 1) + element1(s, i - 1, j);
	return s[i][j];
}

void test2() {
	int n;
	cin >> n;
	int arr[100][100];
	for (int i = 0; i < n; i++) {//  i--->���� 0,1,2,3......   j--->���� 0,1,2,3......
		for (int k = 0; k < (n - 1 - i) * 2; k++) {//  n--->�иߣ�
			cout << " "; //��ӡ�ո���
		}
		arr[i][0] = 1;
		for (int j = 0; j <= i; j++) {
			cout << element1(arr,i, j) << "   ";
		}
		cout << endl;
	}
}

//�Ż��ݹ�ʵ��������� ʹ��һλ���鸲��
void createrow(int n,int s[]) {
	if (n == 0) {
		s[0] = 1;
		return;
	}

	for (int j = n; j > 0; j--) {
		s[j] = s[j] + s[j - 1];
	}
}


void test3() {
	int n;
	int p[10] = {0};
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < (n - 1 - i) * 2; k++) {//  n--->�иߣ�
			cout << " "; //��ӡ�ո���
		}
		createrow(i, p);
		for (int j = 0; j <= i; j++) {
			cout << p[j] << "   ";
		}
		cout << endl;
	}
}


int main(void) {
	test3();
	system("pause");
	return 0;
}