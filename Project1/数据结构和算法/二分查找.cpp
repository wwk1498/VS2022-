#include<iostream>
using namespace std;
//����1
int fun(int arry[], int targe, int size) {
	int i = 0, j =size-1;
	while (i <= j) {
		//int m = (i + j) >> 1   ---->  ����������գ���i����j�ϴ�ʱ��m�����
		int m = i + ((j - i) >> 1);//int m =i+ ((j-i) >> 1)  ---->  ���Ա�֤mһ������i��С��j
		if (targe < arry[m]) {
			j = m - 1;
		}
		else if (arry[m] < targe) {
			i = m + 1;
		}
		else {
			return m;
		}
	}
	return -1;
}
//����2
int func(int arry[], int targe, int size) {
	int i = 0, j = size;
	while (i < j) {
		int m = i + ((j - i) >> 1);
		if (targe < arry[m]) {
			j = m;
		}
		else if (arry[m] < targe) {
			i = m + 1;
		}
		else {
			return m;
		}
	}
	return -1;
}
//����3-->ƽ���
 int binarySearchBalance(int a[], int target, int size) {
	int i = 0, j = size;
	while (1 < j - i) {         // ��Χ�ڴ����ҵ�Ԫ�ظ��� > 1 ʱ
		int m = i + ((j - i) >> 1);
		if (target < a[m]) {    // Ŀ�������
			j = m;
		}
		else {                // Ŀ���� m ���ұ�
			i = m;
		}
	}
	return (target == a[i]) ? i : -1;
}

 //����4  --->leftmost----->Ѱ��Ŀ��ֵ���������
 int funu(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 int candidate = -1;//��ѡ��
	 while (i <= j) {
		 int m = i + ((j - i) >> 1);
		 if (targe < arry[m]) {
			 j = m - 1;
		 }
		 else if (arry[m] < targe) {
			 i = m + 1;
		 }
		 else { 
			 candidate = m;//��ѡ�߱��
			 j = m - 1;
		 }
	 }
	 return candidate;
 }
 //����5  --->rightmost----->Ѱ��Ŀ��ֵ���ҵ�����
 int funp(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 int candidate = -1;//��ѡ��
	 while (i <= j) {
		 int m = i + ((j - i) >> 1);
		 if (targe < arry[m]) {
			 j = m - 1;
		 }
		 else if (arry[m] < targe) {
			 i = m + 1;
		 }
		 else {
			 candidate = m;//��ѡ�߱��
			 i = m + 1;
		 }
	 }
	 return candidate;
 }

 //����6  --->leftmost  ---->����  ���ڵ���targe ���������
 int funk(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 while (i <= j) {
		 int  m = i + ((j - i) >> 1);
		 if (targe <= arry[m]) {
			 j = m - 1;
		 }else{
			 i = m + 1;
		 }
	 }
	 return i;
 }
 //����7  --->rightmost  ---->����  С�ڵ���targe ���������
 int funj(int arry[], int targe, int size) {
	 int i = 0, j = size - 1;
	 while (i <= j) {
		 int  m = i + ((j - i) >> 1);
		 if (targe < arry[m]) {
			 j = m - 1;
		 }
		 else {
			 i = m + 1;
		 }
	 }
	 return i-1;
 }

int main(void) {
	int arry[12] = { 1,2,3,4,5,5,7,8,8,8,9,10 };
	int size= sizeof(arry) / sizeof(arry[0]);
	int target = -3;
	//cout << size << endl;
	//int maxValue = std::numeric_limits<int>::max();
	//cout << fun(arry, target, size) << endl;
	//cout << func(arry, target, size) << endl;
	cout << funp(arry, target, size) << endl;
	system("pause");
	return 0;
}