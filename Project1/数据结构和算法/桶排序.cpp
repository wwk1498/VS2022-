/*
˼��:
  1.�Ѳ�ͬ��Χ�����ݷֳ�����С�飨Ͱ��,1-9,10-19,20-29........
  2.��Բ�ͬ��Ͱ�ֱ�������������ź�����������η���ԭ��������
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void bucketSort(int a[],int size) {
	//1.׼��Ͱ
	
	//1.1�ҵ����ֵ
	int max = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	//1.2����Ͱ����Ͱ����Ϊ��max / 10 + 1
	int index = max / 10 + 1;
	vector<vector<int>> w(index);
	
	//2.��������
	
	for (int j = 0; j < size; j++) {
		w[a[j]/10].push_back(a[j]);
	}

	//3.����Ͱ��Ԫ��,����ÿ��Ͱ������õ��������η���ԭ����
	int m = 0;
	for (int k = 0; k < index; k++) {
		sort(w[k].begin(), w[k].end());
		if (!w[k].empty()) {//��Ͱ��Ϊ�գ����滻ԭ�����Ԫ��
			for (int y = 0; y < w[k].size(); y++) {
				a[m++] = w[k][y];
			}
		}
		
	}
}

int main() {
	int s[6] = { 12,8,3,25,7,4 };
	bucketSort(s, 6);
	for (int e : s) {
		cout << e << "  ";
	}
	system("pause");
	return 0;
}