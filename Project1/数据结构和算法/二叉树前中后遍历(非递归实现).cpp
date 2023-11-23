#include<iostream>
#include<stack>//ջͷ�ļ�
using namespace std;

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

std::stack<TreeNode*> stackObject;//����ջ����

//����������Ԫ��
TreeNode* pull(int val) {
	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
	tree->data = val;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
//������������6��Ԫ��
TreeNode* offer() {
	TreeNode* node1 = pull(1);
	TreeNode* node2 = pull(2);
	TreeNode* node3 = pull(3);
	TreeNode* node4 = pull(4);
	TreeNode* node5 = pull(5);
	TreeNode* node6 = pull(6);
	TreeNode* node7 = pull(7);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node7;
	node3->left = node5;
	node3->right= node6;
	return node1;
}

//ǰ����������
void peek(TreeNode* tree) {
	TreeNode* curr = tree;
	while (curr!=NULL ||  !stackObject.empty()){
		if (curr != NULL) {
			cout << curr->data << endl;
			stackObject.push(curr);
			curr = curr->left;
		}
		else {
			TreeNode* top= stackObject.top();
			stackObject.pop();
			cout << top->data << endl;
			curr = top->right;
		}
	}
}

int main() {
	TreeNode* T = offer();
	peek(T);
	system("pause");
	return 0;
}