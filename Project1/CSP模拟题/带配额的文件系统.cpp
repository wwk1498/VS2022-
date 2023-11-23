#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct TreeNode {
	string m_filename;
	std::vector< TreeNode*> children;// 子节点的集合
}TreeNode;


class File {
public:
	int m_size;//配额大小
	TreeNode* root;//根节点

	File() {
		this->m_size = 0;
		this->root = NULL;
	}
	//判断该节点与其孩子节点是否存在对应字符串
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


	//添加子孩子节点
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

	//创建普通文件
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
	//移除文件
	void pull() {

	 }
	//设置配额值
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