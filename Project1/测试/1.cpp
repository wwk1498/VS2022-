#include<iostream>
#include<vector>
#include<regex>
#include<algorithm>
using namespace std;

//����
struct token {
	string type;
	string value;
};

//����ڵ���
class Node {
public:
	vector<int>flags;//�洢���ֵ�����ȡֵ
	vector<int>position;//��������Ҫ��Ĳ��ֵ�λ��
	Node(vector<int> _flags, vector<int>posi) :flags(_flags), position(posi) {}
};

//�﷨��������
class Parser {
public:
	vector<token> tokens;
	//���캯��
	Parser(vector<token> tok) :tokens(tok) {}

	//������뵥parse_CompUnit
	void parse_CompUnit() {
		Node* a = parse_Decl();

		Node* b = parse_Miain();

	}
	//��������Decl
	Node* parse_Miain() {

	}
	//����������ConstDecl
	Node* parse_Decl() {

	}
	//����������ConstDef
	Node* parse_ConstDef(){

	}
	//��������ֵConstInitVal
	Node* parse_ConstInitVal() {

	}
	//�����������VarDecl
	Node* parse_VarDecl() {

	}
	//�����������VarDef
	Node* parse_VarDef() {

	}
	//���
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