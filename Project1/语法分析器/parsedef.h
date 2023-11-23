#include<iostream>
#include<vector>
#include<regex>
#include<string>
#include<algorithm>
using namespace std;

//语法分析器类
class Parser {
private:
	//获取输入单词的索引
	int i;
	//存储元素个数的索引
	int m;
	vector<pair<string, string>> tokens;
	vector<string> myvec;
	vector<string> myver;

public:

	//构造函数
	Parser(vector<pair<string, string>> tok, int _i, int _m) :tokens(tok), i(_i), m(_m) {}

	//处理编译单parse_CompUnit
	bool parse_CompUnit();
	//处理声明Decl
	bool parse_Decl();
	//处理常量声明ConstDecl
	bool parse_ConstDecl();
	//处理,和ConstDef
	bool parse_douandConstDef();
	//处理常数定义ConstDef
	bool  parse_ConstDef();
	//m
	bool parse_m();
	//处理常量初值ConstInitVal
	bool  parse_ConstInitVal();
	//k
	bool parse_k();
	//p
	bool parse_p();
	//处理变量声明VarDecl
	bool  parse_VarDecl();
	//
	bool parse_h();
	//处理变量定义VarDef
	bool parse_VarDef();
	//
	bool parse_g();

	//处理变量初值InitVal
	bool  parse_InitVal();
	//
	bool parse_f();
	//
	bool parse_s();
	//
	bool parse_d();
	//处理函数定义FuncDef
	bool  parse_FuncDef();
	//处理主函数定义MainFuncDef
	bool  parse_MainFuncDef();
	//处理函数类型FuncType
	bool parse_FuncType();
	//处理函数形参表FuncFParams
	bool  parse_FuncFParams();
	//
	bool parse_t();
	//处理函数形参FuncFParam
	bool  parse_FuncFParam();
	//
	bool parse_r();
	//
	bool  parse_e();

	//处理语句块Block
	bool parse_Block();
	//处理语句块项BlockItem
	bool  parse_BlockItem();
	//处理语句Stmt
	bool parse_Stmt();
	//
	bool parse_w();
	//
	bool parse_v();
	//
	bool parse_x();
	//
	bool parse_te();
	//
	bool parse_C();
	//
	bool parse_as();
	//
	bool parse_hj();
	//
	bool parse_yu();
	//
	bool parse_ty();
	//
	bool parse_cv();
	//
	bool parse_op();
	//
	bool parse_jl();
	//处理表达式Exp
	bool  parse_Exp();
	//处理条件表达式Cond
	bool  parse_Cond();
	//处理左值表达式LVal
	bool  parse_LVal();
	//
	bool parse_fg();
	//处理基本表达式PrimaryExp
	bool parse_PrimaryExp();
	//处理数值Number
	bool  parse_Number();
	//处理一元表达式UnaryExp
	bool  parse_UnaryExp();
	//
	bool parse_er();
	//
	bool parse_vb();
	//处理单目运算符UnaryOp
	bool  parse_UnaryOp();
	//处理函数实参表FuncRParms
	bool  parse_FuncRParms();
	//
	bool parse_se();
	//处理乘除模表达式MulExp
	bool parse_MulExp();
	//
	bool parse_fd();
	//处理加减表达式AddExp
	bool  parse_AddExp();
	//
	bool parse_zx();

	//处理关系表达式RelExp
	bool  parse_RelExp();
	//
	bool  parse_bvg();
	//处理相等性表达式EqExp
	bool  parse_EqExp();
	//
	bool  parse_gfd();
	//
	bool parse_gfy();
	//处理逻辑与表达式LAndExp
	bool  parse_LAndExp();
	//
	bool parse_xcd();
	//
	bool parse_nm();
	//
	bool parse_vfg();
	//
	bool parse_lmn();
	//处理逻辑或表达式LOrExp
	bool  parse_LOrExp();
	//处理常量表达式ConstExp
	bool  parse_ConstExp();
	//判断格式化字符串
	bool isFStrb();
	//判断数值常量IntConst
	bool parse_IntConst();
	//删除索引a(包括a)以后的元素
	void popvec(int a);
	//
	void printl();
	//
	bool parse_hbv();
	//
	bool parse_fdg();
	//
	bool parse_ubfr();
	//
	bool parse_nmbv();
	//
	bool parse_sfhg();
	//
	bool parse_mnbc();
	//
	bool  parse_awer();
	//
	bool parse_uhbvg();
	//
	bool parse_iunm();
	//
	bool parse_bmnu();
	//
	bool parse_mcert();
	//
	bool parse_derwq();
	//
	void inputl();
	//
	bool parse_Identhan();
	//
	bool parse_cder();
	//
	bool parse_ytgh();
};