#include<iostream>
using namespace std;
void test() {
	string str="wwwww";
	cout << str << endl;
	const char* str1 = "yyyyyy";
	string  str2(str1);
	string  str3(str2);
	string str4(10, 't');
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
}

void test01() {
	string st = "qqqq";
	string sw = st;
	string sq;
	sq = 'f';
	string s5;
	s5.assign("pppuyy");
	string s6;
	s6.assign("qwertr", 5);
	string s7;
	s7.assign(8,'p');
	cout << st << endl;
	cout << sw<< endl;
	cout << sq << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
}
void test02() {
	string str = "w";
	str += "tre";
	str += ":";
	str += "LL";
	cout << str << endl;
	string sp = "I";
	sp.append("tty");
	sp.append("qqqqqqqqqqqqq", 4);
	//sp.append(str);
	sp.append(str,0,3);
	cout << sp << endl;
}
void test03() {
	string sj = "qwedrtyed";
	int sv=sj.find("ed");
	int sg = sj.rfind("ed");
	cout << sv << endl;
	cout << sg << endl;
}
void test04() {
	string xc = "abcdefgh";
	xc.replace(1, 4, "77777");
	cout << xc << endl;
}
void test05() {
	string as = "qbcd";
	string fg = "qrcd";
	if (as.compare(fg) == 0) {
		cout << "00" << endl;
	}
	else if (as.compare(fg)>0) {
		cout << "1>0" << endl;
	}
	else if (as.compare(fg) < 0) {
		cout << "0<1" << endl;
	}
}

void test06() {

	string sa = "uytgh";
	for (int i = 0; i < sa.size(); i++) {
		cout << sa[i] << " ";
		cout << sa.at(i)<< " ";
	}
	sa[1] = 'p';
	cout << sa << endl;
}

void test07() {
	string p = "xcsert";
	p.insert(1, "999");//²åÈë
	cout << p << endl;
	string b = "puhgtre";
	b.erase(1, 3);//É¾³ý
	cout << b << endl;
	string x = "rewdcgt";
	string df = x.substr(1, 3);//½ØÈ¡
	cout << df << endl;
}

void test08() {
	string k = "wwkwwk@123.com";
	int ind = k.find('@');
	string f = k.substr(0, ind);
	cout << f << endl;
}
int main() {
	test08();

	system("pause");
	return 0;
}