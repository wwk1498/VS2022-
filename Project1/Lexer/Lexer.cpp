#include <iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cctype>
#include<unordered_map>
#include<stack>
#include<iomanip>
using namespace std;

#define VN first /* 用VN来代替first，与语义相适应 */
#define VT second
#define ERROR -1 

typedef pair<string, int> psi;
typedef pair<string, string> pss;

class NFA
{
public:
	ofstream fout;				/* 用于文件输出 */
	bool isDef;					/* 是否已经确定化 */
	int snum, fsnum;			/* 状态总数，终态总数 */
	string line, VT, VN;		/* 文法中的每一行，VN表示first，VT表示second */
	string Start;				/* 只有一个初态Start */
	vector<bool> FinalSet;		/* 终态集，如果是终态，置为true */
	set<string> VtSet;			/* VT集合 */
	set<string> KeySet;			/* 关键词 */
	map<string, int> Map;		/* VN集合，并且有每一个VN对应的编号，该编号与List中的index同步 */
	vector<vector<pss> > List;	/* 状态转换，表示由当前状态通过弧操作，到达另一个状态 */
	map<string, int> Type;		/* 表示最开始的五大类，标识符、关键词、分隔符、操作符、常量 */
	map<string, int> SType;		/* 表示各状态在哪一个类别的路径上 */

	NFA(); /* 构造，初始化一个NFA */

	void input(string regular);			/* 输入三型文法regular expression文本文件 */
	void print(string out);				/* 将中间过程以及三元组结果打印在product文本文件中 */
	void solve_line(string line);		/* 每次一行一行处理输入的文法，一行文法可能涉及到多条产生式 */
	void solve_pro(string production);	/* 每次处理一条产生式 */
	string get_start(string line);		/* 从regular expression文本文件中获取第一个VN，也就是起始状态 */
	string get_vn(string& line);		/* 从regular expression文本文件中获取除起始符之外的VN(产生式左部)，并擦除其以及->之间(包含二者)的部分 */
	string get_vt(string& line);		/* 由get_start经过擦除后，只剩下右边的部分，获取VT */
	void get_Type(string line);			/* 对于第一行，右部的部分是五大类，在Type中赋值，将其编号，作为种类号 */
	void extend(string VN);				/* 将新的状态加入Map中 */
	void nfa_2_dfa();					/* NFA转DFA */
	void e_closure(string status, vector<string>& V);						/* 求某个给定状态的$闭包 */
	void vt_move(string vt, vector<string> V_closure, vector<string>& T);	/* 在闭包中找到vt弧变化，并将其放入新状态中 */
};

/* 词法分析 */
class LA : public NFA
{
public:
	ofstream fout;	/* 用于文件输出 */
	string line;	/* 当前处理的行 */
	string word;	/* 当前处理的单词 */
	string T;		/* 当前状态 */
	int index;		/* 当前状态在List中对应的下标 */
	int id;			/* 输出行号 */	
	int deviation;	/* 偏移 */
	int dec_error;	/* 小数点造成的错误 */

	LA(); /* 构造，初始化一个LA */
	void analysis(NFA& nfa, string source, string out);		/* 根据DFA对source code进行词法分析，并将结果打印在product文本文件中 */
	void read_next_VT(char ch, NFA& nfa, string out);		/* 根据DFA读入下一个vt */
	void output(int error, int type, NFA& nfa, string out);	/* 根据DFA和给定的类别码，将结果打印在product文本文件中 */
	bool isAlphabet(char ch);								/* 判断是不是字母，在识别标识符时，需要对数字字母的形式进行报错，再下一个单词处理是跳过这一部分 */
	bool isDigit(char ch);									/* 判断是不是数字，在+/-后面如果不是数字，往操作符方向靠 */
	bool isOps(string s);									/* 判断是不是比较关系符，后面是数字，这种情形下才是常量，否则是+/-操作符 */
	string pre;												/* 之前的状态是=、<=、>=、<<、>>，遇到数字前面的符号当作正负号 */
};

/* 在map中根据second(VT)找key */
class match
{
private:
	const char ch;
public:
	explicit match(char c) : ch(c) {}
	bool operator() (const std::pair<string, string>& element) const {
		return element.second[0] == ch;
	}
};

