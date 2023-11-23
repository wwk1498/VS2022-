#include<iostream>
#include<regex>
using namespace std;

//1.�ַ���ƥ��
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
//2.�ַ�������
void testsearch() {
	//1�����񵥸��ַ���
	string str = "#1 include<iostream>";
	regex reg("[^ \\n\\t]|\\w+");
	smatch result;//�洢��ƥ����
	if (regex_search(str,result,reg)) {
		cout << result.size() << endl;//�����ȡ�����Ӵ�������
		cout << result.str() <<endl;//�����ȡ�����Ӵ�
		cout << result.prefix() << endl;//�����ȡ�����Ӵ���ǰ׺
		cout << result.suffix() << endl;//�����ȡ�����Ӵ��ĺ�׺
	}
	cout << "--------------------" << endl;
	//2.�����������ַ���
	regex mg("\\w+|[^\\n\\t ]");
    sregex_iterator pos(str.begin(), str.end(), mg);//��ƥ�䵽��ÿ�����ַ������洢��pos��Ӧ������,pos����ָ��
	sregex_iterator end;//end��βָ��ĺ�һ��
	while(pos!=end) {
		cout << pos->str() << endl;
		pos++;
	}
	cout << "--------" << endl;
	//3.��ƥ�䶼�ĺͲ�ƥ��Ķ���ȡ
	string strg = "yv#245unftd78";
	regex ty("\\d+");
	sregex_token_iterator start(strg.begin(),strg.end(),ty,-1);//0������ƥ�䵽�ģ�-1�����в�����ƥ���
	sregex_token_iterator enf;
	while (start!=enf) {
		cout << start->str() << endl;
		start++;
	}

}
//3.�ַ����滻
void testreplace() {
	//1�������÷�
	//regex_replace(string str,regex mj,string up,replacestr);
	string uh = "123iut0pbg##6$$";
	regex sd("\\d+");
	cout << regex_replace(uh, sd, "@") << endl;//����滻����ַ���
	cout<< regex_replace(uh, sd, "@",regex_constants::format_first_only) << endl;//ֻ�滻��һ��ƥ�䵽��
	cout << regex_replace(uh, sd, "@", regex_constants::format_no_copy) << endl;//�м���������ƥ�䣬��ֻ�������
}

int main() {

	//testmatch();
	//testsearch();
	testreplace();

	system("pause");
	return 0;
}