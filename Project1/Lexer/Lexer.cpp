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

#define VN first /* ��VN������first������������Ӧ */
#define VT second
#define ERROR -1 

typedef pair<string, int> psi;
typedef pair<string, string> pss;

class NFA
{
public:
	ofstream fout;				/* �����ļ���� */
	bool isDef;					/* �Ƿ��Ѿ�ȷ���� */
	int snum, fsnum;			/* ״̬��������̬���� */
	string line, VT, VN;		/* �ķ��е�ÿһ�У�VN��ʾfirst��VT��ʾsecond */
	string Start;				/* ֻ��һ����̬Start */
	vector<bool> FinalSet;		/* ��̬�����������̬����Ϊtrue */
	set<string> VtSet;			/* VT���� */
	set<string> KeySet;			/* �ؼ��� */
	map<string, int> Map;		/* VN���ϣ�������ÿһ��VN��Ӧ�ı�ţ��ñ����List�е�indexͬ�� */
	vector<vector<pss> > List;	/* ״̬ת������ʾ�ɵ�ǰ״̬ͨ����������������һ��״̬ */
	map<string, int> Type;		/* ��ʾ�ʼ������࣬��ʶ�����ؼ��ʡ��ָ����������������� */
	map<string, int> SType;		/* ��ʾ��״̬����һ������·���� */

	NFA(); /* ���죬��ʼ��һ��NFA */

	void input(string regular);			/* ���������ķ�regular expression�ı��ļ� */
	void print(string out);				/* ���м�����Լ���Ԫ������ӡ��product�ı��ļ��� */
	void solve_line(string line);		/* ÿ��һ��һ�д���������ķ���һ���ķ������漰����������ʽ */
	void solve_pro(string production);	/* ÿ�δ���һ������ʽ */
	string get_start(string line);		/* ��regular expression�ı��ļ��л�ȡ��һ��VN��Ҳ������ʼ״̬ */
	string get_vn(string& line);		/* ��regular expression�ı��ļ��л�ȡ����ʼ��֮���VN(����ʽ��)�����������Լ�->֮��(��������)�Ĳ��� */
	string get_vt(string& line);		/* ��get_start����������ֻʣ���ұߵĲ��֣���ȡVT */
	void get_Type(string line);			/* ���ڵ�һ�У��Ҳ��Ĳ���������࣬��Type�и�ֵ�������ţ���Ϊ����� */
	void extend(string VN);				/* ���µ�״̬����Map�� */
	void nfa_2_dfa();					/* NFAתDFA */
	void e_closure(string status, vector<string>& V);						/* ��ĳ������״̬��$�հ� */
	void vt_move(string vt, vector<string> V_closure, vector<string>& T);	/* �ڱհ����ҵ�vt���仯�������������״̬�� */
};

/* �ʷ����� */
class LA : public NFA
{
public:
	ofstream fout;	/* �����ļ���� */
	string line;	/* ��ǰ������� */
	string word;	/* ��ǰ����ĵ��� */
	string T;		/* ��ǰ״̬ */
	int index;		/* ��ǰ״̬��List�ж�Ӧ���±� */
	int id;			/* ����к� */	
	int deviation;	/* ƫ�� */
	int dec_error;	/* С������ɵĴ��� */

	LA(); /* ���죬��ʼ��һ��LA */
	void analysis(NFA& nfa, string source, string out);		/* ����DFA��source code���дʷ����������������ӡ��product�ı��ļ��� */
	void read_next_VT(char ch, NFA& nfa, string out);		/* ����DFA������һ��vt */
	void output(int error, int type, NFA& nfa, string out);	/* ����DFA�͸���������룬�������ӡ��product�ı��ļ��� */
	bool isAlphabet(char ch);								/* �ж��ǲ�����ĸ����ʶ���ʶ��ʱ����Ҫ��������ĸ����ʽ���б�������һ�����ʴ�����������һ���� */
	bool isDigit(char ch);									/* �ж��ǲ������֣���+/-��������������֣������������� */
	bool isOps(string s);									/* �ж��ǲ��ǱȽϹ�ϵ�������������֣����������²��ǳ�����������+/-������ */
	string pre;												/* ֮ǰ��״̬��=��<=��>=��<<��>>����������ǰ��ķ��ŵ��������� */
};

