/*
ʱ�临�Ӷ� �� 2*n+k
Ҫ�㣺
   1.��ԭʼ����ӳ�䵽 count[0] ,���ֵӳ�䵽 count ���Ҳ�
   2.�������СΪ �����ֵ-��Сֵ��+1
   3.count���� = ԭʼ����Ԫ��-��Сֵ
      
*/

#include<iostream>
#include <cstdlib>//calloc����ͷ�ļ�
using namespace std;

void sort1(int arr[], int size) {

	//ѡ�����ֵ
	int max = arr[0];
	int min= arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	//calloc�����������СΪ(max + 1) * sizeof(int)���ڴ�飬����ÿ���ֽڶ���ʼ��Ϊ0��
	int* count = (int*)calloc(max-min + 1, sizeof(int));

	//����ԭʼ��������������Ԫ��ͳ��
	for (int j = 0; j < size; j++) {
		int m = arr[j];
		count[m-min]++;
	}
	
	int f = 0;
	for (int k = 0; k < max-min + 1; k++) {
		while (count[k] > 0) {
			arr[f++] = k + min;
			count[k]--;
		}
	}

	free(count);
}


int main() {

	int a[8] = { 2,5,9,1,3,2,4,2 };
	sort1(a, 8);
	for (int e : a) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}