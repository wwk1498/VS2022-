#include "lex.h"

 vector<string> myvef{ "Ident","IntConst","FormatStrin","main","const","int","break","continue",
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
	regex pg("\"(?:([^\"]*)|%d(?:(?!\\B)|.*(?!$)))\"");
	if (regex_match(str, pg)) {
		return true;
	}
	return false;
}

void Lexical::getFilename(ifstream& file) {
	file.open("test.cpp");
	if (!file) {
		cout << "�ļ�����������Ŀ¼���Ƿ�����Ϊtest.cpp���ļ�!";
	}
}

vector<pair<string, string>> Lexical::InputFile(ifstream& file, vector<pair<string, string>> token) {
	string line;//�洢ÿ���ַ���
	int index;
	while (getline(file, line)) {//�ֱ��ȡÿ���ַ���
		//������ʽ�����ַ���ƥ��,�������ַ����ǵ������ţ���ʽ���ַ��������֣�����
		regex reg("\"[^\"]*\"|[a-zA-Z.\\d]+|==|!=|<=|>=|&&|\\|\\||[^\\n\\t\\ .]");//"[a-zA-Z.\\d+]+|[^\\n\\t\\ .]"
		sregex_iterator start(line.begin(), line.end(), reg);
		sregex_iterator end;
		while (start != end) {
			//��ȡÿ���ַ���ƥ�䵽�ĵ�һ�����ַ���
			string str = start->str();
			//�������ַ���
			auto it = find(myvef.begin(), myvef.end(), str);
			if (it != myvef.end()) {// ��myvec�ҵ���Ԫ��
				index = distance(myvef.begin(), it);//indexΪ������it�����begin()��λ�ã����ҵ���Ԫ�ص�����
				//cout << myMap[index + 1] << "  ";
				token.push_back({ myMap[index + 1] ,*it });
				//cout << *it << endl;
			}
			else if (isword(str)) {//str�Ǹ�����
				//cout << myMap[1] << "  ";
				//cout << str << endl;
				token.push_back({ myMap[1] ,str });
			}
			else if (isnumb(str)) {//str�Ǹ�����
				//cout << myMap[2] << "  ";
				//cout << str << endl;
				token.push_back({ myMap[2] ,str });
			}
			else if (isFStrb(str)) {//str�Ǹ�ʽ���ַ���
				//cout << myMap[3] << "  ";
				//cout << str << endl;
				token.push_back({ myMap[3] ,str });
			}
			else {
				
				// δ�ҵ�Ԫ��
				cout << "δ�ҵ�Ԫ��" << endl;
			}
			start++;
		}
	}
	file.close();
	return token;
}
