/*

��������Ҫ��:
 1.�ҵ����ֵ������һ����СΪ���ֵ+1��count����
 2.count�����������Ӧԭʼ�����Ԫ�أ�����ͳ�Ƹ�Ԫ�صĳ��ִ���
 3.����count���飬����count�������������ԭʼ�����Ԫ�أ��Լ����ִ�����������������ݣ�count�����������:
   ���ź����
 ǰ��:������Ԫ��>=0�����ֵ����̫��

*/

#include<iostream>
#include <cstdlib>//calloc����ͷ�ļ�
using namespace std;

void sort1(int arr[],int size) {

	//ѡ�����ֵ
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i]>max) {
			max = arr[i];
		}
	}
	
	//calloc�����������СΪ(max + 1) * sizeof(int)���ڴ�飬����ÿ���ֽڶ���ʼ��Ϊ0��
	int* count = (int*)calloc(max + 1, sizeof(int));

	//����ԭʼ��������������Ԫ��ͳ��
	for (int j = 0; j < size; j++) {
		int m = arr[j];
		count[m]++;
	}
	
	int f=0;
	for (int k = 0; k < max + 1; k++) {
		while (count[k]>0) {
			arr[f++] = k;
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