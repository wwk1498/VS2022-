#include <bits/stdc++.h>
using namespace std;

#define all(X) X.begin(),X.end() 
#define CFG_FILE "./config"

typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
typedef pair<char, char> pcc;
typedef pair<char, int> pci;
typedef vector<string> vecs;
typedef vector<char> vecc;
typedef vector<struct Pro> vecP;

struct Pro
{
	string expr; 		/* 产生式 */
	int pos;			/* 项目分隔符的位置，最初从右部的前面一个位置开始，最左边是产生式的左部 */
	string ahead;		/* 向前搜索符 */
	bool operator < (const Pro x) const
	{
		if (expr != x.expr) {
			return expr < x.expr;
		}
		else {
			if (pos != x.pos) {
				return pos < x.pos;
			}
			else {
				return ahead < x.ahead;
			}
		}
	}
	bool operator == (const Pro x) const
	{
		if (expr == x.expr && pos == x.pos && ahead == x.ahead) return true;
		return false;
	}
};

class LR1
{
public:
	char Start;						/* 起始符 */
	unordered_set<char> VtSet;		/* 终结符集 */
	vector<char> VnSet;				/* 非终结符集,遍历比较方便 */
	vector<string> Productions;		/* 产生式 */
	vector<vector<pair<int, char> > > DFA;		/* DFA */
	vector<vector<pair<char, int> > > Action;	/* Action表 */
	vector<vector<pair<char, int> > > Goto;		/* Goto表 */
	map<char, string> First;					/* 每个非终结符的First集的集合 */
	map<string, char> Dic;						/* 词典 */
	int error_t;								/* 错误次数，避免"发生了错误最后Acc"以及"缺少#的报错"的情况*/

	void generate_FirstSet();					/* 产生每一个非终结符的First集合 */
	bool contains(string a, string b);			/* 串b中的字符是否都在串a中出现 */
	string generate_ahead(string remaider, string ahead);	/* 产生向前搜索符 */

	void input(string File);						/* 处理输入的文法和词典 */
	void analysis(string FileIn,string FileOut);	/* 根据输入的三元组进行分析 */
	void build_DFA();								/* 构造DFA转换 */
	void build_table(vector<vecP>& Collections);	/* 建表 */
	void enclosure(vecP& C);						/* 求项目集 */
	void report(int r, stack<int> state, stack<char> sign, string FileOut);

	string stack_2_string(stack<int> state);	/* 将状态栈从栈底到栈顶以字符串的形式返回 */
	string stack_2_string1(stack<char> sign);	/* 将符号栈从栈底到栈顶以字符串的形式返回 */
};

int main()
{
	string in = "2NF grammar.txt",
		s = "lexer_product.txt",
		out = "grammer_product.txt";
	LR1 a;
	a.input(in);
	a.build_DFA();
	a.analysis(s, out);
	return 0;
}

string LR1::stack_2_string(stack<int> state) {
	string str;
	stack<int> state1;
	while (state.size()) {
		state1.push(state.top());
		state.pop();
	}
	while (state1.size() > 1) {
		str += to_string(state1.top())+ ",";
		state1.pop();
	}
	if (state1.size() == 1) str += to_string(state1.top());
	return str;
}

string LR1::stack_2_string1(stack<char> sign) {
	string str;
	stack<char> sign1;
	while (sign.size()) {
		sign1.push(sign.top());
		sign.pop();
	}
	while (sign1.size() > 1) {
		str += sign1.top();
		sign1.pop();
	}
	if (sign1.size() == 1) str += sign1.top();
	return str;
}

