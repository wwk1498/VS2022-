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



//判断字符串仅仅是变量
bool Lexical::isword(string str) {
	regex mg("^[a-zA-Z_][a-zA-Z0-9_]*$");
	if (regex_match(str, mg)) {
		return true;
	}
	return false;
}

//判断字符串仅仅是数字
bool Lexical::isnumb(string str) {
	regex cg("\\d+");
	if (regex_match(str, cg)) {
		return true;
	}
	return false;
}
//判断字符串仅仅是格式化字符串
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
		cout << "文件名有误，请检查目录下是否有名为test.cpp的文件!";
	}
}

void Lexical::InputFile(ifstream& file) {
	string line;//存储每行字符串
	while (getline(file,line)) {//分别获取每行字符串
		//正则表达式进行字符串匹配,满足子字符串是单个符号，格式化字符串，数字，变量
		regex reg("\"[^\"]*\"|[a-zA-Z.\\d]+|==|!=|<=|>=|&&|\\|\\||else\\sif|[^\\n\\t\\ .]");//"[a-zA-Z.\\d+]+|[^\\n\\t\\ .]"
		sregex_iterator start(line.begin(),line.end(),reg);
		sregex_iterator end;
		while (start!=end) {
			//获取每行字符串匹配到的第一个子字符串
			string str = start->str();

			//处理子字符串
			auto it = find(myvec.begin(), myvec.end(), str);
			if (it != myvec.end()) {// 在myvec找到了元素
				
				int index = distance(myvec.begin(), it);//index为迭代器it相对于begin()的位置，即找到的元素的索引
				cout << myMap[index + 1] << "  ";
				cout << *it << endl;
			}
			else if (isword(str)) {//str是个变量
				cout << myMap[1] << "  " ;
				cout << str << endl;
			}
			else if (isnumb(str)) {//str是个数字
				cout << myMap[2] << "  " ;
				cout << str << endl;
			}
			else if (isFStrb(str)) {//str是格式化字符串
				cout << myMap[3] << "  " ;
				cout << str << endl;
			}
			else {
				// 未找到元素
				cout << "未找到元素" << endl;
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