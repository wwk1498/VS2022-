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
	string expr; 		/* ����ʽ */
	int pos;			/* ��Ŀ�ָ�����λ�ã�������Ҳ���ǰ��һ��λ�ÿ�ʼ��������ǲ���ʽ���� */
	string ahead;		/* ��ǰ������ */
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
	char Start;						/* ��ʼ�� */
	unordered_set<char> VtSet;		/* �ս���� */
	vector<char> VnSet;				/* ���ս����,�����ȽϷ��� */
	vector<string> Productions;		/* ����ʽ */
	vector<vector<pair<int, char> > > DFA;		/* DFA */
	vector<vector<pair<char, int> > > Action;	/* Action�� */
	vector<vector<pair<char, int> > > Goto;		/* Goto�� */
	map<char, string> First;					/* ÿ�����ս����First���ļ��� */
	map<string, char> Dic;						/* �ʵ� */
	int error_t;								/* �������������"�����˴������Acc"�Լ�"ȱ��#�ı���"�����*/

	void generate_FirstSet();					/* ����ÿһ�����ս����First���� */
	bool contains(string a, string b);			/* ��b�е��ַ��Ƿ��ڴ�a�г��� */
	string generate_ahead(string remaider, string ahead);	/* ������ǰ������ */

	void input(string File);						/* ����������ķ��ʹʵ� */
	void analysis(string FileIn,string FileOut);	/* �����������Ԫ����з��� */
	void build_DFA();								/* ����DFAת�� */
	void build_table(vector<vecP>& Collections);	/* ���� */
	void enclosure(vecP& C);						/* ����Ŀ�� */
	void report(int r, stack<int> state, stack<char> sign, string FileOut);

	string stack_2_string(stack<int> state);	/* ��״̬ջ��ջ�׵�ջ�����ַ�������ʽ���� */
	string stack_2_string1(stack<char> sign);	/* ������ջ��ջ�׵�ջ�����ַ�������ʽ���� */
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
/* ��дLR1����Ŀ���淶��Ĺ���, ����DFA��Action��Goto */
{
	generate_FirstSet();
	vector<vecP> Collections;	/* ��Ŀ���淶��, �����״̬ */
	stack<vecP> Stack; 			/* ����ջ */
	vecP Closure; 				/* ĳһ״̬(��Ŀ��) */
	Pro pro;

	for (int i = 0; i < Productions.size(); i++) /* ���ó�̬ */
	{
		// ����һ����Ŀ�����һ����Ŀ����
		if (Productions[i][0] == Start)
		{
			pro.expr = Productions[i];
			pro.ahead = "#";
			pro.pos = 1;
			Closure.push_back(pro);
		}
	}
	// ���һ����Ŀ��
	enclosure(Closure);

	vector<pic> tmp;
	DFA.push_back(tmp); /* ÿ����һ���µ���Ŀ�����ͻ��ȷ���һ���ṹ��֮�������Ŷ�Ӧ����Ŀ��ת�� */
	Collections.push_back(Closure); /* ����һ����Ŀ������Ŀ���淶���� */
	Stack.push(Closure);			/* ����һ����Ŀѹջ */

	while (!Stack.empty())
	{
		Closure = Stack.top();
		Stack.pop();
		unordered_map<char, int> Vis;

		/* �������ݷ����±� */
		int index = find(all(Collections), Closure) - Collections.begin();

		/* ������ת�Ƶ�V,��ֹ��Vt */
		for (int i = 0; i < Closure.size(); i++)
		{
			string expr = Closure[i].expr;
			if (Closure[i].pos >= expr.length()) continue;	/* ��Ŀ�ָ����ڲ���ʽ��ĩβ */
			char ch = expr[Closure[i].pos];
			if (Vis.count(ch) != 0) continue;
			Vis[ch] = 1;
			vecP NewClosure;
			/* �ҵ�ͬһClosure����������ch��ת�� */
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
			enclosure(NewClosure); /* ���� */
			if (find(all(Collections), NewClosure) == Collections.end())
			{
				Collections.push_back(NewClosure);
				DFA.push_back(tmp);	/* ͬ��push_back,�±��Ӧ*/
				Stack.push(NewClosure);
			}
			/* ����ӵ�DFA�� */
			int New_index = find(all(Collections), NewClosure) - Collections.begin();
			DFA[index].push_back({ New_index, ch }); /* ��Ŀ��index����ͨ��ch������Ŀ��New_index*/
		}
	}

	build_table(Collections);
	cout << "Action��" << endl;
	for (int i = 0; i < Action.size(); i++)
	{
		cout << "״̬" << i << "��";
		for (int j = 0; j < Action[i].size(); j++)
		{
			cout << "(" << Action[i][j].first << "��" << Action[i][j].second << ") ";
		}
		cout << endl;
	}
	for (int i = 0; i < 110; i++) cout << '-';
	cout << endl;
	cout << "Goto��" << endl;
	for (int i = 0; i < Goto.size(); i++)
	{
		cout << "״̬" << i << "��";
		for (int j = 0; j < Goto[i].size(); j++)
		{
			cout << "(" << Goto[i][j].first << "��" << Goto[i][j].second << ") ";
		}
		cout << endl;
	}
	cout << endl;
}