void LR1::build_DFA()
/* 重写LR1中项目集规范族的构造, 产生DFA、Action、Goto */
{
	generate_FirstSet();
	vector<vecP> Collections;	/* 项目集规范族, 保存各状态 */
	stack<vecP> Stack; 			/* 处理栈 */
	vecP Closure; 				/* 某一状态(项目集) */
	Pro pro;

	for (int i = 0; i < Productions.size(); i++) /* 设置初态 */
	{
		// 将第一个项目放入第一个项目集中
		if (Productions[i][0] == Start)
		{
			pro.expr = Productions[i];
			pro.ahead = "#";
			pro.pos = 1;
			Closure.push_back(pro);
		}
	}
	// 求第一个项目集
	enclosure(Closure);

	vector<pic> tmp;
	DFA.push_back(tmp); /* 每次有一个新的项目集，就会先放入一个结构，之后用来放对应的项目集转换 */
	Collections.push_back(Closure); /* 将第一个项目放入项目集规范族中 */
	Stack.push(Closure);			/* 将第一个项目压栈 */

	while (!Stack.empty())
	{
		Closure = Stack.top();
		Stack.pop();
		unordered_map<char, int> Vis;

		/* 根据内容反推下标 */
		int index = find(all(Collections), Closure) - Collections.begin();

		/* 遍历可转移的V,不止是Vt */
		for (int i = 0; i < Closure.size(); i++)
		{
			string expr = Closure[i].expr;
			if (Closure[i].pos >= expr.length()) continue;	/* 项目分隔符在产生式的末尾 */
			char ch = expr[Closure[i].pos];
			if (Vis.count(ch) != 0) continue;
			Vis[ch] = 1;
			vecP NewClosure;
			/* 找到同一Closure中所有依赖ch的转移 */
			for (int j = i; j < Closure.size(); j++)
			{
				if (Closure[j].pos < Closure[j].expr.length()
					&& Closure[j].expr[Closure[j].pos] == ch)
				{
					Pro tmp;
					tmp.expr = Closure[j].expr;
					tmp.pos = Closure[j].pos + 1;
					tmp.ahead = Closure[j].ahead;
					NewClosure.push_back(tmp);
				}
			}
			enclosure(NewClosure); /* 扩充 */
			if (find(all(Collections), NewClosure) == Collections.end())
			{
				Collections.push_back(NewClosure);
				DFA.push_back(tmp);	/* 同步push_back,下标对应*/
				Stack.push(NewClosure);
			}
			/* 弧添加到DFA中 */
			int New_index = find(all(Collections), NewClosure) - Collections.begin();
			DFA[index].push_back({ New_index, ch }); /* 项目集index可以通过ch到达项目集New_index*/
		}
	}

	build_table(Collections);
	cout << "Action表" << endl;
	for (int i = 0; i < Action.size(); i++)
	{
		cout << "状态" << i << "：";
		for (int j = 0; j < Action[i].size(); j++)
		{
			cout << "(" << Action[i][j].first << "，" << Action[i][j].second << ") ";
		}
		cout << endl;
	}
	for (int i = 0; i < 110; i++) cout << '-';
	cout << endl;
	cout << "Goto表" << endl;
	for (int i = 0; i < Goto.size(); i++)
	{
		cout << "状态" << i << "：";
		for (int j = 0; j < Goto[i].size(); j++)
		{
			cout << "(" << Goto[i][j].first << "，" << Goto[i][j].second << ") ";
		}
		cout << endl;
	}
	cout << endl;
}

void LR1::build_table(vector<vecP>& Collections)
/* 建立Action、Goto表*/
{
	/* vector<vector<pair<int,char> > > DFA; */
	/* vector<vecP> Collections; */
	/* vector<vector<pair<char,int> > > Action; */
	/* vector<vector<pair<char,int> > > Goto; */

	int n = DFA.size();
	Action.resize(n);
	Goto.resize(n);

	int state;
	char v;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < DFA[i].size(); j++)	/* 移进 */
		{
			// 通过哪个字符到达哪个新的项目集
			state = DFA[i][j].first;
			v = DFA[i][j].second;
			/* 判断字符ch是否为英文字母，若为英文字母，返回非0（小写字母为2，大写字母为1） */
			if (isalpha(v) == 1) /* 大写非终结符 */
			{
				Goto[i].push_back({ v,state });
			}
			else /* 终结符 */
			{
				Action[i].push_back({ v,state });
			}
		}
		for (int j = 0; j < Collections[i].size(); j++) /* 规约 */
		{
			if (Collections[i][j].pos >= Collections[i][j].expr.length())
			{
				string expr = Collections[i][j].expr;
				int pos = find(all(Productions), expr) - Productions.begin(); /* 第几条产生式 */
				pos = -pos; /* 用状态的负数表示规约(无空产生式，故state为0时不可能规约)*/
				for (int k = 0; k < Collections[i][j].ahead.length(); k++)
				{
					Action[i].push_back({ Collections[i][j].ahead[k], pos });
				}
			}
		}
	}
}

