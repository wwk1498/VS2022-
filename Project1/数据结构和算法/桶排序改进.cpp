
/*
�Ľ������Ԫ�ط��䲻���ȵ����:

 1.ϣ��Ͱ��Ԫ�ؾ��ȷֲ�,��Ͱ�ĸ����Ľ�Ϊ max-min+1,ÿ��Ͱ��������Ϊ ����ǰֵ-min��
 2.ϣ��ÿ��Ͱ�ڴ洢rang��Ԫ�أ������ٴ���Ͱ�ĸ�������ʱͰ�ĸ����Ľ�Ϊ ��max-min)/rang +1,ÿ��Ͱ��������Ϊ ����ǰֵ-min)/rang


*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void bucketSort(int a[], int size,int rang) {
	//1.׼��Ͱ

	//1.1�ҵ����ֵ����Сֵ
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	//1.2����Ͱ����Ͱ����Ϊ��max-min+ 1
	int index = (max-min)/rang+ 1;
	vector<vector<int>> w(index);

	//2.��������

	for (int j = 0; j < size; j++) {
		w[(a[j] - min) / rang].push_back(a[j]);
	}

	//3.����Ͱ��Ԫ��,����ÿ��Ͱ������õ��������η���ԭ����
	int m = 0;
	for (int k = 0; k < index; k++) {
		if (!w[k].empty()) {//��Ͱ��Ϊ�գ�������Ͱ��Ԫ��,�滻ԭ�����Ԫ��
			sort(w[k].begin(), w[k].end());
			for (int y = 0; y < w[k].size(); y++) {
				a[m++] = w[k][y];
			}
		}
	}
}

int main() {
	int s[6] = { 12,8,3,25,7,4 };
	bucketSort(s, 6,3);
	for (int e : s) {
		cout << e << "  ";
	}
	system("pause");
	return 0;
}
