#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

stack<string>mt;

string getstr(string str) {
	for (char e : str) {
		if (e!=' ') {
			cout << e << endl;
			string  at = to_string(e);
			cout << at << endl;
			if ((at!="+")&& (at != "-")&& (at != "*")) {
				mt.push(at);
			}
			else {
				string t1 = mt.top();
				cout << t1 << endl;
				mt.pop();
				string t2 = mt.top();
				mt.pop();
				string t3 = t1 + e + t2;
				cout << t3 << endl;
				mt.push(t3);
			}
		}
	}
	string tm = mt.top();
	mt.pop();
	return tm;

}

int main() {
	//int n, m;
	//cin >> n >> m;
	string str;
	//cin >> str;
	getline(cin, str);
	//vector<int>w;//�洢�Ա����±�
	//vector<vector<int>> myvec(m, vector<int>(n,0));//�洢����Ԫ��
	//vector<int> p;//�洢����ֵ

	string stl = getstr(str);
	//1.�洢����
	/*for (int i = 0; i < m; i++) {
		int d;
		cin >> d;
		w.push_back(d);
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			myvec[i][j] = x;
		}
		
	}*/
	//2.��������
	
	//3.�洢����ֵ
	cout << stl;
	
	system("pause");
	return 0;
}