void LR1::enclosure(vecP& Closure)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < Closure.size(); i++)
		{
			string expr = Closure[i].expr;
			if (Closure[i].pos >= expr.length()) continue;
			char v = expr[Closure[i].pos]; /* 间隔符后第一个字符 */
			if (find(all(VnSet), v) != VnSet.end()) /* 是非终结符 */
			{
				for (int j = 0; j < Productions.size(); j++) /* 遍历所有产生式，把此Vn打头的都放进来 */
				{
					if (Productions[j][0] != v) continue;
					Pro tmp;
					tmp.expr = Productions[j];
					tmp.pos = 1;
					/* 看项目分隔符后面的第二个字符 */
					tmp.ahead = generate_ahead(expr.substr(Closure[i].pos + 1), Closure[i].ahead);
					if (find(all(Closure), tmp) == Closure.end())
					{
						Closure.push_back(tmp);
						flag = true;
					}
				}
			}

		}
	}
	sort(all(Closure));  /* 扩充 */
}

string LR1::generate_ahead(string remainder, string ahead)
/* 输入项目分隔符右边部分以及该项目向前搜索符，求给出字串的first集  */
{
	char ch;
	string ans = "";
	if (remainder.length() == 0)
	{
		ans = ahead;
	}
	else
	{
		for (int i = 0; i < remainder.length(); i++) /* 遍历串的每个字符 */
		{
			ch = remainder[i];
			if (find(all(VnSet), ch) != VnSet.end()) /* 非终结符 */
			{
				string tmp = First[ch];
				int pos = find(all(tmp), '$') - tmp.begin();
				if (pos < tmp.length()) /* 能推出空 */
				{
					tmp.erase(pos, 1);
					ans += tmp;
					sort(all(ans));
					ans.erase(unique(all(ans)), ans.end());
					if (i == remainder.length() - 1) /* 每个VN都能推出空 */
					{
						ans += ahead;
						sort(all(ans));
						ans.erase(unique(all(ans)), ans.end());
					}
				}
				else /* 不能推出空 */
				{
					ans += tmp;
					sort(all(ans));
					ans.erase(unique(all(ans)), ans.end());
					break;
				}
			}
			else /* 终结符 */
			{
				if (find(all(ans), ch) == ans.end())
				{
					ans += ch;
					sort(all(ans));
				}
				break;
			}
		}
	}
	return ans;
}

void LR1::generate_FirstSet()
/* 生成每个非终结符的First集的集合 */
{
	for (int i = 0; i < VnSet.size(); i++)
	{
		First[VnSet[i]] = "";
	}

	bool flag = true; /* First修改过就被置成true */
	while (flag)
	{
		flag = false;
		for (int i = 0; i < VnSet.size(); i++) /* 遍历每个非终结符 */
		{
			// 每个VN
			char ch = VnSet[i];
			for (int j = 0; j < Productions.size(); j++) /* 从产生式库中找到左部是ch的 */
			{
				if (Productions[j][0] != ch) continue;
				int k = 1;
				// 遍历产生式右部的每一个符号
				while (k < Productions[j].length())
				{
					/* 遇到"终结符"或"非终结符推不出空"则退出循环 */
					/* 添加其first集 */
					if (!VtSet.count(Productions[j][k])) /* 非终结符 */
					{
						string tmp = First[Productions[j][k]];
						int pos = find(all(tmp), '$') - tmp.begin();
						if (pos < tmp.length()) /* 含空产生式， 只有此情况会继续看产生式下一个字符  */
						{
							tmp.erase(pos, 1);
							if (!contains(First[ch], tmp))
							{
								First[ch] += tmp;
								sort(all(First[ch]));
								First[ch].erase(unique(all(First[ch])), First[ch].end());
								flag = true;
							}
							if (k == Productions[j].length() - 1 && First[ch].find("$") == -1)
							{
								First[ch] += '$';
								sort(all(First[ch])); /* 排序 */
								First[ch].erase(unique(all(First[ch])), First[ch].end()); /* 相邻元素重复去重 */
								flag = true;
							}
						}
						else /* 不含空产生式  */
						{
							if (!contains(First[ch], tmp))
							{
								First[ch] += tmp;
								sort(all(First[ch]));
								First[ch].erase(unique(all(First[ch])), First[ch].end());
								flag = true;
							}
							break;
						}
					}
					else /* 终结符 */
					{
						/* 求first集 是不是$都可以直接加 */
						if (find(all(First[ch]), Productions[j][k]) == First[ch].end())
						{
							First[ch] += Productions[j][k];
							sort(all(First[ch]));
							flag = true;
						}
						break;
					}
					k++;
				}
			}
		}
	}
}