void LR1::build_table(vector<vecP>& Collections)
/* ����Action��Goto��*/
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
		for (int j = 0; j < DFA[i].size(); j++)	/* �ƽ� */
		{
			// ͨ���ĸ��ַ������ĸ��µ���Ŀ��
			state = DFA[i][j].first;
			v = DFA[i][j].second;
			/* �ж��ַ�ch�Ƿ�ΪӢ����ĸ����ΪӢ����ĸ�����ط�0��Сд��ĸΪ2����д��ĸΪ1�� */
			if (isalpha(v) == 1) /* ��д���ս�� */
			{
				Goto[i].push_back({ v,state });
			}
			else /* �ս�� */
			{
				Action[i].push_back({ v,state });
			}
		}
		for (int j = 0; j < Collections[i].size(); j++) /* ��Լ */
		{
			if (Collections[i][j].pos >= Collections[i][j].expr.length())
			{
				string expr = Collections[i][j].expr;
				int pos = find(all(Productions), expr) - Productions.begin(); /* �ڼ�������ʽ */
				pos = -pos; /* ��״̬�ĸ�����ʾ��Լ(�޿ղ���ʽ����stateΪ0ʱ�����ܹ�Լ)*/
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
			char v = expr[Closure[i].pos]; /* ��������һ���ַ� */
			if (find(all(VnSet), v) != VnSet.end()) /* �Ƿ��ս�� */
			{
				for (int j = 0; j < Productions.size(); j++) /* �������в���ʽ���Ѵ�Vn��ͷ�Ķ��Ž��� */
				{
					if (Productions[j][0] != v) continue;
					Pro tmp;
					tmp.expr = Productions[j];
					tmp.pos = 1;
					/* ����Ŀ�ָ�������ĵڶ����ַ� */
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
	sort(all(Closure));  /* ���� */
}

string LR1::generate_ahead(string remainder, string ahead)
/* ������Ŀ�ָ����ұ߲����Լ�����Ŀ��ǰ��������������ִ���first��  */
{
	char ch;
	string ans = "";
	if (remainder.length() == 0)
	{
		ans = ahead;
	}
	else
	{
		for (int i = 0; i < remainder.length(); i++) /* ��������ÿ���ַ� */
		{
			ch = remainder[i];
			if (find(all(VnSet), ch) != VnSet.end()) /* ���ս�� */
			{
				string tmp = First[ch];
				int pos = find(all(tmp), '$') - tmp.begin();
				if (pos < tmp.length()) /* ���Ƴ��� */
				{
					tmp.erase(pos, 1);
					ans += tmp;
					sort(all(ans));
					ans.erase(unique(all(ans)), ans.end());
					if (i == remainder.length() - 1) /* ÿ��VN�����Ƴ��� */
					{
						ans += ahead;
						sort(all(ans));
						ans.erase(unique(all(ans)), ans.end());
					}
				}
				else /* �����Ƴ��� */
				{
					ans += tmp;
					sort(all(ans));
					ans.erase(unique(all(ans)), ans.end());
					break;
				}
			}
			else /* �ս�� */
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
/* ����ÿ�����ս����First���ļ��� */
{
	for (int i = 0; i < VnSet.size(); i++)
	{
		First[VnSet[i]] = "";
	}

	bool flag = true; /* First�޸Ĺ��ͱ��ó�true */
	while (flag)
	{
		flag = false;
		for (int i = 0; i < VnSet.size(); i++) /* ����ÿ�����ս�� */
		{
			// ÿ��VN
			char ch = VnSet[i];
			for (int j = 0; j < Productions.size(); j++) /* �Ӳ���ʽ�����ҵ�����ch�� */
			{
				if (Productions[j][0] != ch) continue;
				int k = 1;
				// ��������ʽ�Ҳ���ÿһ������
				while (k < Productions[j].length())
				{
					/* ����"�ս��"��"���ս���Ʋ�����"���˳�ѭ�� */
					/* �����first�� */
					if (!VtSet.count(Productions[j][k])) /* ���ս�� */
					{
						string tmp = First[Productions[j][k]];
						int pos = find(all(tmp), '$') - tmp.begin();
						if (pos < tmp.length()) /* ���ղ���ʽ�� ֻ�д���������������ʽ��һ���ַ�  */
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
								sort(all(First[ch])); /* ���� */
								First[ch].erase(unique(all(First[ch])), First[ch].end()); /* ����Ԫ���ظ�ȥ�� */
								flag = true;
							}
						}
						else /* �����ղ���ʽ  */
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
					else /* �ս�� */
					{
						/* ��first�� �ǲ���$������ֱ�Ӽ� */
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
/* ��b�е��ַ��Ƿ��ڴ�a�г��� */
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
	/* ����2���ķ�,����һ��Start,��Ҫ�ǲ���ʽ�󲿺��Ҳ������� */
	/* Production��0λ�ǲ���ʽ�󲿣������ǲ���ʽ�Ҳ�  */
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
				// �������ʽ�󲿺��Ҳ�������->��|������
				Productions.push_back(start + line.substr(j, i - j));
				line.erase(i, 1);
				j = i;
				continue;
			}
			else
			{
				// ��VN����VnSet
				if (line[i] >= 'A' && line[i] <= 'Z') /* ��д��ĸ�Ƿ��ս�� */
				{
					if (find(all(VnSet), line[i]) == VnSet.end())
					{
						VnSet.push_back(line[i]);
					}
				}
				// ��VT����VtSet
				else VtSet.insert(line[i]);
			}
			i++;
		}
		// �������ʽ�󲿺��Ҳ�(���һ��)
		Productions.push_back(start + line.substr(j, i - j));
	}
	/* ����ʵ� */
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
			if (t) /* �������Key��Value */
			{
				value = line[i];
				i++; /* value����Ϊ1 */
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
				key = line.substr(j, i - j); /* ȡkey */
				t = true;
			}
		}
	}
	Dic["#"] = '#';
}

void LR1::analysis(string FileIn, string FileOut)
/* ����ʷ���������������﷨��������� */
{
	ofstream fout;
	fout.open(FileOut, ios::app); /* ׷�Ӵ�ӡ */
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

	fout << "����ջ" << "\r\n";
	fout << std::left << setw(20) << "����" <<
		std::left << setw(30) << "״̬ջ" <<
		std::left << setw(25) << "����ջ" <<
		std::left << setw(20) << "���봮" <<
		std::left << setw(15) << "Action" <<
		std::left << setw(15) << "GoTo" << "\r\n";
	cout << endl;
	cout << "����ջ" << endl;
	cout << std::left << setw(20) << "����" << 
		std::left << setw(30) << "״̬ջ" << 
		std::left << setw(25) <<"����ջ" << 
		std::left << setw(20) << "���봮" <<
		std::left << setw(12) << "Action" <<
		std::left << setw(12) << "GoTo" << endl;

	bool fir = true;
	bool f = false;
	//f==true�Ͳ�������һ��
	while (f || getline(cin, line))
	{
		fout << endl;
		fout << std::left << setw(20) << ++step <<
			std::left << setw(30) << stack_2_string(state) <<
			std::left << setw(25) << stack_2_string1(sign);
		cout << std::left << setw(20) <<step <<
			std::left << setw(30) << stack_2_string(state) <<
			std::left << setw(25) << stack_2_string1(sign);
		/* ���� */
		// �����һ���ڹ�Լ��˵��δ������һ���ж�����ַ������β����ж��룬����ֱ�ӽ��д���
		if (!f)
		{
			int i = 1;
			while (line[i] != ',') i++;
			index = atoi(line.substr(1, i - 1).c_str());//����
			int j = ++i;
			while (line[i] != ',') i++;
			// j����ָ����","
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
		/* ���� */
		char sn;
		// ��bΪ�����ڴʱ���û�У�b��Identifier����Ҫ�ҵ�Identifier��Ӧ�Ĵ���
		if (Dic.count(word) != 0) sn = Dic[word];
		else if (type == "Identifier")
		{
			sn = Dic["Identifier"];
		}
		else if (type == "Constant")
			sn = Dic["Constant"];
		st = state.top();
		int path = 0;
		if (find(all(VnSet), sn) != VnSet.end()) /* ���ս�� - Goto */
		{
			bool t = true;
			for (int k = 0; k < Goto[st].size(); k++)
			{
				// ����Go-to�����״̬ת��
				if (Goto[st][k].first == sn) /* �ƽ� */
				{
					state.pop();
					state.push(Goto[st][k].second);
					sign.push(sn);
					t = false;
					path = 1;
					break;
				}
			}
			// û����Ӧ��״̬ת�ƣ�����
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
					if (Action[st][k].second >= 0) /* �ƽ� */
					{
						state.push(Action[st][k].second);
						sign.push(sn);
						path = 2;
					}
					else /* ��Լ */
					{
						pos = -Action[st][k].second;
						string expr = Productions[pos];
						int cnt = expr.length() - 1;
						while (cnt--)	/* ��������ʽ�Ҳ��Ĳ��� */
						{
							sign.pop();
							state.pop();
						}
						sign.push(expr[0]);
						st = state.top();
						for (int k = 0; k < Goto[st].size(); k++)
						{
							if (Goto[st][k].first == expr[0]) /* �ƽ� */
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
			if (t)  /* ���󱨸� */
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
	fout.open(FileOut,ios::app); /* ׷�Ӵ�ӡ */
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