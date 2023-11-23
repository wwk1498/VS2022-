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
	Node(vector<int> _flags, vector<int>posi):flags(_flags),position(posi){}
};

//语法分析器类
class Parser {
public:
	//构造函数
	Parser(vector<token> tok):tokens(tok){}
	
	//处理编译单parse_CompUnit
	void parse_CompUnit();
	//处理声明Decl
	Node* parse_Decl();
	//处理常量声明ConstDecl
	Node* parse_ConstDecl();
	//处理常数定义ConstDef
	Node* parse_ConstDef();
	//处理常量初值ConstInitVal
	Node* parse_ConstInitVal();
	//处理变量声明VarDecl
	Node* parse_VarDecl();
	//处理变量定义VarDef
	Node* parse_VarDef();
	//处理变量初值InitVal
	Node* parse_InitVal();
	//处理函数定义FuncDef
	Node* parse_FuncDef();
	//处理主函数定义MainFuncDef
	Node* parse_MainFuncDef();
	//处理函数类型FuncType
	Node* parse_FuncType();
	//处理函数形参表FuncFParams
	Node* parse_FuncFParams();
	//处理函数形参FuncFParam
	Node* parse_FuncFParam();
	//处理语句块Block
	Node* parse_Block();
	//处理语句块项BlockItem
	Node* parse_BlockItem();
	//处理语句Stmt
	Node* parse_Stmt();
	//处理表达式Exp
	Node* parse_Exp();
	//处理条件表达式Cond
	Node* parse_Cond();
	//处理左值表达式LVal
	Node* parse_LVal();
	//处理基本表达式PrimaryExp
	Node* parse_PrimaryExp();
	//处理数值Number
	Node* parse_Number();
	//处理一元表达式UnaryExp
	Node* parse_UnaryExp();
	//处理单目运算符UnaryOp
	Node* parse_UnaryOp();
	//处理函数实参表FuncRParms
	Node* parse_FuncRParms();
	//处理乘除模表达式MulExp
	Node* parse_MulExp();
	//处理加减表达式AddExp
	Node* parse_AddExp();
	//处理关系表达式RelExp
	Node* parse_RelExp();
	//处理相等性表达式EqExp
	Node* parse_EqExp();
	//处理逻辑与表达式LAndExp
	Node* parse_LAndExp();
	//处理逻辑或表达式LOrExp
	Node* parse_LOrExp();
	//处理常量表达式ConstExp
	Node* parse_ConstExp();
	//判断标识符Ident
	bool parse_Ident();
	//判断数值常量IntConst
	bool parse_IntConst();
	//判断取值是否满足要求
	bool judgval(Node* p);
	//程序入口
	void printl();

private:
	int i;
	vector<token> tokens;
};

//处理编译单parse_CompUnit
void Parser::parse_CompUnit() {

	//处理声明Decl
	Node* a = parse_Decl();

	//处理函数定义FuncDef
	Node* b = parse_FuncDef();
	
	//处理主函数定义MainFuncDef
	Node* c = parse_MainFuncDef();

	if (judgval(c)) {
		if (judgval(a) && judgval(b)) {
			//输出 声明 函数 主函数都有
			
		}
		else if (judgval(a)) {
			//输出 声明  主函数
		}
		else if (judgval(b)) {
			// 输出 函数 主函数
		}
		else {
			//输出 主函数
		}
	}
	else {
		//此处 主函数不满足要求，不用输出
	}
	 
}