int main()
{
	string regular = "regular expression.txt", 
		out = "lexer_product.txt", 
		source = "source_code.txt";

	NFA nfa;
	nfa.input(regular);
	nfa.print(out);		/* 打印NFA的内容 */
	nfa.nfa_2_dfa();	/* NFA转DFA */
	nfa.print(out);		/* 追加打印DFA的内容 */

	LA la; /* 创建词法分析器 */
	la.T = nfa.Start;				/* 词法分析器的初态是DFA是初态 */
	la.analysis(nfa, source, out);	/* 将source_code作为输入，根据已生成的DFA，将分析结果追加打印在product文件中*/

	return 0;
}

/* 是字母 */
bool LA::isAlphabet(char ch) {
	if (ch >= 'a' && ch <= 'z') return true;
	if (ch >= 'A' && ch <= 'Z') return true;
	return false;
}
/* 是数字 */
bool LA::isDigit(char ch) {
	if (ch >= '0' && ch <= '9') return true;
	return false;
}

bool LA::isOps(string s) {
	if (s == "=") return true;
	if (s == "<") return true;
	if (s == ">") return true;
	if (s == ">=") return true;
	if (s == "<=") return true;
	if (s == "==") return true;
	if (s == "<<") return true;
	if (s == ">>") return true;
	return false;
}

void LA::analysis(NFA& nfa, string source, string out)
{
	//for (auto p : KeySet) cout << "p : " << p << endl;
	cin.clear();
	freopen(source.c_str(), "r", stdin);
	int n;
	bool flag = true;
	while (getline(cin, line))
	{
		cout << line << endl;
		n = line.length();
		if (n == 0) break;
		id++;
		for (int i = 0; i < n; i++)
		{
			if (line[i] == '}') {
				word = "}";
				output(0, 3, nfa, out);
				T = nfa.Start;
				index = 0;
				word = "";
				continue;
			}
			if (line[i] == ' '|| line[i] == '\t') {
				if (nfa.KeySet.count(word)) {
					output(0, 5, nfa, out);
					T = nfa.Start;
					index = 0;
					word = "";
					continue;
				}
				else if (nfa.SType[T] == nfa.Type["Identifier"]) {
					output(0, nfa.SType[T], nfa, out);
					if (word != "" && !isOps(word)) {
						pre = "ncmp";
					}
					T = nfa.Start;
					index = 0;
					word = "";
					continue;
				}
				else {
					continue;
				}
			}
			if (word == "") {
				if (line[i] == '\n') continue;
			}
			if (word == "/" && line[i] == '/') { /* 跳过注释 */
				/*output(-4, 0, nfa, out);*/
				flag = false;
				break;
			}
			else {
				if (!isOps(word)) {
					if (line[i] == '+' || line[i] == '-') {
						if ((i + 1) < n && line[i + 1] == '=') {
							if (line[i] == '+')
								word = "+=";
							else word = "-=";
							i++;
							output(0, 2, nfa, out);
							T = nfa.Start;
							index = 0;
							word = "";
							continue;
						}
						else if (pre != "cmp") {
							word = line[i];
							output(0, 2, nfa, out);
							T = nfa.Start;
							index = 0;
							word = "";
							continue;
						}
					}
				}
				read_next_VT(line[i], nfa, out);
				if (dec_error == 1) {
					dec_error = 0;
					while (line[i] == '.' || (line[i] >= '0' && line[i] <= '9')) {
						word += line[i++];
					}
					output(ERROR, 4, nfa, out);
					T = nfa.Start;
					index = 0;
					word = "";
					i--;
				}
				if (deviation == 1) {
					deviation = 0;
					while (isAlphabet(line[i])) {
						word += line[i++];
					}
					output(ERROR, 4, nfa, out);
					T = nfa.Start;
					index = 0;
					word = "";
					i--;
				}
			}
		}
		if (flag) {
			if (nfa.KeySet.count(word))
				output(0, 5, nfa, out);
			else
				output(0, nfa.SType[T], nfa, out);
		}
		T = nfa.Start;
		index = 0;
		word = "";
	}
	fclose(stdin);
}

