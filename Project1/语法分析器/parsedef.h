#include<iostream>
#include<vector>
#include<regex>
#include<string>
#include<algorithm>
using namespace std;

//�﷨��������
class Parser {
private:
	//��ȡ���뵥�ʵ�����
	int i;
	//�洢Ԫ�ظ���������
	int m;
	vector<pair<string, string>> tokens;
	vector<string> myvec;
	vector<string> myver;

public:

	//���캯��
	Parser(vector<pair<string, string>> tok, int _i, int _m) :tokens(tok), i(_i), m(_m) {}

	//������뵥parse_CompUnit
	bool parse_CompUnit();
	//��������Decl
	bool parse_Decl();
	//����������ConstDecl
	bool parse_ConstDecl();
	//����,��ConstDef
	bool parse_douandConstDef();
	//����������ConstDef
	bool  parse_ConstDef();
	//m
	bool parse_m();
	//��������ֵConstInitVal
	bool  parse_ConstInitVal();
	//k
	bool parse_k();
	//p
	bool parse_p();
	//�����������VarDecl
	bool  parse_VarDecl();
	//
	bool parse_h();
	//�����������VarDef
	bool parse_VarDef();
	//
	bool parse_g();

	//���������ֵInitVal
	bool  parse_InitVal();
	//
	bool parse_f();
	//
	bool parse_s();
	//
	bool parse_d();
	//����������FuncDef
	bool  parse_FuncDef();
	//��������������MainFuncDef
	bool  parse_MainFuncDef();
	//����������FuncType
	bool parse_FuncType();
	//�������βα�FuncFParams
	bool  parse_FuncFParams();
	//
	bool parse_t();
	//�������β�FuncFParam
	bool  parse_FuncFParam();
	//
	bool parse_r();
	//
	bool  parse_e();

	//��������Block
	bool parse_Block();
	//����������BlockItem
	bool  parse_BlockItem();
	//�������Stmt
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
	//������ʽExp
	bool  parse_Exp();
	//�����������ʽCond
	bool  parse_Cond();
	//������ֵ���ʽLVal
	bool  parse_LVal();
	//
	bool parse_fg();
	//����������ʽPrimaryExp
	bool parse_PrimaryExp();
	//������ֵNumber
	bool  parse_Number();
	//����һԪ���ʽUnaryExp
	bool  parse_UnaryExp();
	//
	bool parse_er();
	//
	bool parse_vb();
	//����Ŀ�����UnaryOp
	bool  parse_UnaryOp();
	//������ʵ�α�FuncRParms
	bool  parse_FuncRParms();
	//
	bool parse_se();
	//����˳�ģ���ʽMulExp
	bool parse_MulExp();
	//
	bool parse_fd();
	//����Ӽ����ʽAddExp
	bool  parse_AddExp();
	//
	bool parse_zx();

	//�����ϵ���ʽRelExp
	bool  parse_RelExp();
	//
	bool  parse_bvg();
	//��������Ա��ʽEqExp
	bool  parse_EqExp();
	//
	bool  parse_gfd();
	//
	bool parse_gfy();
	//�����߼�����ʽLAndExp
	bool  parse_LAndExp();
	//
	bool parse_xcd();
	//
	bool parse_nm();
	//
	bool parse_vfg();
	//
	bool parse_lmn();
	//�����߼�����ʽLOrExp
	bool  parse_LOrExp();
	//���������ʽConstExp
	bool  parse_ConstExp();
	//�жϸ�ʽ���ַ���
	bool isFStrb();
	//�ж���ֵ����IntConst
	bool parse_IntConst();
	//ɾ������a(����a)�Ժ��Ԫ��
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