/* ��map�и���second(VT)��key */
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
	nfa.print(out);		/* ��ӡNFA������ */
	nfa.nfa_2_dfa();	/* NFAתDFA */
	nfa.print(out);		/* ׷�Ӵ�ӡDFA������ */

	LA la; /* �����ʷ������� */
	la.T = nfa.Start;				/* �ʷ��������ĳ�̬��DFA�ǳ�̬ */
	la.analysis(nfa, source, out);	/* ��source_code��Ϊ���룬���������ɵ�DFA�����������׷�Ӵ�ӡ��product�ļ���*/

	return 0;
}

/* ����ĸ */
bool LA::isAlphabet(char ch) {
	if (ch >= 'a' && ch <= 'z') return true;
	if (ch >= 'A' && ch <= 'Z') return true;
	return false;
}
/* ������ */
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
			if (word == "/" && line[i] == '/') { /* ����ע�� */
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
	/* List[index]ָ���ǵ�ǰ״̬��Ӧ�Ļ��任 */
	/* �鿴���ch�Ƿ��ж�Ӧ���任 */ 
	auto it = std::find_if(nfa.List[index].begin(), nfa.List[index].end(), match(ch));
	// ��̬�ˣ�û�ж�Ӧ�Ļ��任���������ڹؼ��ʱ����ҵ�
	/* û�ж�Ӧ�Ļ��任 */
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
		/* ���ǡ������̬ */
		/* �ؼ��ʺͱ�ʶ��Ҫ�������� */
		if (nfa.FinalSet[index])
		{
			/* һ���������ߵ���̬�����Ǻ��滹�����ŷǿպͷǽ��������*/
			/*cout << "word : " << word << ", Type : " << nfa.SType[T] << endl;*/
			/* ״̬��Ӧ�ı�� */ 
			
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
			/* ��һ���ӳ�̬��ʼ�� */
			T = nfa.Start;
			index = 0;
			word = "";
			read_next_VT(ch, nfa, out);
		}
		/* ���������̬��˵�������� */
		else
		{
			output(ERROR, nfa.SType[T], nfa, out);
		}
	}
	else {					/* �ҵ� */
		T = it->first;		/* ��һ��״̬����it->first */
		index = nfa.Map[T];	/* �鿴��һ��״̬T����VN��Map�еı�� */
		word += ch;			/* ��ͣ���ۼ�����̬ */
	}
}

