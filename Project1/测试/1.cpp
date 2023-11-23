#include<iostream>
#include<vector>
#include<regex>
#include<algorithm>
using namespace std;

//单词
struct token {
	string type;
	string value;
};

//定义节点类
class Node {
public:
	vector<int>flags;//存储出现的所有取值
	vector<int>position;//必须满足要求的部分的位置
	Node(vector<int> _flags, vector<int>posi) :flags(_flags), position(posi) {}
};

//语法分析器类
class Parser {
public:
	vector<token> tokens;
	//构造函数
	Parser(vector<token> tok) :tokens(tok) {}

	//处理编译单parse_CompUnit
	void parse_CompUnit() {
		Node* a = parse_Decl();

		Node* b = parse_Miain();

	}
	//处理声明Decl
	Node* parse_Miain() {

	}
	//处理常量声明ConstDecl
	Node* parse_Decl() {

	}
	//处理常数定义ConstDef
	Node* parse_ConstDef(){

	}
	//处理常量初值ConstInitVal
	Node* parse_ConstInitVal() {

	}
	//处理变量声明VarDecl
	Node* parse_VarDecl() {

	}
	//处理变量定义VarDef
	Node* parse_VarDef() {

	}
	//入口
	void printl() {
		i = 0;
		parse_CompUnit();
	}

private:
	int i;
	vector<token> tokens;

};


int main() {

	vector<token> tokens{
	 {"INTTK" ,"int"},
	  {"MAINTK"," main"},
	  {"LPARENT","("},
	  {"RPARENT",")"},
	   {"LBRACE", "{"},
	  {"INTTK" ,"int"},
	   {"IDENFR", "c"},
	   {"SEMICN",";" }
	};
	Parser* parse = new Parser(tokens);
	parse->printl();
	system("pause");
	return 0;
}