bool LR1::contains(string a, string b)
/* 串b中的字符是否都在串a中出现 */
{
	for (int j = 0; j < b.length(); j++)
	{
		if (find(all(a), b[j]) == a.end())
		{
			return false;
		}
	}
	return true;
}

void LR1::input(string File)
{
	/* 输入2型文法,存了一个Start,主要是产生式左部和右部的生成 */
	/* Production第0位是产生式左部，后面是产生式右部  */
	cin.clear();
	freopen(File.c_str(), "r", stdin);
	string line;
	bool b = true;
	while (getline(cin, line))
	{
		if (line.length() == 0) break;
		if (b)
		{
			this->Start = line[0];
			b = false;
		}
		int i = 1, j = 1;
		char start = line[0];
		while (i < line.size())
		{
			if (line[i] == '>' || line[i] == '-')
			{
				line.erase(i, 1);
				continue;
			}
			else if (line[i] == '|')
			{
				// 放入产生式左部和右部，其余->和|均擦除
				Productions.push_back(start + line.substr(j, i - j));
				line.erase(i, 1);
				j = i;
				continue;
			}
			else
			{
				// 将VN放入VnSet
				if (line[i] >= 'A' && line[i] <= 'Z') /* 大写字母是非终结符 */
				{
					if (find(all(VnSet), line[i]) == VnSet.end())
					{
						VnSet.push_back(line[i]);
					}
				}
				// 将VT放入VtSet
				else VtSet.insert(line[i]);
			}
			i++;
		}
		// 放入产生式左部和右部(最后一个)
		Productions.push_back(start + line.substr(j, i - j));
	}
	/* 处理词典 */
	getline(cin, line);
	int i = 0;
	bool t = false;
	string key;
	char value;
	while (i < line.length())
	{
		if (line[i] == ' ' || line[i] == ':')
		{
			i++;
			continue;
		}
		else
		{
			if (t) /* 交替访问Key和Value */
			{
				value = line[i];
				i++; /* value长度为1 */
				t = false;
				Dic[key] = value;
			}
			else
			{
				int j = i;
				while (i < line.length() && line[i] != ' ' && line[i] != ':')
				{
					i++;
				}
				key = line.substr(j, i - j); /* 取key */
				t = true;
			}
		}
	}
	Dic["#"] = '#';
}

