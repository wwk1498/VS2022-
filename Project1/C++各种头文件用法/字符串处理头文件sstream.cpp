#include<iostream>
#include<sstream>//stringstream ss
#include<vector>
#include<cctype>//isalnum(str)判断 字符str 是否是字母或数字，是 返回正数，否则 返回0
using namespace std;


int main() {
	string str = "# include<iostream> ii 786 %%&     q";
	stringstream ss(str);//去掉str中的空格和\n,\t
	string word;
	vector<string>words;
	while (ss>>word) {//依次读取ss中以空格为分界的单词或字符，赋值给word
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
输出：
includeiostream
<>
ii
786
%%&
q

*/