void LA::read_next_VT(char ch, NFA& nfa, string out)
{
	/* List[index]指的是当前状态对应的弧变换 */
	/* 查看这个ch是否有对应弧变换 */ 
	auto it = std::find_if(nfa.List[index].begin(), nfa.List[index].end(), match(ch));
	// 终态了，没有对应的弧变换，并且能在关键词表中找到
	/* 没有对应的弧变换 */
	if (ch == '\t') {
		output(-5, 5, nfa, out);
		T = nfa.Start;
		index = 0;
		word = "";
		return;
	}
	if (it == nfa.List[index].end())
	{
		if (ch == ' ' && word=="") {
			output(-3, 5, nfa, out);
			T = nfa.Start;
			index = 0;
			word = "";
			return;
		}
		if (nfa.KeySet.count(word) && nfa.FinalSet[index]) {
			output(0, 5, nfa, out);
			T = nfa.Start;
			index = 0;
			word = "";
			read_next_VT(ch, nfa, out);
			return;
		}
		if (word == "+" || word == "-") {
			if (!isDigit(ch) && ch != '=') {
				output(0, 2, nfa, out);
				T = nfa.Start;
				index = 0;
				word = "";
				read_next_VT(ch, nfa, out);
				return;
			}
		}
		if (isOps(word)) {
			pre = "cmp";
		}
		if (word != "" && !isOps(word)){
			pre = "ncmp";
		}
		/* 如果恰好是终态 */
		/* 关键词和标识符要进行区分 */
		if (nfa.FinalSet[index])
		{
			/* 一个类别如果走到终态，但是后面还紧跟着非空和非界符，出错*/
			/*cout << "word : " << word << ", Type : " << nfa.SType[T] << endl;*/
			/* 状态对应的编号 */ 
			
			if (nfa.SType[T] == 4 && isAlphabet(ch) && ch != 'i') {
				deviation = 1;
				return;
			}
			if (nfa.KeySet.count(word)) 
				output(0, 5, nfa, out);
			else {
				if (nfa.SType[T] == 4 && ch == '.') {
					dec_error = 1;
					return;
				}
				else {
					output(0, nfa.SType[T], nfa, out);
				}
			}
			/* 下一个从初态开始找 */
			T = nfa.Start;
			index = 0;
			word = "";
			read_next_VT(ch, nfa, out);
		}
		/* 如果不是终态，说明出错了 */
		else
		{
			output(ERROR, nfa.SType[T], nfa, out);
		}
	}
	else {					/* 找到 */
		T = it->first;		/* 下一个状态就是it->first */
		index = nfa.Map[T];	/* 查看下一个状态T，该VN在Map中的编号 */
		word += ch;			/* 不停地累加至终态 */
	}
}

void LA::output(int error, int type,NFA& nfa, string out)
{
	fout.open(out.c_str(), ios::app);
	if (error == ERROR)
	{
		/* 沿着某条路径走，但是走到某一步却出现了错误，说明不是该类型 */
		index = nfa.Map[T];
		auto it = std::find_if(nfa.Type.begin(), nfa.Type.end(), [type](const std::map<std::string, int>::value_type item)->bool {return item.second == type; });
		cout << "ERROR(" << type << "): While tackling " << it->first << ", \'" << word << "\' is not a " << it->first << "." << endl;
	}
	/*else if (error == -2) {
		fout << "PROMPT (" << "line" << id << "): \'\n\' is  jumped." << endl;
		cout << "PROMPT (" << "line" << id << "): \'\n\' is  jumped." << endl;
	}
	else if (error == -3) {
		fout << "PROMPT (" << "line" << id << "): \'Space\' is  jumped." << endl;
		cout << "PROMPT (" << "line" << id << "): \'Space\' is  jumped." << endl;
	}
	else if (error == -4) {
		fout << "PROMPT (" << "line" << id << "): \'\/\/\' is  jumped." << endl;
		cout << "PROMPT (" << "line" << id << "): \'\/\/\' is  jumped." << endl;
	}
	else if (error == -5) {
		fout << "PROMPT (" << "line" << id << "): \'Tab\' is  jumped." << endl;
		fout << "PROMPT (" << "line" << id << "): \'Tab\' is  jumped." << endl;
	}*/
	else
	{
		auto it = std::find_if(nfa.Type.begin(), nfa.Type.end(), [type](const std::map<std::string, int>::value_type item)->bool {return item.second == type; });  /* 根据value倒推key */
		int len = word.length();
		fout << "(" << id << "," << it->first << "," << word << ")" << endl;
		cout << "(" << id << "," << it->first << "," << word << ")" << endl;
	}
	fout.close();
}

LA::LA()
{
	index = 0;
	id = 0;
	word = "";
	T = "";
}

