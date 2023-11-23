#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct TreeNode {
	string m_filename;
	std::vector< TreeNode*> children;// �ӽڵ�ļ���
}TreeNode;


class File {
public:
	int m_size;//����С
	TreeNode* root;//���ڵ�

	File() {
		this->m_size = 0;
		this->root = NULL;
	}
	//�жϸýڵ����亢�ӽڵ��Ƿ���ڶ�Ӧ�ַ���
	bool containsValue(TreeNode* node, string filename) {
		if (node == NULL) {
			return false;
		}
		if (node->m_filename== filename) {
			return true;
		}
		for (TreeNode* child: node->children) {
			if (containsValue(child, filename)) {
				return true;
			}
		}
		return false;
	}


	//����Ӻ��ӽڵ�
	void addchild(TreeNode* node1,string n_filename) {
		if (containsValue(node1, n_filename)) {

		}
		TreeNode* child = new TreeNode;
		child->m_filename = n_filename;
		child->children = {};
		if (this->root != NULL) {
			this->root->children.push_back(child);
		}
		this->root = child;
	}

	//������ͨ�ļ�
	bool offer() {
		string n_filename;
		int n_size;
		cin >> n_filename;
		cin >> n_size;
		int len = n_filename.length();

		for (int i = 0; i < len; i+2) {
			string first = n_filename.substr(i, 2);
			addchild(this->root,first);
		}
		

		
	 }
	//�Ƴ��ļ�
	void pull() {

	 }
	//�������ֵ
	void setup() {

	 }
	
};

int main() {
	File file;
	int n,flag;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> flag;
		if (flag == 'C') {

		}
		else if (flag=='R') {

		}
		else if (flag=='Q') {

		}
	}
	
	system("pause");
	return 0;
}