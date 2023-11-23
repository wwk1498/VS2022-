
/*
��������:�����Ч���� LSD���ӵ�λ���λ�ţ�
*/
#include<iostream>
#include<vector>
using namespace std;

//size--����Ԫ�ظ���  length--�ַ�������
void radixsort(string a[],int size,int length) {

	//����length�ְ�λͰ����
	for (int f = length - 1; f >= 0; f--) {

		//׼��Ͱ
		vector<vector<string>> w(10);//�ɸ�Ϊw(128)--����ASCII��ȷʵ����

		//������Ԫ��(�ַ���)������ʵ�Ͱ
		for (int i = 0; i < size; i++) {
			w[a[i].at(f)-'0'].push_back(a[i]);//�ɸ�Ϊw[a[i].at(f)].push_back(a[i])
		}
		//����ȡ���ź�����ַ������Ż�ԭ����
		int k = 0;
		for (int j = 0; j < 10; j++) {
			for (int y = 0; y < w[j].size(); y++) {
				a[k++] = w[j][y];
			}
		}
		w.clear();//���ͰԪ��
	}
	
}
int main() {
	string s[20] = 
	{ 
		"13872654983",
		"18590436271",
        "13657098246",
        "15946823751",
        "17761548392",
        "13982016754",
        "18360457983",
        "13729045826",
        "15684927305",
        "13371548290",
        "18069523148",
        "15874102635",
        "13497650287",
        "18968375120",
        "13746019538",
        "15832946710",
        "17758392641",
        "13921680475",
        "13637482590",
        "18350794628"
	};
	radixsort(s, 20, 11);
	for (string e : s) {
		cout << e << " ";
	}
	system("pause");
	return 0;
}