void NFA::nfa_2_dfa()
/* NFA的图转化为 DFA的图 */
{
	/* 由状态->编号 变为 状态集->编号 */
	map<string, int> NewMap;    	/* VN集合 */
	vector<vector<pss> > NewList;  /* 由状态变换变为状态集变换 */
	map<string, int> NewSType; 	/* 各状态集的编号 */
	vector<vector<string> > NewStates; /* 由状态变为状态集 */

	int n, id, t = 0;
	string start = "T", NewStart;
	vector<string> NewStartSet;

	e_closure(Start, NewStartSet); /* 状态V:Start的$闭包 */

	NewStates.push_back(NewStartSet);
	NewStart = start + to_string(t);
	NewMap[start + to_string(t)] = t++;

	for (int map_id = 0; map_id < t; map_id++)	/* 遍历状态集，在遍历过程中可能会产生新的状态集 */
	{
		n = NewStates[map_id].size(); /* 当前处理状态集 */
		vector<pss> arcList; /* 由本新状态引出的弧 */
		unordered_map<string, int> Viewed;

		for (int i = 0; i < n; i++) /* 遍历此新态每一个VN， 将遇到的VT都算一遍 */
		{
			int index = Map[NewStates[map_id][i]], m = List[index].size();
			for (int j = 0; j < m; j++) /* 遍历一个VN中全部弧（VN--vt-->anotherVN） */
			{
				string vt = List[index][j].second;
				/* $说明是和本状态集中的状态发生转化，联系弧操作不考虑$ */
				if (vt == "$") continue; /* 跳过空字符 */
				if (Viewed.count(vt) != 0) continue; /* 保证每个新状态每个终结符只查一次 */
				else
				{
					vector<string> T; /* T才是新状态 */
					vt_move(vt, NewStates[map_id], T); /* 通过闭包转换获得对应新状态*/
					Viewed[vt] = 1;  /* 防止此原状态反复判断该终结符 */

					set<string>tmp(T.begin(), T.end());
					/* 不同VN通过相同的VT可能到达同一个VN */
					T.assign(tmp.begin(), tmp.end()); /* T去重、排序 */

					int pos = find(NewStates.begin(), NewStates.end(), T) - NewStates.begin();
					/* 每加入一个新状态，状态数t++，pos==t说明，find返回为NewStates.end()，添加新状态集 */
					if (pos == t) /* 如果新状态集中不含当前新状态，就添加进去 */
					{
						NewStates.push_back(T);
						NewMap[start + to_string(t)] = t++;

						for (int k = 0; k < T.size(); k++) /* NewSType */
						{
							if (SType[T[k]] != 0) {
								/* 类型和原来保持一致 */
								NewSType[start + to_string(t - 1)] = SType[T[k]];
							}	
						}
					}
					/* 通过vt弧到达新状态或者是已有的状态 */
					arcList.push_back({ start + to_string(pos), vt }); /* 不管此新状态是否已经出现过，都要添加这条新弧 */

				}
			}
		}
		NewList.push_back(arcList);
	}

	/* 重写 MAP, LIST, SType, Start, FinalSet */
	Map.swap(NewMap);
	List.swap(NewList);
	SType.swap(NewSType);
	snum = t;
	Start = start + "0";
	FinalSet.resize(snum, false);
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < NewStates[i].size(); j++)
		{
			if (NewStates[i][j].find("final") == -1) continue;
			else
			{
				FinalSet[i] = true;
				break;
			}
		}	
	}
	isDef = true;
}

void NFA::e_closure(string status, vector<string>& T)
/* 给出一个状态，求$闭包 */
{
	int id, n;
	string tmp;
	stack<string> Stack;
	Stack.push(status);
	T.push_back(status);
	while (!Stack.empty())
	{
		tmp = Stack.top();
		Stack.pop();
		id = Map[tmp];
		n = List[id].size();
		for (int i = 0; i < n; i++)
		{
			if (List[id][i].second == "$")
			{
				/* 之前还没加入，就加入当前状态 */
				if (find(T.begin(), T.end(), List[id][i].first) == T.end())
				{
					Stack.push(List[id][i].first);
					T.push_back(List[id][i].first);
				}
			}
		}
	}
}