void LR1::analysis(string FileIn, string FileOut)
/* 读入词法分析结果，进行语法分析，输出 */
{
	ofstream fout;
	fout.open(FileOut, ios::app); /* 追加打印 */
	int step = 0;
	/*freopen(FileOut.c_str(), "w+",stdin);*/
	cin.clear();
	freopen(FileIn.c_str(), "r", stdin);

	string line;
	int index;
	string word, type;
	int if_num = 0, do_num = 0;

	stack<int> state;
	stack<char> sign;
	sign.push('#');
	int st, pos;
	state.push(0);

	for (int i = 0; i < 115; i++) cout << '-';

	fout << "分析栈" << "\r\n";
	fout << std::left << setw(20) << "步骤" <<
		std::left << setw(30) << "状态栈" <<
		std::left << setw(25) << "符号栈" <<
		std::left << setw(20) << "输入串" <<
		std::left << setw(15) << "Action" <<
		std::left << setw(15) << "GoTo" << "\r\n";
	cout << endl;
	cout << "分析栈" << endl;
	cout << std::left << setw(20) << "步骤" << 
		std::left << setw(30) << "状态栈" << 
		std::left << setw(25) <<"符号栈" << 
		std::left << setw(20) << "输入串" <<
		std::left << setw(12) << "Action" <<
		std::left << setw(12) << "GoTo" << endl;

	bool fir = true;
	bool f = false;
	//f==true就不读入下一行
	while (f || getline(cin, line))
	{
		fout << endl;
		fout << std::left << setw(20) << ++step <<
			std::left << setw(30) << stack_2_string(state) <<
			std::left << setw(25) << stack_2_string1(sign);
		cout << std::left << setw(20) <<step <<
			std::left << setw(30) << stack_2_string(state) <<
			std::left << setw(25) << stack_2_string1(sign);
		/* 输入 */
		// 如果上一步在归约，说明未处理上一步中读入的字符，本次不进行读入，而是直接进行处理
		if (!f)
		{
			int i = 1;
			while (line[i] != ',') i++;
			index = atoi(line.substr(1, i - 1).c_str());//行数
			int j = ++i;
			while (line[i] != ',') i++;
			// j可能指向界符","
			if (i == j) i++;
			type = line.substr(j, i - j);
			j = ++i;
			while (line[i] != ')') i++;
			word = line.substr(j, i - j);
			if (word == "if") if_num++;
			if (word == "else") if_num--;
			if (word == "while") do_num--;
			if (word == "do") do_num++;
		}
		f = false;
		cout << std::left << setw(20) << word;
		fout << std::left << setw(20) << word;
		if (word == "#")
		{
			if (state.size() == 2) {
				int tmp = state.top();
				state.pop();
				if (state.top() == 0) {
					if (error_t > 0) {
						cout << endl;
						cout << "NO" << endl;
						fout << "\r\n";
						fout << "NO" << "\r\n";
					}
					else {
						cout << std::left << setw(12) << "Acc" << endl;
						cout << endl;
						cout << "Yes" << endl;
						fout << std::left << setw(15) << "Acc" << "\r\n";
						fout << "\r\n";
						fout << "Yes" << "\r\n";
					}
					return;
				}
				else {
					state.push(tmp);
				}
			}
		}
		/* 处理 */
		char sn;
		// 以b为例，在词表中没有，b是Identifier，需要找到Identifier对应的代号
		if (Dic.count(word) != 0) sn = Dic[word];
		else if (type == "Identifier")
		{
			sn = Dic["Identifier"];
		}
		else if (type == "Constant")
			sn = Dic["Constant"];
		st = state.top();
		int path = 0;
		if (find(all(VnSet), sn) != VnSet.end()) /* 非终结符 - Goto */
		{
			bool t = true;
			for (int k = 0; k < Goto[st].size(); k++)
			{
				// 根据Go-to表进行状态转移
				if (Goto[st][k].first == sn) /* 移进 */
				{
					state.pop();
					state.push(Goto[st][k].second);
					sign.push(sn);
					t = false;
					path = 1;
					break;
				}
			}
			// 没有相应的状态转移，出错
			if (t)
			{
				error_t++;
				if (if_num < 0) {
					cout << endl;
					cout << "[ERROR] 'then' has no previous 'if' to match." << endl;
					fout << "\r\n";
					fout << "[ERROR] 'then' has no previous 'if' to match." << "\r\n";
				}
				if (do_num < 0) {
					cout << endl;
					cout << "[ERROR] 'while' has no 'do' to match." << endl;
					fout << "\r\n";
					fout << "[ERROR] 'while' has no 'do' to match." << "\r\n";
				}
				report(index, state, sign, FileOut);
			}
		}
		else
		{
			bool t = true;
			for (int k = 0; k < Action[st].size(); k++)
			{
				if (Action[st][k].first == sn)
				{
					if (Action[st][k].second >= 0) /* 移进 */
					{
						state.push(Action[st][k].second);
						sign.push(sn);
						path = 2;
					}
					else /* 规约 */
					{
						pos = -Action[st][k].second;
						string expr = Productions[pos];
						int cnt = expr.length() - 1;
						while (cnt--)	/* 弹出产生式右部的部分 */
						{
							sign.pop();
							state.pop();
						}
						sign.push(expr[0]);
						st = state.top();
						for (int k = 0; k < Goto[st].size(); k++)
						{
							if (Goto[st][k].first == expr[0]) /* 移进 */
							{
								state.push(Goto[st][k].second);
								break;
							}
						}
						f = true;
						path = 3;
					}
					t = false;
					break;
				}
			}
			if (t)  /* 错误报告 */
			{
				error_t++;
				if (if_num < 0) {
					if_num = 0;
					cout << endl;
					cout << "[ERROR] 'else' has no previous 'if' to match." << endl;
					fout << "\r\n";
					fout << "[ERROR] 'else' has no previous 'if' to match." << "\r\n";
				}
				if (do_num < 0) {
					cout << endl;
					cout << "[ERROR] 'while' has no 'do' to match." << endl;
					fout << "\r\n";
					fout << "[ERROR] 'while' has no 'do' to match." << "\r\n";
				}
				report(index, state, sign, FileOut);
			}
		}
		if (path == 1) {
			int top = state.top();
			cout << std::left << setw(12) << " " << std::left << setw(15) << top << endl;
			fout << std::left << setw(15) << " " << std::left << setw(15) << top << "\r\n";
		}
		else if (path == 2) {
			int top = state.top();
			string top1 = to_string(top);
			cout << std::left << setw(12) << "s" + top1 << endl;
			fout << std::left << setw(15) << "s" + top1 << "\r\n";
		}
		else if (path == 3) {
			int top = state.top();
			string pos1 = to_string(pos);
			cout << std::left << setw(12) << "r" + pos1 << std::left << setw(12) << top << endl;
			fout << std::left << setw(15) << "r" + pos1 << std::left << setw(15) << top << "\r\n";
		}
	}
	cout << endl;
	if (error_t != 0) {
		cout << "No" << endl;
		fout << "No" << "\r\n";
	}
	else {
		cout << "No" << endl;
		cout << "Reason : # is needed." << endl;
		fout << "No" << "\r\n";
		fout << "Reason : # is needed." << "\r\n";
	}
}

