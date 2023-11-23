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
	regex pg("\"(?:([^\"]*)|%d(?:(?!\\B)|.*(?!$)))\"");
	if (regex_match(str, pg)) {
		return true;
	}
	return false;
}

void Lexical::getFilename(ifstream& file) {
	file.open("test.cpp");
	if (!file) {
		cout << "文件名有误，请检查目录下是否有名为test.cpp的文件!";
	}
}

vector<pair<string, string>> Lexical::InputFile(ifstream& file, vector<pair<string, string>> token) {
	string line;//存储每行字符串
	int index;
	while (getline(file, line)) {//分别获取每行字符串
		//正则表达式进行字符串匹配,满足子字符串是单个符号，格式化字符串，数字，变量
		regex reg("\"[^\"]*\"|[a-zA-Z.\\d]+|==|!=|<=|>=|&&|\\|\\||[^\\n\\t\\ .]");//"[a-zA-Z.\\d+]+|[^\\n\\t\\ .]"
		sregex_iterator start(line.begin(), line.end(), reg);
		sregex_iterator end;
		while (start != end) {
			//获取每行字符串匹配到的第一个子字符串
			string str = start->str();
			//处理子字符串
			auto it = find(myvef.begin(), myvef.end(), str);
			if (it != myvef.end()) {// 在myvec找到了元素
				index = distance(myvef.begin(), it);//index为迭代器it相对于begin()的位置，即找到的元素的索引
				//cout << myMap[index + 1] << "  ";
				token.push_back({ myMap[index + 1] ,*it });
				//cout << *it << endl;
			}
			else if (isword(str)) {//str是个变量
				//cout << myMap[1] << "  ";
				//cout << str << endl;
				token.push_back({ myMap[1] ,str });
			}
			else if (isnumb(str)) {//str是个数字
				//cout << myMap[2] << "  ";
				//cout << str << endl;
				token.push_back({ myMap[2] ,str });
			}
			else if (isFStrb(str)) {//str是格式化字符串
				//cout << myMap[3] << "  ";
				//cout << str << endl;
				token.push_back({ myMap[3] ,str });
			}
			else {
				
				// 未找到元素
				cout << "未找到元素" << endl;
			}
			start++;
		}
	}
	file.close();
	return token;
}