void NFA::vt_move(string vt, vector<string> V, vector<string>& T)
/* 在闭包V中找到vt弧转换， 将新状态放入T中 */
{
	int id, n;
	for (int i = 0; i < V.size(); i++)
	{
		id = Map[V[i]];
		n = List[id].size();
		for (int j = 0; j < n; j++)
		{
			if (List[id][j].second == vt) /* 找到之后就不会再匹配了 */
			{
				e_closure(List[id][j].first, T);
				break;
			}
		}
	}
}

void NFA::solve_line(string line)
/* 每次处理一行，可能有多条产生式*/
{
	if (line[0] == '/' && line[1] == '/') return;	/* 跳过注释 */
	/* 查找'|'失败 */
	/* 只有一条产生式 */
	if (line.find('|') == -1)
		solve_pro(line);
	else {
		string subfront, subrear;
		int pos = line.find('>'), j = pos + 1;
		subfront = line.substr(0, pos + 1);	/* 截取到>(包含>)的位置 */
		while (line.find('|', pos + 1) != -1)	/* 能找到'|' */
		{
			pos = line.find('|', pos + 1);
			/* 下一次从pos + 1位置开始查找 */
			/* 起始位置和下一个'|'之间的部分就是产生式的右部 */
			subrear = line.substr(j, pos - j);
			j = pos + 1;
			solve_pro(subfront + subrear);
		}
		subrear = subrear = line.substr(j);	/* 从'|'的下一个位置开始 */
		solve_pro(subfront + subrear);
	}
}

void NFA::solve_pro(string production)
/* 每次处理一条产生式  */
{
	VN = get_vn(production);
	VT = get_vt(production);

	VtSet.insert(VT);
	/* Map存放所有状态以及对应的编号 */
	/* 新出现的VN */
	if (Map.count(VN) == 0)
		extend(VN);
	/* 新出现的状态 */
	if (Map.count(production) == 0)
		extend(production);
	int id = Map[VN];
	List[id].push_back(pss(production, VT));
	/* Start只是一个虚拟节点 */
	/* 其后的Identifier、Operator、Seperator、Constant、Key在input时已经被赋值了对应的类型编号 */
	if (VN == Start) return;
	/* SType表示最后能归到哪一类，同一类对应的编号相同 */
	if (SType.count(VN) == 0 && Type.count(VN))
		SType[VN] = Type[VN];
	/* VN->production */
	/* production(也是一个状态) 和 VN 的类型一致 */
	if (SType.count(production) == 0)
		SType[production] = SType[VN];
}

void NFA::extend(string VN)
/* 将状态加到Map中，并且在对应的List表中增添数据结构 */
{
	vector<pss> t; // pair<string,string>
	List.push_back(t);
	Map[VN] = snum++;
}

string NFA::get_start(string production)
/* 从输入中获取第一个VN，这是起始状态 */
{
	int i = 0, j = 0;
	while (j < production.length() && production[j] != ' ' && production[j] != '-')	j++;	/* -之前 */
	string sub = production.substr(i, j);
	return sub;
}

string NFA::get_vn(string& production)
/* 从输入中得到下一个VN，并在line中去掉其与其之后的-> */
{
	int i = 0, j = 0;
	while (j < production.length() && production[j] != ' ' && production[j] != '-')	j++;
	string sub = production.substr(i, j);
	while (j < production.length() && (production[j] == ' ' || production[j] == '-' || production[j] == '>'))
	{
		j++;
		if (production[j - 1] == '>') break;
	}
	while (j < production.length() && production[j] == ' ') j++;
	production.erase(i, j);
	return sub;
}

string NFA::get_vt(string& production)
/* 从输入中得到下一个VT */
{
	int i = 0, j = 0;
	string sub;
	if (isalpha(production[j]) == 1)	/* 判断是不是终结符 */
		sub = "$";
	else if (production[j] == '\'') {	/* 如果是'表示是一个大写字母，用这种方式将其与非终结符进行区分*/
		j++;
		while (production[j] != '\'') j++;
		j++;
		sub = production.substr(i + 1, j - 2);
		//cout << "j : " << j << ", sub :" << sub << endl;
		if (j > 3) /* 关键词，去头尾引号 */
		{
			KeySet.insert(sub);
			//cout << "sub : " << sub << endl;
		}
		production.erase(i, j);
	}
	else
	{
		j++;
		sub = production.substr(i, j);
		production.erase(i, j);
	}


	if (production == "")
	{
		production = "final" + to_string(fsnum);
		fsnum++;
	}
	return sub;
}

