
/*
基数排序:最低有效数字 LSD（从低位向高位排）
*/
#include<iostream>
#include<vector>
using namespace std;

//size--数组元素个数  length--字符串长度
void radixsort(string a[],int size,int length) {

	//进行length轮按位桶排序
	for (int f = length - 1; f >= 0; f--) {

		//准备桶
		vector<vector<string>> w(10);//可改为w(128)--根据ASCII码确实索引

		//把数组元素(字符串)放入合适的桶
		for (int i = 0; i < size; i++) {
			w[a[i].at(f)-'0'].push_back(a[i]);//可改为w[a[i].at(f)].push_back(a[i])
		}
		//重新取出排好序的字符串，放回原数组
		int k = 0;
		for (int j = 0; j < 10; j++) {
			for (int y = 0; y < w[j].size(); y++) {
				a[k++] = w[j][y];
			}
		}
		w.clear();//清空桶元素
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