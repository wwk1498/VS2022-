#include<iostream>
#include<regex>
using namespace std;

//1.字符串匹配
void testmatch() {
	string str = "3452770595@qq.com";
	regex reg("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$");
	if (regex_match(str,reg)) {
		cout << 1;
	}
	else {
		cout << 2;
	}
}
//2.字符串捕获
void testsearch() {
	//1、捕获单个字符串
	string str = "#1 include<iostream>";
	regex reg("[^ \\n\\t]|\\w+");
	smatch result;//存储字匹配结果
	if (regex_search(str,result,reg)) {
		cout << result.size() << endl;//输出获取到的子串的数量
		cout << result.str() <<endl;//输出获取到的子串
		cout << result.prefix() << endl;//输出获取到的子串的前缀
		cout << result.suffix() << endl;//输出获取到的子串的后缀
	}
	cout << "--------------------" << endl;
	//2.连续捕获多个字符串
	regex mg("\\w+|[^\\n\\t ]");
    sregex_iterator pos(str.begin(), str.end(), mg);//把匹配到的每个子字符串都存储到pos对应的数组,pos是首指针
	sregex_iterator end;//end是尾指针的后一个
	while(pos!=end) {
		cout << pos->str() << endl;
		pos++;
	}
	cout << "--------" << endl;
	//3.把匹配都的和不匹配的都获取
	string strg = "yv#245unftd78";
	regex ty("\\d+");
	sregex_token_iterator start(strg.begin(),strg.end(),ty,-1);//0：所有匹配到的，-1：所有不符合匹配的
	sregex_token_iterator enf;
	while (start!=enf) {
		cout << start->str() << endl;
		start++;
	}

}
//3.字符串替换
void testreplace() {
	//1、基本用法
	//regex_replace(string str,regex mj,string up,replacestr);
	string uh = "123iut0pbg##6$$";
	regex sd("\\d+");
	cout << regex_replace(uh, sd, "@") << endl;//输出替换后的字符串
	cout<< regex_replace(uh, sd, "@",regex_constants::format_first_only) << endl;//只替换第一次匹配到的
	cout << regex_replace(uh, sd, "@", regex_constants::format_no_copy) << endl;//有几部分满足匹配，则只输出几次
}

int main() {

	//testmatch();
	//testsearch();
	testreplace();

	system("pause");
	return 0;
}