void LR1::report(int r,stack<int> state, stack<char> sign, string FileOut)
{
	ofstream fout;
	fout.open(FileOut,ios::app); /* 追加打印 */
	string reason;
	int top = state.top();
	reason = "Maybe [ ";
	stack<char> need_sign;
	for (auto p : Action[top]) { /* first:char, second:int */
		int s = p.second;
		char vt = p.first;
		need_sign.push(vt);
		need_sign.push(' ');
		if (vt == 'b') {
			cout << endl;
			cout << "[ERROR] ';' is needed to end this sentence."<< endl;
			fout << "\r\n";
			fout << "[ERROR] ';' is needed to end this sentence." << "\r\n";
		}
		else if (vt == 'm') {
			cout << endl;
			cout << "[ERROR] 'relational operator' is needed to end this sentence." << endl;
			fout << "\r\n";
			fout << "[ERROR] 'relational operator' is needed to end this sentence." << "\r\n";
		}
		else if (vt == 'g') {
			cout << endl;
			cout << "[ERROR] 'keyword' is needed to be in there." << endl;
			fout << "\r\n";
			fout << "[ERROR] 'keyword' is needed to be in there." << "\r\n";
		}
		else if (vt == 'e') {
			cout << endl;
			cout << "[ERROR] 'equal sign' is needed to be in there." << endl;
			fout << "\r\n";
			fout << "[ERROR] 'equal sign' is needed to be in there." << "\r\n";
		}
		else if (vt == 'f' || vt == 'd') {
			cout << endl;
			cout << "[ERROR] 'constant' or 'identifier' is needed to be in there." << endl;
			fout << "\r\n";
			fout << "[ERROR] 'constant' or 'identifier' is needed to be in there." << "\r\n";
		}
	}
	if (need_sign.size() == 0) {
		reason = nullptr;
	}
	else {
		reason += stack_2_string1(need_sign);
		reason += "] is or are needed.";
	}
	//state.push(top);
	time_t t = time(nullptr);
	struct tm* now = localtime(&t);
	stringstream time;
	string state1 = stack_2_string(state);
	time << "Time : " << now->tm_year + 1900 << "/";
	time << now->tm_mon + 1 << "/";
	time << now->tm_mday << " ";
	time << now->tm_hour << ":";
	time << now->tm_min << ":";
	time << now->tm_sec;
	cout << endl;
	cout << "[ERROR] " << time.str() << endl;
	cout << "        When scaning line " << r << ", wrong state is visited while compling." << endl;
	cout << "        Reason : " << reason << endl;
	cout << "        Informations in State Stack(bottom to top) : " << state1 << endl;
	fout << "\r\n";
	fout << "[ERROR] " << time.str() << "\r\n";
	fout << "\t  When scaning line " << r << ", wrong state is visited while compling." << "\r\n";
	fout << "\t  Reason : " << reason << "\r\n";
	fout << "\t  Informations in State Stack(bottom to top) : " << state1 << "\r\n";
}