//处理声明Decl
Node* Parser::parse_Decl() {
	vector<int> flag;
	vector<int> posi;
	//处理常量声明ConstDecl
	Node* a = parse_ConstDecl();
	//处理变量声明VarDecl
	Node* b = parse_VarDecl();
	
	if (judgval(a)) {
		//输出 常量声明
		flag.push_back(1);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag,posi);
	}
	else if (judgval(b)) {
		//输出 变量声明
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(1);
		return new Node(flag, posi);
	}
	else {
		//此处为 无常量声明 无变量声明，不用输出
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		return new Node(flag, posi);
	}

}
//处理常量声明ConstDecl
Node* Parser::parse_ConstDecl() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z,k;
	//1.判断const类型
	if (tokens[i].value == "const") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2.判断int类型
	if (tokens[i].value == "int") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//3.处理常数定义ConstDef
	Node* a = parse_ConstDef();
	//4.判断逗号
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}
	//5.处理常数定义ConstDef
	Node* b = parse_ConstDef();
	//6.判断int类型
	if (tokens[i].value == ";") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		k = 1;
	}
	else {
		k = 0;
	}

	//综合判断
	if (x&&y&& judgval(a)&&k) {
		//输出满足花括号内重复0次
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else if (x && y && judgval(a)&&z&& judgval(b)&& k) {
		//输出满足花括号内重复1次
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else {
		//此处为不满足常量声明ConstDecl，不用输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(5);
		return new Node(flag, posi);
	}


}
//处理常数定义ConstDef
Node* Parser::parse_ConstDef() {
	vector<int> flag;
	vector<int> posi;
	bool flg;
	int x, y, z;

	//1.判断标识符
	flg = parse_Ident();
	//2.判断 [
	if (tokens[i].value == "[") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.判断常量表达式
	Node* a = parse_ConstExp();
	//4.判断 ]
	if (tokens[i].value == "]") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//5.判断 =
	if (tokens[i].value == "=") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}
	//6.判断 常量初值
	Node* b = parse_ConstInitVal();

	//综合判断
	if (flg&&z&&judgval(b)) {
		//1,5,6类似 a=0 的普通变量
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else if (flg &&x&& judgval(a)&&y&& z && judgval(b)) {
		//1,2,3,4,5,6类似 a[0]=1 的一维数组
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else {
		//不满足常数定义ConstDef，不用输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
}
//处理常量初值ConstInitVal
Node* Parser::parse_ConstInitVal() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z;
	//1.处理常量表达式ConstExp
	Node*a= parse_ConstExp();
	//2.判断 {
	if (tokens[i].value == "{") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.常量初值
	Node* b = parse_ConstInitVal();
	//4.判断,
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	
	//5.常量初值
	Node* c = parse_ConstInitVal();
	//6.判断 }
	if (tokens[i].value == "}") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}

	//综合判断
	if (judgval(a)&&!x&& !judgval(b)&&!y&& !judgval(c)&&!z) {
		//1,输出只有 常量表达式ConstExp
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if (!judgval(a) && x && judgval(b) && !y && !judgval(c) && z) {
		//2,3,6 类似{2+3}
		flag.push_back(0);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else if(!judgval(a) && x && judgval(b) && y && judgval(c)&& z){
		//2,3,4,5,6类似{2+3,{2+3}};
		flag.push_back(0);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else {
		//错误，不用输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}

}
//处理变量声明VarDecl
Node* Parser::parse_VarDecl() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z;
	//1.判断int
	if (tokens[i].value == "int") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2.处理变量定义VarDef
	Node* a = parse_VarDef();
	//3.判断,
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//4.处理变量定义VarDef
	Node* b = parse_VarDef();
	//5.判断;
	if (tokens[i].value == ";") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}

	//综合判断
	if (x&& judgval(a)&&z) {
		//1,2,5 类似int a;
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(4);
		return new Node(flag, posi);
	}
	else if (x && judgval(a)&&y&& judgval(b)&& z) {
		//1,2,3,4,5类似int a=0,b=1;
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		return new Node(flag, posi);

	}
	else {
		//有问题，不用输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(4);
		return new Node(flag, posi);
	}

}
//处理变量定义VarDef
Node* Parser::parse_VarDef() {
	vector<int> flag;
	vector<int> posi;
	int x, y;
	//1.处理标识符
	bool flg = parse_Ident();
	//2. [
	if (tokens[i].value == "[") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.常量表达式parse_ConstExp()
	Node* a = parse_ConstExp();
	
	//4.]
	if (tokens[i].value == "]") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}

	//综合判断
	if (flg&&!x&&!judgval(a)&&!y) {
		//1,类似 a
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if (flg && x && judgval(a) &&y) {
		//1,2,3,4类似 arry[8]
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		return new Node(flag, posi);
	}
	else {
		//错误，不用输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}

}
//处理变量初值InitVal
Node* Parser::parse_InitVal() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z;
	//1.表达式EXP
	Node* a = parse_Exp();
	//2.  {
	if (tokens[i].value == "{") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.变量初值InitVal
	Node* b = parse_InitVal();
	//4.   ,
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//5.变量初值InitVal
	Node* c = parse_InitVal();
	//6.  }
	if (tokens[i].value == "{") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}

	//综合判断
	if (judgval(a)&&!x&& !judgval(b)&&!y&&!judgval(c)&&!z) {
		//1，只有Exp,类似8
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if (!judgval(a) && x && judgval(b) && y && judgval(c) && z) {
		//2,3,4,5,6类似{3,8}
		flag.push_back(0);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else if(!judgval(a) && x && !judgval(b) && !y && !judgval(c) && z) {
		//2,6类似{}
		flag.push_back(0);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(1);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else {
		//错误，不用输出
		//1，只有Exp,类似8
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}

}
//处理函数定义FuncDef
Node* Parser::parse_FuncDef() {
	vector<int> flag;
	vector<int> posi;
	int x, y;
	//1.  FuncType
	Node* a = parse_FuncType();
	//2.  Ident
	bool flg = parse_Ident();
	//3.  (
	if (tokens[i].value == "(") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//4.  FuncFParams
	Node* b = parse_FuncFParams();
	//5.  )
	if (tokens[i].value == ")") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//6. Block 
	Node* c = parse_Block();

	//综合分析
	if (judgval(a)&&flg &&x &&!judgval(b) &&y && c) {
		//1,2,3,5,6 类似 int fun(){}
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}
	else if (judgval(a) && flg && x && judgval(b) && y && c) {
		//1,2,3,4,5,6类似 int fun(int a){}
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);

	}
	else {
		//错误，不输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(4);
		posi.push_back(5);
		return new Node(flag, posi);
	}

}

//处理主函数定义MainFuncDef
Node* Parser::parse_MainFuncDef() {
	vector<int> flag;
	vector<int> posi;
	int x, y,z,k;

	//1.  int 
	if (tokens[i].value == "int") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2.   main
	if (tokens[i].value == "main") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//3.  (
	if (tokens[i].value == "(") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}
	//4.  )
	if (tokens[i].value == ")") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		k = 1;
	}
	else {
		k = 0;
	}
	//5.  block
	Node* a = parse_Block();

	//综合
	if (x&&y&&z&&k&&judgval(a)) {
		//1,2,3,4,5
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		return new Node(flag, posi);
	}
	
	else {
		//错误，不输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		return new Node(flag, posi);
	}

}
//处理函数类型FuncType
Node* Parser::parse_FuncType() {
	vector<int> flag;
	vector<int> posi;
	int x, y;
	//1.void
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2.int
	if (tokens[i].value == "int") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}

	//综合判断
	if (x) {
		//是void
		flag.push_back(1);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if (y) {
		//是int
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(1);
		return new Node(flag, posi);
	}
	else {
		//错误，不用输出
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}

}
//处理函数形参表FuncFParams
Node* Parser::parse_FuncFParams() {
	vector<int> flag;
	vector<int> posi;
	int x;
	//1.FuncFParam
	Node* a = parse_FuncFParam();
	//2.  ,
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.FuncFParam
	Node* b = parse_FuncFParam();


	//综合
	if (judgval(a)&&!x&&!judgval(b)) {
		//1,类似 int a[]
		flag.push_back(1);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if(judgval(a) && x && judgval(b)) {
		//1,2,3类似 int a[][3]
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		return new Node(flag, posi);
	}
	else {
		//错误，不输出
		//1,类似 int a[]
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
}
//处理函数形参FuncFParam
Node* Parser::parse_FuncFParam() {

	vector<int> flag;
	vector<int> posi;
	int x, y, z, k,m;

	//1. int 
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2. 标识符
	bool flg = parse_Ident();
	// 3. [
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//4. ]
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}
	//5. [
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		k = 1;
	}
	else {
		k = 0;
	}
	//6.常量表达式
	Node* a = parse_ConstExp();
	//7. ]
	if (tokens[i].value == "void") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		m = 1;
	}
	else {
		m = 0;
	}


	//综合
	if (x &&flg &&!y&&!z&& !k && !judgval(a)&&!m) {
		//1,2类似 int a 
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		return new Node(flag, posi);
	}
	else if (x && flg && y && z && !k && !judgval(a) && !m) {
		//1,2,3,4 类似 int[]
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		return new Node(flag, posi);
	}
	else if (x && flg && y && z && k && judgval(a) && m) {
		//1,2,3,4,5,6,7 类似 int[][3]
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		posi.push_back(3);
		posi.push_back(4);
		posi.push_back(5);
		posi.push_back(6);
		return new Node(flag, posi);
	}
	else {
		//错误，不输出
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		return new Node(flag, posi);
	}


}
//处理语句块Block
Node* Parser::parse_Block() {

}
//处理语句块项BlockItem
Node* Parser::parse_BlockItem() {

}
//处理语句Stmt
Node* Parser::parse_Stmt() {

}
//处理表达式Exp
Node* Parser::parse_Exp() {

}
//处理条件表达式Cond
Node* Parser::parse_Cond() {

}
//处理左值表达式LVal
Node* Parser::parse_LVal() {

}
//处理基本表达式PrimaryExp
Node* Parser::parse_PrimaryExp() {

}
//处理数值Number
Node* Parser::parse_Number() {

}
//处理一元表达式UnaryExp
Node* Parser::parse_UnaryExp() {

}
//处理单目运算符UnaryOp
Node* Parser::parse_UnaryOp() {

}
//处理函数实参表FuncRParms
Node* Parser::parse_FuncRParms() {

}
//处理乘除模表达式MulExp
Node* Parser::parse_MulExp() {

}
//处理加减表达式AddExp
Node* Parser::parse_AddExp() {

}
//处理关系表达式RelExp
Node* Parser::parse_RelExp() {

}
//处理相等性表达式EqExp
Node* Parser::parse_EqExp() {

}
//处理逻辑与表达式LAndExp
Node* Parser::parse_LAndExp() {

}
//处理逻辑或表达式LOrExp
Node* Parser::parse_LOrExp() {

}
//处理常量表达式ConstExp
Node* Parser::parse_ConstExp() {

}

//判断标识符Ident
bool Parser::parse_Ident() {
	string str = tokens[i].value;
	cout << tokens[i].type << "  " << tokens[i].value << endl;
	i++;
	regex mg("^[a-zA-Z_][a-zA-Z0-9_]*$");
	if (regex_match(str, mg)) {
		return true;
	}
	return false;

}
//判断数值常量IntConst
bool Parser::parse_IntConst() {

}

//判断取值是否满足要求
bool Parser::judgval(Node* p){
	bool flg = true;
	for (int e : p->position) {
		if (p->flags[e] == 0) {
			flg = false;
			break;
		}
	}
	if (flg) {
		return true;
	}
	return false;
}

//程序入口
void Parser::printl() {
	i = 0;
	parse_CompUnit();
}



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