void LA::output(int error, int type,NFA& nfa, string out)
{
	fout.open(out.c_str(), ios::app);
	if (error == ERROR)
	{
		/* ����ĳ��·���ߣ������ߵ�ĳһ��ȴ�����˴���˵�����Ǹ����� */
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
		auto it = std::find_if(nfa.Type.begin(), nfa.Type.end(), [type](const std::map<std::string, int>::value_type item)->bool {return item.second == type; });  /* ����value����key */
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
/* NFA��ͼת��Ϊ DFA��ͼ */
{
	/* ��״̬->��� ��Ϊ ״̬��->��� */
	map<string, int> NewMap;    	/* VN���� */
	vector<vector<pss> > NewList;  /* ��״̬�任��Ϊ״̬���任 */
	map<string, int> NewSType; 	/* ��״̬���ı�� */
	vector<vector<string> > NewStates; /* ��״̬��Ϊ״̬�� */

	int n, id, t = 0;
	string start = "T", NewStart;
	vector<string> NewStartSet;

	e_closure(Start, NewStartSet); /* ״̬V:Start��$�հ� */

	NewStates.push_back(NewStartSet);
	NewStart = start + to_string(t);
	NewMap[start + to_string(t)] = t++;

	for (int map_id = 0; map_id < t; map_id++)	/* ����״̬�����ڱ��������п��ܻ�����µ�״̬�� */
	{
		n = NewStates[map_id].size(); /* ��ǰ����״̬�� */
		vector<pss> arcList; /* �ɱ���״̬�����Ļ� */
		unordered_map<string, int> Viewed;

		for (int i = 0; i < n; i++) /* ��������̬ÿһ��VN�� ��������VT����һ�� */
		{
			int index = Map[NewStates[map_id][i]], m = List[index].size();
			for (int j = 0; j < m; j++) /* ����һ��VN��ȫ������VN--vt-->anotherVN�� */
			{
				string vt = List[index][j].second;
				/* $˵���Ǻͱ�״̬���е�״̬����ת������ϵ������������$ */
				if (vt == "$") continue; /* �������ַ� */
				if (Viewed.count(vt) != 0) continue; /* ��֤ÿ����״̬ÿ���ս��ֻ��һ�� */
				else
				{
					vector<string> T; /* T������״̬ */
					vt_move(vt, NewStates[map_id], T); /* ͨ���հ�ת����ö�Ӧ��״̬*/
					Viewed[vt] = 1;  /* ��ֹ��ԭ״̬�����жϸ��ս�� */

					set<string>tmp(T.begin(), T.end());
					/* ��ͬVNͨ����ͬ��VT���ܵ���ͬһ��VN */
					T.assign(tmp.begin(), tmp.end()); /* Tȥ�ء����� */

					int pos = find(NewStates.begin(), NewStates.end(), T) - NewStates.begin();
					/* ÿ����һ����״̬��״̬��t++��pos==t˵����find����ΪNewStates.end()�������״̬�� */
					if (pos == t) /* �����״̬���в�����ǰ��״̬������ӽ�ȥ */
					{
						NewStates.push_back(T);
						NewMap[start + to_string(t)] = t++;

						for (int k = 0; k < T.size(); k++) /* NewSType */
						{
							if (SType[T[k]] != 0) {
								/* ���ͺ�ԭ������һ�� */
								NewSType[start + to_string(t - 1)] = SType[T[k]];
							}	
						}
					}
					/* ͨ��vt��������״̬���������е�״̬ */
					arcList.push_back({ start + to_string(pos), vt }); /* ���ܴ���״̬�Ƿ��Ѿ����ֹ�����Ҫ��������»� */

				}
			}
		}
		NewList.push_back(arcList);
	}

	/* ��д MAP, LIST, SType, Start, FinalSet */
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
/* ����һ��״̬����$�հ� */
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
				/* ֮ǰ��û���룬�ͼ��뵱ǰ״̬ */
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
/* �ڱհ�V���ҵ�vt��ת���� ����״̬����T�� */
{
	int id, n;
	for (int i = 0; i < V.size(); i++)
	{
		id = Map[V[i]];
		n = List[id].size();
		for (int j = 0; j < n; j++)
		{
			if (List[id][j].second == vt) /* �ҵ�֮��Ͳ�����ƥ���� */
			{
				e_closure(List[id][j].first, T);
				break;
			}
		}
	}
}

void NFA::solve_line(string line)
/* ÿ�δ���һ�У������ж�������ʽ*/
{
	if (line[0] == '/' && line[1] == '/') return;	/* ����ע�� */
	/* ����'|'ʧ�� */
	/* ֻ��һ������ʽ */
	if (line.find('|') == -1)
		solve_pro(line);
	else {
		string subfront, subrear;
		int pos = line.find('>'), j = pos + 1;
		subfront = line.substr(0, pos + 1);	/* ��ȡ��>(����>)��λ�� */
		while (line.find('|', pos + 1) != -1)	/* ���ҵ�'|' */
		{
			pos = line.find('|', pos + 1);
			/* ��һ�δ�pos + 1λ�ÿ�ʼ���� */
			/* ��ʼλ�ú���һ��'|'֮��Ĳ��־��ǲ���ʽ���Ҳ� */
			subrear = line.substr(j, pos - j);
			j = pos + 1;
			solve_pro(subfront + subrear);
		}
		subrear = subrear = line.substr(j);	/* ��'|'����һ��λ�ÿ�ʼ */
		solve_pro(subfront + subrear);
	}
}

void NFA::solve_pro(string production)
/* ÿ�δ���һ������ʽ  */
{
	VN = get_vn(production);
	VT = get_vt(production);

	VtSet.insert(VT);
	/* Map�������״̬�Լ���Ӧ�ı�� */
	/* �³��ֵ�VN */
	if (Map.count(VN) == 0)
		extend(VN);
	/* �³��ֵ�״̬ */
	if (Map.count(production) == 0)
		extend(production);
	int id = Map[VN];
	List[id].push_back(pss(production, VT));
	/* Startֻ��һ������ڵ� */
	/* ����Identifier��Operator��Seperator��Constant��Key��inputʱ�Ѿ�����ֵ�˶�Ӧ�����ͱ�� */
	if (VN == Start) return;
	/* SType��ʾ����ܹ鵽��һ�࣬ͬһ���Ӧ�ı����ͬ */
	if (SType.count(VN) == 0 && Type.count(VN))
		SType[VN] = Type[VN];
	/* VN->production */
	/* production(Ҳ��һ��״̬) �� VN ������һ�� */
	if (SType.count(production) == 0)
		SType[production] = SType[VN];
}

void NFA::extend(string VN)
/* ��״̬�ӵ�Map�У������ڶ�Ӧ��List�����������ݽṹ */
{
	vector<pss> t; // pair<string,string>
	List.push_back(t);
	Map[VN] = snum++;
}

string NFA::get_start(string production)
/* �������л�ȡ��һ��VN��������ʼ״̬ */
{
	int i = 0, j = 0;
	while (j < production.length() && production[j] != ' ' && production[j] != '-')	j++;	/* -֮ǰ */
	string sub = production.substr(i, j);
	return sub;
}

string NFA::get_vn(string& production)
/* �������еõ���һ��VN������line��ȥ��������֮���-> */
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
/* �������еõ���һ��VT */
{
	int i = 0, j = 0;
	string sub;
	if (isalpha(production[j]) == 1)	/* �ж��ǲ����ս�� */
		sub = "$";
	else if (production[j] == '\'') {	/* �����'��ʾ��һ����д��ĸ�������ַ�ʽ��������ս����������*/
		j++;
		while (production[j] != '\'') j++;
		j++;
		sub = production.substr(i + 1, j - 2);
		//cout << "j : " << j << ", sub :" << sub << endl;
		if (j > 3) /* �ؼ��ʣ�ȥͷβ���� */
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
	while (line.length() && line[i] == ' ') i++;	/*  ��->֮�� */
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
		fout.open(out, ios::app);		/* ofstream����ʹ��ios::appģʽ���ļ��������ļ�ĩβ��������� */
	else
		fout.open(out);
	if (isDef) fout << "DFA\n";	/* �Ѿ�ȷ���� -> DFA */
	else fout << "NFA\n";				/* δȷ���� -> NFA */
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\n";
	fout << "VN ( nonterminal character ) \n"; /* Map���VN */
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
	fout << "\nVT ( terminal character ) \n"; /* VtSet���VT */
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
	fout << "\nKey ( key character ) \n"; /* Key��Źؼ��� */
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
	fout << "\nStart ( initial state ) \n" << Start;	/* ��״̬ */
	fout << "\n";
	for (int i = 0; i < 150; i++) fout << '-';
	fout << "\nFinal ( final state ) \n";				/* ��̬ */
	k = 0;
	for (int i = 0; i < snum; i++)
		if (FinalSet[i] == true)
		{
			/* {״̬, ״̬���} */
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
		fout << std::left << setw(16) << p.first << ' ' << p.second << '\t';	/* ��� */
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
		fout << std::left << setw(16) << p.first << ' ' << p.second << '\t';	/* ÿ��״̬��Ӧ������� */
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
		for (int j = 0; j < n; j++)	/* ��VN��Ӧ�Ļ��仯 */
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
	get_Type(line);	/* �õ�Identifier��Operator��Seperator��Constant��Key�ı�� */
	do {
		solve_line(line);
		line = "";
		getline(cin, line);
	} while (line != "");
	FinalSet.resize(snum, false);						/* ��ʼΪ��СΪsnum�Ҿ�Ϊfalse�����飬��ʾ��ʼ״̬��������̬ */
	for (int i = 0; i < fsnum; i++)						/* ֻ�к���final��״̬������̬����ֵΪtrue */
		FinalSet[Map["final" + to_string(i)]] = true;
	fclose(stdin);
}

NFA::NFA()
{
	snum = 0;				/* ��ʼ״̬��Ϊ0 */
	fsnum = 0;				/* ��ʼ��̬��Ϊ0 */
	isDef = false;	/* ��ʼδ��ȷ����ΪDFA */
}