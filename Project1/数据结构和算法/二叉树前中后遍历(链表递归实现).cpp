#include<iostream>
using namespace std;

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//����������Ԫ��
TreeNode* pull(int val) {
	TreeNode* tree= (TreeNode*)malloc(sizeof(TreeNode));
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
	TreeNode* node6= pull(6);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	return node1;
}
//ǰ�����
void preorder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	cout << tree->data << " ";
	preorder(tree->left);
	preorder(tree->right);
}
//�������
void ineorder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	ineorder(tree->left);
	cout << tree->data << " ";
	ineorder(tree->right);
}
//�������
void postorder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << " ";
}

int main() {
	TreeNode*T = offer();
	preorder(T);
	cout << endl;
	ineorder(T);
	cout << endl;
	postorder(T);
	system("pause");
	return 0;
}