void NFA::get_Type(string line)
{
	int i = 0, id = 1;
	while (i < line.length() && line[i] != '>') i++;
	i++;
	while (line.length() && line[i] == ' ') i++;	/*  从->之后 */
	while (i < line.length())
	{
		int j = i;
		while (line[i] != '|' && i < line.length()) i++;
		string tmp = line.substr(j, i - j);
		Type[tmp] = id++;
		i++;
	}
}

void NFA::print(string out)
{
	int k = 0;
	if (isDef)
		fout.open(out, ios::app);		/* ofstream对象使用ios::app模式打开文件可以在文件末尾添加新内容 */
	else
		fout.open(out);
	if (isDef) fout << "DFA\n";	/* 已经确定化 -> DFA */
	else fout << "NFA\n";				/* 未确定化 -> NFA */
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\n";
	fout << "VN ( nonterminal character ) \n"; /* Map存放VN */
	for (const auto p : Map){
		fout << std::left << setw(12) << p.first << ' ';
		k++;
		if (k % 11 == 0) {
			fout << "\n";
			k -= 11;
		}
	}
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\nVT ( terminal character ) \n"; /* VtSet存放VT */
	k = 0;
	for (const auto p : VtSet) {
		fout << std::left << setw(16) << p << ' ';
		k++;
		if (k % 9 == 0) {
			fout << "\n";
			k -= 9;
		}
	}
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	k = 0;
	fout << "\nKey ( key character ) \n"; /* Key存放关键词 */
	for (const auto p : KeySet) {
		fout << std::left << setw(16) << p << ' ';
		k++;
		if (k % 9 == 0) {
			fout << "\n";
			k -= 9;
		}
	}
		
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\nStart ( initial state ) \n" << Start;	/* 初状态 */
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\nFinal ( final state ) \n";				/* 终态 */
	k = 0;
	for (int i = 0; i < snum; i++)
		if (FinalSet[i] == true)
		{
			/* {状态, 状态编号} */
			auto it = std::find_if(Map.begin(), Map.end(), [i](const std::map<std::string, int>::value_type item)->bool {return item.second == i; });
			fout << std::left << setw(12) << it->first << ' ';
			k++;
			if (k % 11 == 0) {
				fout << "\n";
				k -= 11;
			}
		}
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\nType \n";
	k = 0;
	for (const auto p : Type) {
		fout << std::left << setw(16) << p.first << ' ' << p.second << '\t';	/* 类别 */
		k++;
		if (k % 6 == 0) {
			fout << "\n";
			k -= 6;
		}
	}
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\nSType \n";
	k = 0;
	for (const auto p : SType) {
		fout << std::left << setw(16) << p.first << ' ' << p.second << '\t';	/* 每个状态对应到的类别 */
		k++;
		if (k % 6 == 0) {
			fout << "\n";
			k -= 6;
		}
	}
	fout << "\n";
	fout << "\nListArc \n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\n";
	int n, i;
	for (const auto p : Map)
	{
		if (p.first == "") continue;
		fout << p.first << ": " << "\n";
		i = p.second;
		n = List[i].size();
		if (n == 0) fout << "NULL";
		k = 0;
		for (int j = 0; j < n; j++)	/* 该VN对应的弧变化 */
		{
			fout <<  "( " << List[i][j].second << " , " << List[i][j].first << " ); ";
			k++;
			if (k % 6 == 0) {
				fout << "\n";
				k -= 6;
			}

		}
		fout << "\n";
		for (int i = 0; i < 150; i++) fout << '-';
		fout << "\n";
	}
	fout.close();
}

void NFA::input(string regular)
{
	freopen(regular.c_str(), "r", stdin);
	getline(cin, line);
	Start = get_start(line);
	get_Type(line);	/* 得到Identifier、Operator、Seperator、Constant、Key的编号 */
	do {
		solve_line(line);
		line = "";
		getline(cin, line);
	} while (line != "");
	FinalSet.resize(snum, false);						/* 初始为大小为snum且均为false的数组，表示初始状态都不是终态 */
	for (int i = 0; i < fsnum; i++)						/* 只有含有final的状态才是终态，赋值为true */
		FinalSet[Map["final" + to_string(i)]] = true;
	fclose(stdin);
}

NFA::NFA()
{
	snum = 0;				/* 初始状态数为0 */
	fsnum = 0;				/* 初始终态数为0 */
	isDef = false;	/* 初始未被确定化为DFA */
}