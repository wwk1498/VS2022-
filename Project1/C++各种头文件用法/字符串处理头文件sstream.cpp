#include<iostream>
#include<sstream>//stringstream ss
#include<vector>
#include<cctype>//isalnum(str)�ж� �ַ�str �Ƿ�����ĸ�����֣��� �������������� ����0
using namespace std;


int main() {
	string str = "# include<iostream> ii 786 %%&     q";
	stringstream ss(str);//ȥ��str�еĿո��\n,\t
	string word;
	vector<string>words;
	while (ss>>word) {//���ζ�ȡss���Կո�Ϊ�ֽ�ĵ��ʻ��ַ�����ֵ��word
		string w;
		string s;
		bool flag = true;
		for (char e:word) {
			
			if (isalnum(e)) {
				w += e;
				if (!flag) {
					;
					flag = true;
				}
			}
			else {
				s += e;
				flag = false;
			}
		}
		if (!w.empty()) {
			words.push_back(w);
		}
		if (!s.empty()) {
			words.push_back(s);
		}
		for (string k : words) {
			cout << k << endl;
		}
		words.clear();
	}

	system("pause");
	return 0;
}
/*
* 
�����
includeiostream
<>
ii
786
%%&
q

*/