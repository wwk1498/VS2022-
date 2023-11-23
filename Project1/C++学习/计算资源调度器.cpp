#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//���ص���ʱʹ��
//#define inline 

typedef struct node {
	int id;//��� 
	int block;//��
	int nums;//��ǰ�������� 
	set<int> task; //����������ı�� 

	bool operator <(const node& a)const {
		if (this->nums != a.nums) {
			return this->nums < a.nums;
		}
		else {
			return this->id < a.id;
		}
	}
}node;

unordered_map<int, node> Node;

//���Ϊn�Ŀ������ڵļ���ڵ�
void fax1(int n, vector<int>& temp) {
	for (auto it = temp.begin(); it != temp.end();) {
		if (Node[*it].block != n) {
			temp.erase(it);
		}
		else it++;
	}
	return;
}

//�ͱ��Ϊn��Ӧ�õļ���������ͬһ��������
void fax2(int n, vector<int>& temp) {
	set<int> qu;
	for (auto it = Node.begin(); it != Node.end(); it++) {
		if (it->second.task.count(n) == 1) {
			qu.insert(it->second.block);
		}
	}
	for (auto it = temp.begin(); it != temp.end();) {
		if (qu.count(Node[*it].block) == 0) {
			temp.erase(it);
		}
		else it++;
	}
	return;
}

//��ʾ���ܺͱ��Ϊn��Ӧ�õļ���������ͬһ������ڵ�������
vector<int> fax3(int n, vector<int> temp) {
	for (auto it = temp.begin(); it != temp.end();) {
		if (Node[*it].task.count(n) == 1) {
			temp.erase(it);
		}
		else it++;
	}
	return temp;
}

int main() {
#ifdef inline
	freopen("stdin.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m; //n���ڵ㣬m����
	int i = 1;

	vector<int> idsum;
	while (i <= n) {
		int temp;
		cin >> temp;
		Node.insert(pair<int, node>(i, node{ i,temp,0,set<int>() }));
		idsum.push_back(i);
		i++;
	}
	


	int T; cin >> T;
	while (T--) {
		int a1, a2, a3, a4, a5, a6;
		cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;

		

		while (a1--) {
			vector<int> temp = idsum, temp2;
			//����ڵ��׺���
			if (a3 != 0) {
				fax1(a3, temp);
			}
			//���������׺���
			if (a4 != 0) {
				fax2(a4, temp);
			}
			//���������׺���
			if (a5 != 0) {
				temp2 = fax3(a5, temp);
			}
			//���������׺���Ҫ���Ǳ�����������޿��ýڵ�   �� ������ ���������׺���Ҳ�޿��ýڵ� 
			if ((temp2.empty() && a6 == 1) || temp.empty()) {
				cout << 0 << " ";
				continue;
			}
			//���������׺���Ҫ���Ǿ�������� �� �޿��ýڵ�   �� ������ ���������׺��� 
			else if (temp2.empty() && a6 == 0) {
				temp2 = temp;
			}
			//���� ���սڵ�����е���ҵ������� 
			sort(temp2.begin(), temp2.end(), [](const auto& a, const auto& b)->bool {
				return Node[a] < Node[b];
				});
			//���½ڵ���Ϣ 
			Node[temp2[0]].nums++;
			Node[temp2[0]].task.insert(a2);
			cout << Node[temp2[0]].id << " ";


		}
		cout << endl;

	}
	return 0;
}
