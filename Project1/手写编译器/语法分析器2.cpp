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
	Node(vector<int> _flags, vector<int>posi):flags(_flags),position(posi){}
};

//�﷨��������
class Parser {
public:
	//���캯��
	Parser(vector<token> tok):tokens(tok){}
	
	//������뵥parse_CompUnit
	void parse_CompUnit();
	//��������Decl
	Node* parse_Decl();
	//����������ConstDecl
	Node* parse_ConstDecl();
	//����������ConstDef
	Node* parse_ConstDef();
	//��������ֵConstInitVal
	Node* parse_ConstInitVal();
	//�����������VarDecl
	Node* parse_VarDecl();
	//�����������VarDef
	Node* parse_VarDef();
	//���������ֵInitVal
	Node* parse_InitVal();
	//����������FuncDef
	Node* parse_FuncDef();
	//��������������MainFuncDef
	Node* parse_MainFuncDef();
	//����������FuncType
	Node* parse_FuncType();
	//�������βα�FuncFParams
	Node* parse_FuncFParams();
	//�������β�FuncFParam
	Node* parse_FuncFParam();
	//��������Block
	Node* parse_Block();
	//����������BlockItem
	Node* parse_BlockItem();
	//�������Stmt
	Node* parse_Stmt();
	//������ʽExp
	Node* parse_Exp();
	//�����������ʽCond
	Node* parse_Cond();
	//������ֵ���ʽLVal
	Node* parse_LVal();
	//����������ʽPrimaryExp
	Node* parse_PrimaryExp();
	//������ֵNumber
	Node* parse_Number();
	//����һԪ���ʽUnaryExp
	Node* parse_UnaryExp();
	//����Ŀ�����UnaryOp
	Node* parse_UnaryOp();
	//������ʵ�α�FuncRParms
	Node* parse_FuncRParms();
	//����˳�ģ���ʽMulExp
	Node* parse_MulExp();
	//����Ӽ����ʽAddExp
	Node* parse_AddExp();
	//�����ϵ���ʽRelExp
	Node* parse_RelExp();
	//��������Ա��ʽEqExp
	Node* parse_EqExp();
	//�����߼�����ʽLAndExp
	Node* parse_LAndExp();
	//�����߼�����ʽLOrExp
	Node* parse_LOrExp();
	//���������ʽConstExp
	Node* parse_ConstExp();
	//�жϱ�ʶ��Ident
	bool parse_Ident();
	//�ж���ֵ����IntConst
	bool parse_IntConst();
	//�ж�ȡֵ�Ƿ�����Ҫ��
	bool judgval(Node* p);
	//�������
	void printl();

private:
	int i;
	vector<token> tokens;
};

//������뵥parse_CompUnit
void Parser::parse_CompUnit() {

	//��������Decl
	Node* a = parse_Decl();

	//����������FuncDef
	Node* b = parse_FuncDef();
	
	//��������������MainFuncDef
	Node* c = parse_MainFuncDef();

	if (judgval(c)) {
		if (judgval(a) && judgval(b)) {
			//��� ���� ���� ����������
			
		}
		else if (judgval(a)) {
			//��� ����  ������
		}
		else if (judgval(b)) {
			// ��� ���� ������
		}
		else {
			//��� ������
		}
	}
	else {
		//�˴� ������������Ҫ�󣬲������
	}
	 
}

