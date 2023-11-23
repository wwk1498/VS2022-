/*
�鲢����
1.��-ÿ�δ��м���һ���������������һ��
2.��-�����ݽ�ʣһ��ʱ������Ϊ����
3.��-��������Ľ�������Խ��кϲ�
*/

#include<iostream>
using namespace std;

//�ϲ�������������---�ǵݹ�     a1--ԭ���飬a2--�����飬k--����������
//i--ԭ�����󲿷���ʼ������iend--ԭ�����󲿷����������j--ԭ�����Ҳ�����ʼ������jend--ԭ�����Ҳ����������

void merge(int a1[],int i,int iend,int j,int jend,int a2[],int k) {
	while (i<=iend && j<=jend) {
		if (a1[i]<a1[j]) {
			a2[k] = a1[i];
			i++;
		}
		else {
			a2[k] = a1[j];
			j++;
		}
		k++;
	}
	//iû����
	while (i <= iend) {
		a2[k] = a1[i];
		i++;
		k++;
	}
	//jû����
	while(j <= jend) {
		a2[k] = a1[j];
		j++;
		k++;
	}
}

//�ϲ�������������---�ݹ�     a1--ԭ���飬a2--�����飬k--����������
//i--ԭ�����󲿷���ʼ������iend--ԭ�����󲿷����������j--ԭ�����Ҳ�����ʼ������jend--ԭ�����Ҳ����������
void merge1(int a1[], int i, int iend, int j, int jend, int a2[], int k) {

	//jû����
	if (i>iend) {
		while (j<=jend) {
			a2[k] = a1[j];
			j++;
			k++;
		}
		return;
	}

	//iû����
	if (j > jend) {
		while (i<=iend) {
			a2[k] = a1[i];
			i++;
			k++;
		}
		return;
	}
	if (a1[i]<a1[j]) {
		a2[k] = a1[i];
		merge1(a1, i + 1, iend, j, jend, a2, k + 1);
	}
	else {
		a2[k] = a1[j];
		merge1(a1, i, iend, j+1, jend, a2, k + 1);
	}

}


//�鲢����--�ݹ飨���϶��£�---left=0,right=size-1,k=0
void split(int a1[],int left ,int right,int a2[],int k) {

	//��
	if (left == right) {
		return;
	}

	//��
	int mid = (left + right) / 2;

	split(a1, left, mid,a2,k);
	split(a1,mid+1,right,a2,k);

	//��
	merge(a1, left, mid, mid+1, right, a2,k);
}

//�鲢����--�ǵݹ飨���¶��ϣ�
void split1(int a1[],int size,int a2[], int k) {
	for (int width = 1; width < size; width *= 2) {
		for (int left = 0; left < size; left += 2 * width) {
			int right = min(left+2*width-1,size-1);
			int mid = (left + right) / 2;
			merge(a1, left, mid, mid+1, right, a2, k);
		}
	}
}


int main() {
	int s[10] = { 1,3,6,8,9,4,7,13,20,60 };
	int w[10];
	split1(s, 10, w, 0);
	for (int e : w) {
		cout << e << " ";
	}

	system("pause");
	return 0;
}