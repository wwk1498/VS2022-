#include "parsedef.h"

//������뵥parse_CompUnit
bool Parser::parse_CompUnit() {
	bool flg1=true, flg2=true, flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	while (i < tokens.size()&& flg1) {
		//��������Decl
		flg1 = parse_Decl();
		if (flg1) {
			statui = i;
			statum = m;
		}
		else {
			
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
			
		}

	}
	
	
	while (i < tokens.size() && flg2) {
		//����������FuncDef
		flg2 = parse_FuncDef();
		if (flg2) {
			myvec.push_back("< FuncDef>");
			myver.push_back(" ");
			m++;
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
		}
	}
	

	
	
	//��������������MainFuncDef
	 flg3= parse_MainFuncDef();
	 
	if (flg3) {
		myvec.push_back("<MainFuncDef>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//��������Decl
bool Parser::parse_Decl() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	

	//����������ConstDecl
	 flg1 = parse_ConstDecl();
	if (flg1) {
		myvec.push_back("<ConstDecl>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
	}

	//�����������VarDecl
	 flg2 = parse_VarDecl();
	if (flg2) {
		myvec.push_back("<VarDecl>");
		myver.push_back(" ");
		m++;
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}

//����������ConstDecl
bool Parser::parse_ConstDecl() {
	bool flg1, flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1.�ж�const����
	if (i < tokens.size() && tokens[i++].second =="const") {
		myvec.push_back("const");
		myver.push_back("CONSTTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//2.�ж�int����
	if (i < tokens.size() && tokens[i++].second == "int") {
		myvec.push_back("int");
		myver.push_back("INTTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//3.����������ConstDef
	flg1 = parse_ConstDef();
	if (flg1) {
		myvec.push_back("<ConstDef>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	while (i < tokens.size()&& flg2) {
		//4.����,��ConstDef
		flg2 = parse_douandConstDef();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
		}
	}
	
	//5.�жϣ�
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}


//����,��ConstDef
bool Parser::parse_douandConstDef() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//4.�ж϶���
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//5.����������ConstDef
	flg1 = parse_ConstDef();
	if(flg1){
		myvec.push_back("<ConstDef>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}
//////////////////////////////////////////////////////////////������ȷ

//����������ConstDef
bool Parser::parse_ConstDef() {
	bool flg1,flg2=true,flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1.�жϱ�ʶ��
	flg1 = parse_Identhan();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	

	while (i < tokens.size()&& flg2) {
		//�ж� [ConstExp]
		flg2 = parse_m();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
		}
	}
	
	//5.�ж� =
	if (i < tokens.size() && tokens[i++].second == "=") {
		myvec.push_back("=");
		myver.push_back("ASSIGN");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	

	//6.�ж� ������ֵ
	flg3 = parse_ConstInitVal();
	if (flg3) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	
}
bool Parser::parse_m() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//2.�ж� [
	if (i < tokens.size() && tokens[i++].second == "[") {
		myvec.push_back("]");
		myver.push_back("RBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}


	//3.�жϳ������ʽ
	flg1 = parse_ConstExp();
	if (flg1) {
		myvec.push_back("<ConstExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//4.�ж� ]
	if (i < tokens.size() && tokens[i++].second == "]") {
		myvec.push_back("]");
		myver.push_back("RBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}



//��������ֵConstInitVal
bool Parser::parse_ConstInitVal() {

	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.���������ʽConstExp
	flg1 = parse_ConstExp();
	if (flg1) {
		myvec.push_back("<ConstExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
	}

	//k
	flg2 = parse_k();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

bool Parser::parse_k() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//2.�ж� {
	if (i < tokens.size() && tokens[i++].second == "{") {
		myvec.push_back("}");
		myver.push_back("RBRACE");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//
	flg2 = parse_ytgh();
	if (flg2) {
		statui = i;
		statum = m;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
	}
	

	//6.�ж� }
	if (i < tokens.size() && tokens[i++].second == "}") {
		myvec.push_back("}");
		myver.push_back("RBRACE");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

bool Parser::parse_ytgh() {
	bool flg1,flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//3.������ֵ
	flg1 = parse_ConstInitVal();
	if (flg1) {
		myvec.push_back("<ConstInitVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);

		return false;
	}

	while (i < tokens.size() && flg2) {
		//
		flg2 = parse_p();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			return true;
		}
	}

}


bool Parser::parse_p() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//4.�ж�,
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//5.������ֵ
	flg1 = parse_ConstInitVal();
	if (flg1) {
		myvec.push_back("<ConstInitVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//////////////////////////////////////
//�����������VarDecl
bool Parser::parse_VarDecl() {
	bool flg1,flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.�ж�int
	if (i < tokens.size() && tokens[i++].second == "int") {
		myvec.push_back("int");
		myver.push_back("INTTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	

	//2.�����������VarDef
	 flg1= parse_VarDef();
	 if (flg1) {
		 
		 myvec.push_back("<VarDef>");
		 myver.push_back(" ");
		 m++;
		 statui = i;
		 statum = m;

	 }
	 else {
		 i = starti;
		 m = startm;
		 //ɾ������statum(����statum)�Ժ��Ԫ��
		 popvec(startm);
		 
		 return false;
	 }
	 
	 while (i < tokens.size()&& flg2) {
		 //3
		 flg2 = parse_h();
		 if (flg2) {
			 statui = i;
			 statum = m;

		 }
		 else {

			 i = statui;
			 m = statum;
			 //ɾ������statum(����statum)�Ժ��Ԫ��
			 popvec(statum);
			 
		 }
	 }
	 

	//4.�ж�;
	 
	 if (i<tokens.size()&&tokens[i++].second == ";") {
		 myvec.push_back(";");
		 myver.push_back("SEMICN");
		 m++;
		 statui = i;
		 statum = m;
		 return true;
	 }
	 else {
		 i = starti;
		 m = startm;
		 //ɾ������statum(����statum)�Ժ��Ԫ��
		 popvec(startm);
		 
		 return false;
	 }

	
}

//
bool Parser::parse_h() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//3.�ж�,
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;

		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//4.�����������VarDef
	flg1= parse_VarDef();

	if (flg1) {
		myvec.push_back("<VarDef>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//////////////////////////////////////////
//�����������VarDef
bool Parser::parse_VarDef() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_vfg();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2
	flg2 = parse_lmn();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}
	

}

bool Parser::parse_vfg() {
	bool flg1, flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.�����ʶ��
	flg1 = parse_Identhan();
	if (flg1) {
		statui = i;
		statum = m;

	}
	else {

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	while (i < tokens.size()&& flg2) {
		//2
		flg2 = parse_g();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {

			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
			return true;
		}
	}
	
}

//
bool Parser::parse_lmn() {
	bool flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	//=
	if (i < tokens.size() && tokens[i++].second == "=") {
		myvec.push_back("=");
		myver.push_back("ASSIGN");
		m++;
		statui = i;
		statum = m;
	}
	else {

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//InitVal()
	flg2 = parse_InitVal();
	if (flg2) {
		myvec.push_back("<InitVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}


}

//
bool Parser::parse_g() {

	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//2. [
	if (i < tokens.size() && tokens[i++].second == "[") {
		myvec.push_back("[");
		myver.push_back("LBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3.�������ʽparse_ConstExp()
	flg1= parse_ConstExp();
	if (flg1) {
		myvec.push_back("<ConstExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//4.]
	if (i < tokens.size() && tokens[i++].second == "]") {
		myvec.push_back("]");
		myver.push_back("RBRACK");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}



/////////////////////////////////

//���������ֵInitVal
bool Parser::parse_InitVal() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.���ʽEXP
	flg1 = parse_Exp();
	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//2.
	flg2 = parse_f();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}



//
bool Parser::parse_f() {

	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//2.  {
	if (i < tokens.size() && tokens[i++].second == "{") {
		myvec.push_back("{");
		myver.push_back("LBRACE");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//
	flg1 = parse_s();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
	}

	//6.  }
	if (i < tokens.size() && tokens[i++].second == "}") {
		myvec.push_back("}");
		myver.push_back("RBRACE");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}
}

bool Parser::parse_s() {

	bool flg1, flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//3.������ֵInitVal
	flg1 = parse_InitVal();
	if (flg1) {
		myvec.push_back("<InitVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	while (i < tokens.size()&& flg2) {
		//
		flg2 = parse_d();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
			return true;
		}
	}
	
	

}

bool Parser::parse_d() {

	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//4.   ,
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//5.������ֵInitVal
	flg1 = parse_InitVal();
	if (flg1) {
		myvec.push_back("<InitVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}

}

////////////////////////////////////////


//����������FuncDef
bool Parser::parse_FuncDef() {
	bool flg1, flg2,flg3,flg4;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//1.  FuncType
	flg1= parse_FuncType();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	

	//2.  Ident
	flg2 = parse_Identhan();
	if (flg2) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}


	//3.  (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	//4.  FuncFParams
	flg3= parse_FuncFParams();
	if (flg3) {
		myvec.push_back("<FuncFParams>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
	}
	


	//5.  )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	

	//6. Block 
	 flg4= parse_Block();
	 if (flg4) {
		 myvec.push_back("<Block>");
		 myver.push_back(" ");
		 m++;
		 statui = i;
		 statum = m;


		 return true;
	 }
	 else {
		 i = starti;
		 m = startm;
		 //ɾ������statum(����statum)�Ժ��Ԫ��
		 popvec(startm);
		 
		 return false;
	 }

	
}
//////////////////////////////////

//��������������MainFuncDef
bool Parser::parse_MainFuncDef() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.  int 
	if (i < tokens.size() && tokens[i++].second == "int") {
		myvec.push_back("int");
		myver.push_back("INTTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2.   main
	if (i < tokens.size() && tokens[i++].second == "main") {
		myvec.push_back("main");
		myver.push_back("MAINTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3.  (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//4.  )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	

	//5.  block
	flg1= parse_Block();
	
	if (flg1) {
		myvec.push_back("<Block>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}
//////////////////////////////

//����������FuncType
bool Parser::parse_FuncType() {
	
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	

	//1.void
	if (i < tokens.size() && tokens[i++].second == "void") {
		myvec.push_back("void");
		myver.push_back("VOIDTK");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	
	//2.int
	if (i < tokens.size() && tokens[i++].second == "int") {
		myvec.push_back("int");
		myver.push_back("INTTK");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	
}
//////////////////


//�������βα�FuncFParams
bool Parser::parse_FuncFParams() {
	bool flg1,flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//1.FuncFParam
	flg1= parse_FuncFParam();
	if (flg1) {
		myvec.push_back("<FuncFParam>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	while (i < tokens.size()&& flg2) {
		//2
		flg2 = parse_t();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
			return true;
		}
	}
	
}

//
bool Parser::parse_t() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//2.  ,
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3.FuncFParam
	flg1= parse_FuncFParam();
	if (flg1) {
		myvec.push_back("<FuncFParam>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
/////////////////////////////

//�������β�FuncFParam
bool Parser::parse_FuncFParam() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1. int 
	if (i < tokens.size() && tokens[i++].second == "int") {
		myvec.push_back("int");
		myver.push_back("INTTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2. ��ʶ��
	flg1 = parse_Identhan();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3
	flg2=parse_r();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}


}


bool Parser::parse_r() {
	bool flg1=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	// 3. [
	if (i < tokens.size() && tokens[i++].second == "[") {
		myvec.push_back("[");
		myver.push_back("LBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//4. ]
	if (i < tokens.size() && tokens[i++].second == "]") {
		myvec.push_back("]");
		myver.push_back("RBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	while (i < tokens.size()&& flg1) {
		//
		flg1 = parse_e();
		if (flg1) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
			return true;
		}
	}
	
}

//
bool Parser::parse_e() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//5. [
	if (i < tokens.size() && tokens[i++].second == "[") {
		myvec.push_back("[");
		myver.push_back("LBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//6.�������ʽ
	flg1 = parse_ConstExp();
	if (flg1) {
		myvec.push_back("<ConstExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//7. ]
	if (i < tokens.size() && tokens[i++].second == "]") {
		myvec.push_back("]");
		myver.push_back("RBRACK");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}
//////////////////////

//��������Block
bool Parser::parse_Block() {
	bool flg1=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.  {
	if (i < tokens.size() && tokens[i++].second == "{") {
		myvec.push_back("{");
		myver.push_back("LBRACE");
		m++;
		statui = i;
		statum = m;
		
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	
	//2.  BlockItem
	while (i < tokens.size() && flg1) {
		flg1 = parse_BlockItem();
		if (flg1) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
		}
	}
	
	//3.  }
	if (i < tokens.size() && tokens[i++].second == "}") {
		myvec.push_back("}");
		myver.push_back("RBRACE");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

////////////////////

//����������BlockItem
bool Parser::parse_BlockItem() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1. Decl
	flg1= parse_Decl();
	
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	

	//2. Stmt
	flg2= parse_Stmt();
	
	if (flg2) {
		myvec.push_back("<Stmt>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}

//////////////////////

//�������Stmt
bool Parser::parse_Stmt() {

	bool flg1, flg2, flg3, flg4, flg5, flg6, flg7, flg8, flg9;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	
	//1
	flg1=parse_w();
	
	if (flg1) {
		
		statui = i;
		statum = m;
		
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	

	//
	flg2 = parse_v();
	
	if (flg2) {
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	

	//7. block
	flg3= parse_Block();
	if (flg3) {
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//
	flg4= parse_x();
	if (flg4) {
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//
	flg5 = parse_C();
	if (flg5) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//
	flg6 = parse_as();
	if (flg6) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//
	flg7 = parse_hj();
	if (flg7) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	

	//
	flg8 = parse_yu();
	if (flg8) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}

	//
	flg9 = parse_ty();
	if (flg9) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}

bool Parser::parse_w() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//1. Lval
	flg1= parse_LVal();
	if (flg1) {
		myvec.push_back("<LVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	//2.  x1  =
	if (i < tokens.size() && tokens[i++].second == "=") {
		myvec.push_back("=");
		myver.push_back("ASSIGN");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	

	//3. EXP
	flg2= parse_Exp();
	

	if (flg2) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//4.  x2  ;
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
//
bool Parser::parse_v() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	

	//5. Exp
	flg1= parse_Exp();

	

	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
	}
	
	//6.  x3 ;
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
//
bool Parser::parse_x() {
	bool flg1, flg2, flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//8.  x4 if
	if (i < tokens.size() && tokens[i++].second == "if") {
		myvec.push_back("if");
		myver.push_back("IFTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	

	//9.  x5 (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
		
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	


	//10. cond
	flg1= parse_Cond();
	if (flg1) {
		myvec.push_back("<Cond>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//11.  x6  )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//12.  stmt
	flg2= parse_Stmt();
	if (flg2) {
		myvec.push_back("<Stmt>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	//
	flg3=parse_te();
	if (flg3) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}

}

//
bool Parser::parse_te() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//13.  x7 else
	if (i < tokens.size() && tokens[i++].second == "else") {
		myvec.push_back("else");
		myver.push_back("ELSETK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//14.  stmt
	flg1= parse_Stmt();
	if (flg1) {
		myvec.push_back("<Stmt>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

bool Parser::parse_C() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//15.  x8 while
	if (i < tokens.size() && tokens[i++].second == "while") {
		myvec.push_back("while");
		myver.push_back("WHILETK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//16.  x9 (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//17. cond
	flg1= parse_Cond();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//18.  x10 )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//19.  stmt
	flg2 = parse_Stmt();
	if (flg2) {
		myvec.push_back("<Stmt>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
//
bool Parser::parse_as() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1.
	flg1 = parse_op();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}

	//2.
	flg2 = parse_jl();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	
}

bool Parser::parse_op() {
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//20. x11 break
	if (i < tokens.size() && tokens[i++].second == "break") {
		myvec.push_back("break");
		myver.push_back("BREAKTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//21.  x12 ;
	if (i < tokens.size() && tokens[i++].second == "return") {
		myvec.push_back("return");
		myver.push_back("RETURNTK");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
//
bool Parser::parse_jl() {

	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//22.  x13 continue
	if (i < tokens.size() && tokens[i++].second == "continue") {
		myvec.push_back("continue");
		myver.push_back("CONTINUETK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//23.  x14 ;
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

//
bool Parser::parse_hj() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//24.  x15 return 
	if (i < tokens.size() && tokens[i++].second == "return") {
		myvec.push_back("return");
		myver.push_back("RETURNTK");
		m++;
		statui = i;
		statum = m;
		
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	

	//25.  EXP
	flg1= parse_Exp();
	
	if (flg1) {
		
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
	}
	//26. x16 ;
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

//
bool Parser::parse_yu() {

	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//27. Lval
	flg1 = parse_LVal();
	if (flg1) {
		myvec.push_back("<LVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//28. x17 =
	if (i < tokens.size() && tokens[i++].second == "=") {
		myvec.push_back("=");
		myver.push_back("ASSIGN");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//29. x18 getint
	if (i < tokens.size() && tokens[i++].second == "getint") {
		myvec.push_back("getint");
		myver.push_back("GETINTTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//30. x19 (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//31. x20 )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//32. x21 ;
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//
bool Parser::parse_ty() {
	bool flg1, flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//33. x22 printf
	if (i < tokens.size() && tokens[i++].second == "printf") {
		myvec.push_back("printf");
		myver.push_back("PRINTFTK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//34. x23 (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//35.  FormatString ��ʽ���ַ���
    flg1 = isFStrb();
	if (flg1) {
		myvec.push_back("<FormatString>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return true;
	}
	while (i < tokens.size()&& flg2) {
		//
		flg2 = parse_cv();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
		}
	}
	
	//38.  x25 )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//39.  x26 ;
	if (i < tokens.size() && tokens[i++].second == ";") {
		myvec.push_back(";");
		myver.push_back("SEMICN");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}
//
bool Parser::parse_cv() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//36.  x24 ,
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//37.  EXP
	flg1= parse_Exp();
	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

/////////////////////////////////////

//������ʽExp
bool Parser::parse_Exp() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1.�Ӽ����ʽ
	flg1= parse_AddExp();
	
	if (flg1) {
		myvec.push_back("<AddExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		
		return false;
	}
}
//�����������ʽCond
bool Parser::parse_Cond() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1.�߼�����ʽ
	flg1= parse_LOrExp();
	if (flg1) {
		myvec.push_back("<LOrExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}
//������ֵ���ʽLVal
bool Parser::parse_LVal() {
	bool flg1, flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	
	//1.��ʶ��
	flg1 = parse_Identhan();

	if (flg1) {
		
		statui = i;
		statum = m;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	while (i < tokens.size()&& flg2) {
		//2
		flg2 = parse_fg();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {

			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			
			return true;
		}
	}
	
	
}

bool Parser::parse_fg() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//2.[
	if (i < tokens.size() && tokens[i++].second == "[") {
		myvec.push_back("[");
		myver.push_back("LBRACK");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3.Exp
	flg1=parse_Exp();
	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//4.]
	if (i < tokens.size() && tokens[i++].second == "]") {
		myvec.push_back("]");
		myver.push_back("RBRACK");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
///////////////////////////////////////////

//����������ʽPrimaryExp
bool Parser::parse_PrimaryExp() {
	bool flg1,flg2,flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//
	flg1 = parse_cder();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	
	
	//4 Lval
	flg2 = parse_LVal();
	
	if (flg2) {
		myvec.push_back("<LVal>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//5 Number
	flg3 = parse_Number();
	if (flg3) {
		myvec.push_back("<Number>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}else {
		

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//
bool Parser::parse_cder() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1 (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		
		return false;
	}
	//2 Exp
	flg1 = parse_Exp();
	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3 )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
}


//������ֵNumber
bool Parser::parse_Number() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//
	flg1=parse_IntConst();
	if (flg1) {
		myvec.push_back("<IntConst>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
//����һԪ���ʽUnaryExp
bool Parser::parse_UnaryExp() {
	bool flg1,flg2,flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	
	//2
	flg2 = parse_er();
	
	if (flg2) {
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
	}

	//1
	flg1 = parse_PrimaryExp();
	if (flg1) {
		myvec.push_back("<PrimaryExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
	}

	//3
	flg3 = parse_vb();
	
	if (flg3) {
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

//
bool Parser::parse_er() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1 ident
	flg1 = parse_Identhan();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2 (
	if (i < tokens.size() && tokens[i++].second == "(") {
		myvec.push_back("(");
		myver.push_back("LPARENT");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3 FuncRParams
	flg2 = parse_FuncRParms();
	if (flg2) {
		myvec.push_back("<FuncRParms>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
	}
	//4 )
	if (i < tokens.size() && tokens[i++].second == ")") {
		myvec.push_back(")");
		myver.push_back("RPARENT");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}


//
bool Parser::parse_vb() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1
	flg1=parse_UnaryOp();
	if (flg1) {
		myvec.push_back("<UnaryOp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//2
	flg2 = parse_UnaryExp();
	if (flg2) {
		myvec.push_back("<UnaryExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//����Ŀ�����UnaryOp
bool Parser::parse_UnaryOp() {
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//
	if (i >= tokens.size()) {
		return false;
	}
	string str = tokens[i++].second;
	if (str =="+" or str == "-" or str == "!") {
		myvec.push_back(str);
		if (str == "+") {
			myver.push_back("PLUS");
		}
		else if (str == "-") {
			myver.push_back("MINU");
		}
		else {
			myver.push_back("NOT");
		}
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}
//������ʵ�α�FuncRParms
bool Parser::parse_FuncRParms() {

	bool flg1, flg2=true;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_Exp();
	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	while (i < tokens.size()&& flg2) {
		//2
		flg2 = parse_se();
		if (flg2) {
			statui = i;
			statum = m;
		}
		else {
			i = statui;
			m = statum;
			//ɾ������statum(����statum)�Ժ��Ԫ��
			popvec(statum);
			return true;;
		}
	}
	

}

//
bool Parser::parse_se() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	// ,
	if (i < tokens.size() && tokens[i++].second == ",") {
		myvec.push_back(",");
		myver.push_back("COMMA");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2 Exp
	flg1 = parse_Exp();
	if (flg1) {
		myvec.push_back("<Exp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}



//����˳�ģ���ʽMulExp
bool Parser::parse_MulExp() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1   UnaryExp
	flg1 = parse_UnaryExp();
	
	if (flg1) {
		
		myvec.push_back("<UnaryExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}


	//2 p'
	flg2 = parse_hbv();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		return true;
	}
}

//p'
bool Parser::parse_hbv() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1
	flg1 = parse_fdg();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//2 ��
	if (i < tokens.size() && tokens[i++].second == "") {
		statui = i;
		statum = m;
		return true;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}


bool Parser::parse_fdg() {
	bool flg1,flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	//1
	flg1 = parse_fd();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);

		return false;
	}
	//2
	flg3 = parse_hbv();
	if (flg3) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}
	

}

//
bool Parser::parse_fd() {
	bool flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	
	
	//2
	if (i >= tokens.size()) {
		return false;
	}
	string str = tokens[i++].second;
	if (str == "*" or str == "/" or str=="%") {
		myvec.push_back(str);
		if (str=="*") {
			myver.push_back("MULT");
		}
		else if (str == "/") {
			myver.push_back("DIV");
		}
		else {
			myver.push_back("MOD");
		}
		m++;
		statui = i;
		statum = m;
	}
	else {
		
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3
	flg3 = parse_UnaryExp();
	if (flg3) {
		myvec.push_back("<UnaryExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}


//����Ӽ����ʽAddExp
bool Parser::parse_AddExp() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_MulExp();
	
	if (flg1) {
		
		myvec.push_back("<MulExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}
	
	//2
	flg2 = parse_ubfr();
	if (flg2) {
		
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}
	
}


//p'
bool Parser::parse_ubfr() {

	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_nmbv();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//2 ��
	if (i < tokens.size() && tokens[i++].second == "") {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

bool Parser::parse_nmbv() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_zx();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2
	flg2 = parse_ubfr();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		return true;
	}
}


//
bool Parser::parse_zx() {
	bool flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	
	//2
	if (i >= tokens.size()) {
		return false;
	}
	string str = tokens[i++].second;
	if (str == "+" or str == "-") {
		myvec.push_back(str);
		if (str == "+") {
			myver.push_back("PLUS");
		}
		else {
			myver.push_back("MINU");
		}
		m++;
		
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3
	flg3 = parse_MulExp();
	
	if (flg3) {
		
		myvec.push_back("<MulExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}


//�����ϵ���ʽRelExp
bool  Parser::parse_RelExp() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_AddExp();
	if (flg1) {
		myvec.push_back("<AddExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}
	//2
	flg2 = parse_sfhg();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		return true;
	}

}
//p'
bool Parser::parse_sfhg() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	//1
	flg1 = parse_mnbc();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//2 kong
	if (i < tokens.size() && tokens[i++].second == "") {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//
bool Parser::parse_mnbc() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1=parse_bvg();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

	//2
	flg2 = parse_sfhg();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}
}

bool  Parser::parse_bvg() {
	bool flg3;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	
	//2
	if (i >= tokens.size()) {
		return false;
	}
	string str = tokens[i++].second;
	if (str == "<" or str == ">" or str =="<=" or str ==">=") {
		myvec.push_back(str);
		if (str == "<") {
			myver.push_back("LSS");
		}
		else if (str == ">") {
			myver.push_back("GRE");
		}
		else if (str == "<=") {
			myver.push_back("LEQ");
		}
		else {
			myver.push_back("GEQ");
		}
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
	//3
	flg3 = parse_AddExp();
	if (flg3) {
		myvec.push_back("<AddExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}



//��������Ա��ʽEqExp
bool Parser::parse_EqExp() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_RelExp();
	if (flg1) {
		myvec.push_back("<RelExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}
	//2
	flg2 = parse_awer();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}

}
//p'
bool  Parser::parse_awer() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	//1
	flg1 = parse_uhbvg();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//kong
	if (i < tokens.size() && tokens[i++].second == "") {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}
//
bool Parser::parse_uhbvg() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_gfd();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2
	flg2 = parse_awer();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}
}


//
bool  Parser::parse_gfd() {
	bool flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	
	//2 
	if (i >= tokens.size()) {
		return false;
	}
	string str = tokens[i++].second;
	if ( str == "==" or str =="!=") {
		myvec.push_back(str);
		if (str == "=="){
			myver.push_back("EQL");
		}
		else {
			myver.push_back("NEQ");
		}
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3
	flg2 = parse_RelExp();
	if (flg2) {
		myvec.push_back("<RelExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}


//�����߼�����ʽLAndExp
bool Parser::parse_LAndExp() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_EqExp();
	if (flg1) {
		myvec.push_back("<EqExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		return false;
	}

	//2
	flg2 = parse_iunm();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		return true;
	}
}
//p'
bool Parser::parse_iunm() {

	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_bmnu();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//2 kong
	if (i < tokens.size() && tokens[i++].second == "") {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

//
bool Parser::parse_bmnu() {
	bool flg1,flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//1
	flg1 = parse_xcd();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2
	flg2 = parse_iunm();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}
}

//
bool Parser::parse_xcd() {
	bool flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	
	//2
	if (i < tokens.size() && tokens[i++].second == "&&") {
		myvec.push_back("&&");
		myver.push_back("AND");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3
	flg2 = parse_EqExp();
	if (flg2) {
		myvec.push_back("<EqExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

//�����߼�����ʽLOrExp
bool  Parser::parse_LOrExp() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//1
	flg1 = parse_LAndExp();
	if (flg1) {
		myvec.push_back("<LAndExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		

		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		return false;
	}

	//2
	flg2 = parse_mcert();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}

}
//p'
bool  Parser::parse_mcert() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;
	//1
	flg1 = parse_derwq();
	if (flg1) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
	//2 kong
	if (i < tokens.size() && tokens[i++].second == "") {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}
bool Parser::parse_derwq() {
	bool flg1, flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;


	//1
	flg1 = parse_nm();
	if (flg1) {
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//2 
	flg2 = parse_mcert();
	if (flg2) {
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = statui;
		m = statum;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(statum);
		
		return true;
	}

}
//
bool Parser::parse_nm() {

	bool flg2;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//2 ||
	if (i < tokens.size() && tokens[i++].second == "||") {
		myvec.push_back("||");
		myver.push_back("OR");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	//3
	flg2 = parse_LAndExp();
	if (flg2) {
		myvec.push_back("<LAndExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

//���������ʽConstExp
bool Parser::parse_ConstExp() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//
	flg1 = parse_AddExp();
	if (flg1) {
		myvec.push_back("<AddExp>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}

}

//�ж��ַ��������Ǹ�ʽ���ַ���
bool Parser::isFStrb() {
	if (i >= tokens.size()) {
		return false;
	}

	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	string str = tokens[i++].second;
	regex pg("\"(?:([^\"]*)|%d(?:(?!\\B)|.*(?!$)))\"");
	if (regex_match(str, pg)) {
		myvec.push_back(str);
		myver.push_back("STRCON");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
	
}

//�ж���ֵ����IntConst
bool Parser::parse_IntConst() {
	if (i >= tokens.size()) {
		return false;
	}
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	

	string str = tokens[i++].second;
	regex mg("\\d+");
	if (regex_match(str, mg)) {
		myvec.push_back(str);
		myver.push_back("INTCON");
		m++;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}


//ɾ������a(����a)�Ժ��Ԫ��
void Parser::popvec(int a) {
	myvec.erase(myvec.begin() + a, myvec.end());
	myver.erase(myver.begin() + a, myver.end());
}

//
void Parser::printl() {
	
	//cout << myvec.size() << " " << myver.size() << " " << m << endl;
	for (int index = 0; index <myvec.size(); index++) {
		string str1 = myvec[index];
		string str2 = myver[index];
		if (str1 == "<") {
			cout << myver[index]<<"  ";
			cout << myvec[index] << endl;
			continue;
		}
		if (str1[0]!='<') {
			cout << myver[index] << "  ";
		}
		cout << myvec[index] << endl;
	}
}

void Parser::inputl() {
	bool flg1;
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	//
	flg1=parse_CompUnit();
	if (flg1) {
		myvec.push_back("<CompUnit>");
		myver.push_back(" ");
		m++;
		statui = i;
		statum = m;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
	}
}

//
bool Parser::parse_Identhan() {
	if (i >= tokens.size()) {
		return false;
	}
	int starti = i;
	int startm = m;
	int statui = i;
	int statum = m;

	string str = tokens[i++].second;
	regex mg("^[a-zA-Z_][a-zA-Z0-9_]*$");
	if (regex_match(str, mg)&&str!="main"&&str!="getint"&&str!="printf"&&str!="return"&&str!="break"&&str!="continue"&&str!="while"&&str!="if"&&str!="else"&&str!="const") {
		myvec.push_back(str);
		myver.push_back("IDENFR");
		m++;
		statui = i;
		statum = m;
		return true;
	}
	else {
		i = starti;
		m = startm;
		//ɾ������statum(����statum)�Ժ��Ԫ��
		popvec(startm);
		
		return false;
	}
}