//��������Decl
Node* Parser::parse_Decl() {
	vector<int> flag;
	vector<int> posi;
	//����������ConstDecl
	Node* a = parse_ConstDecl();
	//�����������VarDecl
	Node* b = parse_VarDecl();
	
	if (judgval(a)) {
		//��� ��������
		flag.push_back(1);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag,posi);
	}
	else if (judgval(b)) {
		//��� ��������
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(1);
		return new Node(flag, posi);
	}
	else {
		//�˴�Ϊ �޳������� �ޱ����������������
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		posi.push_back(1);
		return new Node(flag, posi);
	}

}
//����������ConstDecl
Node* Parser::parse_ConstDecl() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z,k;
	//1.�ж�const����
	if (tokens[i].value == "const") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2.�ж�int����
	if (tokens[i].value == "int") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//3.����������ConstDef
	Node* a = parse_ConstDef();
	//4.�ж϶���
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}
	//5.����������ConstDef
	Node* b = parse_ConstDef();
	//6.�ж�int����
	if (tokens[i].value == ";") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		k = 1;
	}
	else {
		k = 0;
	}

	//�ۺ��ж�
	if (x&&y&& judgval(a)&&k) {
		//������㻨�������ظ�0��
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
		//������㻨�������ظ�1��
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
		//�˴�Ϊ�����㳣������ConstDecl���������
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
//����������ConstDef
Node* Parser::parse_ConstDef() {
	vector<int> flag;
	vector<int> posi;
	bool flg;
	int x, y, z;

	//1.�жϱ�ʶ��
	flg = parse_Ident();
	//2.�ж� [
	if (tokens[i].value == "[") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.�жϳ������ʽ
	Node* a = parse_ConstExp();
	//4.�ж� ]
	if (tokens[i].value == "]") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//5.�ж� =
	if (tokens[i].value == "=") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}
	//6.�ж� ������ֵ
	Node* b = parse_ConstInitVal();

	//�ۺ��ж�
	if (flg&&z&&judgval(b)) {
		//1,5,6���� a=0 ����ͨ����
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
		//1,2,3,4,5,6���� a[0]=1 ��һά����
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
		//�����㳣������ConstDef���������
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
//��������ֵConstInitVal
Node* Parser::parse_ConstInitVal() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z;
	//1.���������ʽConstExp
	Node*a= parse_ConstExp();
	//2.�ж� {
	if (tokens[i].value == "{") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//3.������ֵ
	Node* b = parse_ConstInitVal();
	//4.�ж�,
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	
	//5.������ֵ
	Node* c = parse_ConstInitVal();
	//6.�ж� }
	if (tokens[i].value == "}") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}

	//�ۺ��ж�
	if (judgval(a)&&!x&& !judgval(b)&&!y&& !judgval(c)&&!z) {
		//1,���ֻ�� �������ʽConstExp
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
		//2,3,6 ����{2+3}
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
		//2,3,4,5,6����{2+3,{2+3}};
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
		//���󣬲������
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
//�����������VarDecl
Node* Parser::parse_VarDecl() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z;
	//1.�ж�int
	if (tokens[i].value == "int") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		x = 1;
	}
	else {
		x = 0;
	}
	//2.�����������VarDef
	Node* a = parse_VarDef();
	//3.�ж�,
	if (tokens[i].value == ",") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		y = 1;
	}
	else {
		y = 0;
	}
	//4.�����������VarDef
	Node* b = parse_VarDef();
	//5.�ж�;
	if (tokens[i].value == ";") {
		cout << tokens[i].type << "  " << tokens[i].value << endl;
		i++;
		z = 1;
	}
	else {
		z = 0;
	}

	//�ۺ��ж�
	if (x&& judgval(a)&&z) {
		//1,2,5 ����int a;
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
		//1,2,3,4,5����int a=0,b=1;
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
		//�����⣬�������
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
//�����������VarDef
Node* Parser::parse_VarDef() {
	vector<int> flag;
	vector<int> posi;
	int x, y;
	//1.�����ʶ��
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
	//3.�������ʽparse_ConstExp()
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

	//�ۺ��ж�
	if (flg&&!x&&!judgval(a)&&!y) {
		//1,���� a
		flag.push_back(1);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if (flg && x && judgval(a) &&y) {
		//1,2,3,4���� arry[8]
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
		//���󣬲������
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}

}
//���������ֵInitVal
Node* Parser::parse_InitVal() {
	vector<int> flag;
	vector<int> posi;
	int x, y, z;
	//1.���ʽEXP
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
	//3.������ֵInitVal
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
	//5.������ֵInitVal
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

	//�ۺ��ж�
	if (judgval(a)&&!x&& !judgval(b)&&!y&&!judgval(c)&&!z) {
		//1��ֻ��Exp,����8
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
		//2,3,4,5,6����{3,8}
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
		//2,6����{}
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
		//���󣬲������
		//1��ֻ��Exp,����8
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
//����������FuncDef
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

	//�ۺϷ���
	if (judgval(a)&&flg &&x &&!judgval(b) &&y && c) {
		//1,2,3,5,6 ���� int fun(){}
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
		//1,2,3,4,5,6���� int fun(int a){}
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
		//���󣬲����
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

//��������������MainFuncDef
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

	//�ۺ�
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
		//���󣬲����
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
//����������FuncType
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

	//�ۺ��ж�
	if (x) {
		//��void
		flag.push_back(1);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if (y) {
		//��int
		flag.push_back(0);
		flag.push_back(1);
		posi.push_back(1);
		return new Node(flag, posi);
	}
	else {
		//���󣬲������
		flag.push_back(0);
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}

}
//�������βα�FuncFParams
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


	//�ۺ�
	if (judgval(a)&&!x&&!judgval(b)) {
		//1,���� int a[]
		flag.push_back(1);
		posi.push_back(0);
		return new Node(flag, posi);
	}
	else if(judgval(a) && x && judgval(b)) {
		//1,2,3���� int a[][3]
		flag.push_back(1);
		flag.push_back(1);
		flag.push_back(1);
		posi.push_back(0);
		posi.push_back(1);
		posi.push_back(2);
		return new Node(flag, posi);
	}
	else {
		//���󣬲����
		//1,���� int a[]
		flag.push_back(0);
		posi.push_back(0);
		return new Node(flag, posi);
	}
}
//�������β�FuncFParam
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
	//2. ��ʶ��
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
	//6.�������ʽ
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


	//�ۺ�
	if (x &&flg &&!y&&!z&& !k && !judgval(a)&&!m) {
		//1,2���� int a 
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
		//1,2,3,4 ���� int[]
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
		//1,2,3,4,5,6,7 ���� int[][3]
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
		//���󣬲����
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
//��������Block
Node* Parser::parse_Block() {

}
//����������BlockItem
Node* Parser::parse_BlockItem() {

}
//�������Stmt
Node* Parser::parse_Stmt() {

}
//������ʽExp
Node* Parser::parse_Exp() {

}
//�����������ʽCond
Node* Parser::parse_Cond() {

}
//������ֵ���ʽLVal
Node* Parser::parse_LVal() {

}
//����������ʽPrimaryExp
Node* Parser::parse_PrimaryExp() {

}
//������ֵNumber
Node* Parser::parse_Number() {

}
//����һԪ���ʽUnaryExp
Node* Parser::parse_UnaryExp() {

}
//����Ŀ�����UnaryOp
Node* Parser::parse_UnaryOp() {

}
//������ʵ�α�FuncRParms
Node* Parser::parse_FuncRParms() {

}
//����˳�ģ���ʽMulExp
Node* Parser::parse_MulExp() {

}
//����Ӽ����ʽAddExp
Node* Parser::parse_AddExp() {

}
//�����ϵ���ʽRelExp
Node* Parser::parse_RelExp() {

}
//��������Ա��ʽEqExp
Node* Parser::parse_EqExp() {

}
//�����߼�����ʽLAndExp
Node* Parser::parse_LAndExp() {

}
//�����߼�����ʽLOrExp
Node* Parser::parse_LOrExp() {

}
//���������ʽConstExp
Node* Parser::parse_ConstExp() {

}

//�жϱ�ʶ��Ident
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
//�ж���ֵ����IntConst
bool Parser::parse_IntConst() {

}

//�ж�ȡֵ�Ƿ�����Ҫ��
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

//�������
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