#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cctype>
#include<regex>
#include<string>
#include<algorithm>
using namespace std;

vector<string> myvec{"Ident","IntConst","FormatStrin","main","const","int","break","continue",
 "if","else","!","&&","||","while","getint","printf","return","+","-","void","*","/","%","<","<=",">",
	">=","==","!=","=",";",",","(",")","[","]","{","}"
};

map<int, string> myMap{
		{ 1,"IDENFR" }, { 2,"INTCON" }, { 3,"STRCON" }, { 4,"MAINTK" }, { 5,"CONSTTK" }, { 6,"INTTK" }, { 7,"BREAKTK" }, { 8,"CONTINUETK" },
		{ 9,"IFTK" }, { 10,"ELSETK" }, { 11,"NOT" }, { 12,"AND" }, { 13,"OR" }, { 14,"WHILETK" }, { 15,"GETINTTK" }, { 16,"PRINTFTK" }, { 17,"RETURNTK" },
		{ 18,"PLU" }, { 19,"MINU" }, { 20,"VOIDTK" }, { 21,"MULT" }, { 22,"DIV" }, { 23,"MOD" }, { 24,"LSS" }, { 25,"LEQ" }, { 26,"GRE" },
		{ 27,"GEQ" }, { 28,"EQL" }, { 29,"NEQ" }, { 30,"ASSIGN" }, { 31,"SEMICN" }, { 32,"COMMA" }, { 33,"LPARENT" }, { 34,"RPARENT" }, { 35,"LBRACK" },
		{ 36,"RBRACK" }, { 37,"LBRACE" }, { 38,"RBRACE" }

};

class Lexical {
public:
	void getFilename(ifstream& file);
	void InputFile(ifstream& file);
	bool isword(string str);
	bool isnumb(string str);
	bool isFStrb(string str);
};



//�ж��ַ��������Ǳ���
bool Lexical::isword(string str) {
	regex mg("^[a-zA-Z_][a-zA-Z0-9_]*$");
	if (regex_match(str, mg)) {
		return true;
	}
	return false;
}

//�ж��ַ�������������
bool Lexical::isnumb(string str) {
	regex cg("\\d+");
	if (regex_match(str, cg)) {
		return true;
	}
	return false;
}
//�ж��ַ��������Ǹ�ʽ���ַ���
bool Lexical::isFStrb(string str) {
	regex pg("\"(?:([^\"]*)|%d(?:(?!\\B)|.*(?!$)))\"");//pg("^[\"][%][.\\d+\\w+]*[\"]$");
	if (regex_match(str, pg)) {
		return true;
	}
	return false;
}

void Lexical::getFilename(ifstream& file) {
	file.open("test.cpp");
	if(!file){
		cout << "�ļ�����������Ŀ¼���Ƿ�����Ϊtest.cpp���ļ�!";
	}
}

void Lexical::InputFile(ifstream& file) {
	string line;//�洢ÿ���ַ���
	while (getline(file,line)) {//�ֱ��ȡÿ���ַ���
		//������ʽ�����ַ���ƥ��,�������ַ����ǵ������ţ���ʽ���ַ��������֣�����
		regex reg("\"[^\"]*\"|[a-zA-Z.\\d]+|==|!=|<=|>=|&&|\\|\\||else\\sif|[^\\n\\t\\ .]");//"[a-zA-Z.\\d+]+|[^\\n\\t\\ .]"
		sregex_iterator start(line.begin(),line.end(),reg);
		sregex_iterator end;
		while (start!=end) {
			//��ȡÿ���ַ���ƥ�䵽�ĵ�һ�����ַ���
			string str = start->str();

			//�������ַ���
			auto it = find(myvec.begin(), myvec.end(), str);
			if (it != myvec.end()) {// ��myvec�ҵ���Ԫ��
				
				int index = distance(myvec.begin(), it);//indexΪ������it�����begin()��λ�ã����ҵ���Ԫ�ص�����
				cout << myMap[index + 1] << "  ";
				cout << *it << endl;
			}
			else if (isword(str)) {//str�Ǹ�����
				cout << myMap[1] << "  " ;
				cout << str << endl;
			}
			else if (isnumb(str)) {//str�Ǹ�����
				cout << myMap[2] << "  " ;
				cout << str << endl;
			}
			else if (isFStrb(str)) {//str�Ǹ�ʽ���ַ���
				cout << myMap[3] << "  " ;
				cout << str << endl;
			}
			else {
				// δ�ҵ�Ԫ��
				cout << "δ�ҵ�Ԫ��" << endl;
			}
			start++;
		}
	}
	file.close();
}

int main() {
	Lexical* lex = new Lexical;
	ifstream file;
	lex->getFilename(file);
	lex->InputFile(file);
	system("pause");
	return 0;
}