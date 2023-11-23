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
	//vector<int>w;//存储自变量下标
	//vector<vector<int>> myvec(m, vector<int>(n,0));//存储坐标元素
	//vector<int> p;//存储最终值

	string stl = getstr(str);
	//1.存储数据
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
	//2.处理数据
	
	//3.存储最终值
	cout << stl;
	
	system("pause");
	return 0;
}