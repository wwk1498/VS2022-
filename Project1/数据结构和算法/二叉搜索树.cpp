#include<iostream>
#include<stack>//栈头文件
#include<vector>
using namespace std;

typedef  struct Treenode {
	int key;//关键字
	string value;//值
	Treenode* left;//前驱
	Treenode* right;//后继
}Treenode;

Treenode* root;//根节点
std::stack<Treenode*> stackObject;//创建栈对象
std::vector<string> w;
std::vector<string> Y;
std::vector<string> Q;

//向树中插入元素
Treenode* pull(int key,string value, Treenode*node1, Treenode*node2) {
	Treenode* tep = new Treenode;
	tep->key = key;
	tep->value = value;
	tep->left = node1;
	tep->right = node2;
	return tep;
}

//创建树
Treenode* ctreantree() {
	Treenode* n1 = pull(1, "aaa", NULL, NULL);
	Treenode* n3 = pull(3, "bbb", NULL, NULL);
	Treenode* n2 = pull(2, "ccc", n1, n3);

	Treenode* n5 = pull(5, "fff", NULL, NULL);
	Treenode* n7 = pull(7, "yyy", NULL, NULL);
	Treenode* n6 = pull(6, "uuu", n5, n7);

	Treenode* n4 = pull(4, "mmm", n2, n6);
	return n4;

}

//递归返回关键字对应的值
string doget(Treenode*node,int key) {
	if (node == NULL) {
		return "NULL";
	}
	else if (key < node->key) {
		return doget(node->left, key);
	}
	else if(key>node->key){
		return doget(node->right, key);
	}
	else {
		return node->value;
	}
}


//查找关键字对应的值--递归实现
string get2(int key) {
	return doget(root, key);
}

//查找关键字对应的值--非递归实现
string get1(int key) {
	Treenode* node = root;
	while (node != NULL) {
		if (key < node->key) {
			node = node->left;
		}
		else if (node->key < key) {
			node = node->right;
		}
		else {
			return node->value;
		}
	}
	return "NULL";
}

//递归返回最小关键字对应的值
string domin(Treenode* node) {
	if (node == NULL) {
		return "NULL";
	}
	if (node->left == NULL) {
		return node->value;
	}
	return domin(node->left);
}

//查找最小关键字对应的值
string  min() {
	return domin(root);
}

//查找任意最小关键字对应的值--非递归
string  min1(Treenode* node) {
	Treenode* tep = node;
	if (tep == NULL) {
		return "NULL";
	}
	while (tep->left!=NULL) {
		tep = tep->left;
	}
	return tep->value;
}


//查找任意最大关键字对应的值--非递归
string max1(Treenode* node) {
	Treenode* tep = node;
	if (tep == NULL) {
		return "NULL";
	}
	while (tep->right != NULL) {
		tep = tep->right;
	}
	return tep->value;
}

//查找最大关键字对应的值--非递归
string max() {
	return max1(root);
}

//存储关键字和对应值
void put(int key,string val) {
	Treenode* node=root;
	Treenode* tep = NULL;
	while (node != NULL) {
		tep = node;
		if (key < node->key) {
			node = node->left;
			}
		else if (node->key < key) {
			node = node->right;
			}
		else {
			node->value = val;
			return;
			}
		}

		Treenode* newnode= pull(key, val, NULL, NULL);
		if (tep == NULL) {
			root = newnode;
			return;
		}
		if (key < tep->key) {
			tep->left = newnode;
		}
		else if (tep->key < key) {
			tep->right = newnode;
		}
}

//查找关键字的前驱值
string successor(int key) {
	Treenode* node = root;
	Treenode* nodefromleft = NULL;
	while (node!=NULL) {
		if (key<node->key) {
			node = node->left;
		}
		else if (node->key<key) {
			nodefromleft = node;//记录自左而来的祖先节点
			node = node->right;
		}
		else {
			break;
		}
	}

	//没找到节点
	if (node==NULL) {
		return "NULL";
	}

	//情况1，该节点有左子树，前驱是左子树的最大值
	if (node->left!=NULL) {
		return max1(node->left);
	}
	//情况2，该节点无左子树，若离它最近自左而来的祖先则是前驱
	return nodefromleft != NULL ? nodefromleft->value : "NULL";
}



//查找关键字的后继值
string predecessor(int key) {
	Treenode* node = root;
	Treenode* nodefromright = NULL;
	while (node != NULL) {
		if (key < node->key) {
			nodefromright = node;//记录自右而来的祖先节点
			node = node->left;
		}
		else if (node->key < key) {
			node = node->right;
		}
		else {
			break;
		}
	}

	//没找到节点
	if (node == NULL) {
		return "NULL";
	}

	//情况1，该节点有右子树，后继是右子树的最小值
	if (node->right != NULL) {
		return min1(node->right);
	}
	//情况2，该节点无右子树，若离它最近自右而来的祖先则是后继
	return nodefromright != NULL ? nodefromright->value : "NULL";
}



//托孤方法   parent---被删除节点的父节点    deleted---删除节点    child---被顶上去的结点
void shift(Treenode*parent, Treenode*deleted, Treenode*child) {
	if (parent == NULL) {
		root = child;
	}
	else if (deleted==parent->left) {
		parent->left = child;
	}
	else if (deleted==parent->right) {
		parent->right = child;
	}
}



//根据关键字删除--非递归
string  deletel(int key) {
	Treenode* node = root;
	Treenode* parent = NULL;
	while (node != NULL) {
		if (key < node->key) {
			parent = node;//记录父节点
			node = node->left;
		}
		else if (node->key < key) {
			parent = node;//记录父节点
			node = node->right;
		}
		else {
			break;
		}
	}

	//找不到节点
	if (node==NULL) {
		return "NULL";
	}
	//1.删除节点没有左孩子，把右孩子托孤给parent
	if (node->left==NULL&&node->right!=NULL) {
		shift(parent, node, node->right);
	}
	//2.删除节点没有右孩子，把左孩子托孤给parent
	else if (node->left != NULL && node->right == NULL) {
		shift(parent, node, node->left);
	}
	//3.删除节点没有左、右孩子，已经包含在情况1和2中
	


	//4.删除节点左、右孩子都有，分为相邻和不相邻两种情况
	//4.1被删除节点找后继
	Treenode* s = node->right;//后继节点为s
	Treenode* sparent =node;//后继的父节点
	while (s->left!=NULL) {
		sparent = s;
		s = s->left;
	}
	if (sparent!=node) {//若后继节点与被删除节点不相邻--即后继节点的父节点不是被删除节点

		//4.2删除节点和后继节点不相邻，则先处理后继的后事
		shift(sparent,s, s->right);//不可能有左孩子
		s->right = node->right;
	}
	//4.3后继取代被删除节点
	shift(parent, node, s);
	s->left = node->left;//后继的左孩子==被删除节点的左孩子

	return node->value;
}



//根据关键字删除--递归方法-内部使用
Treenode* dodelete(Treenode* node,int key,string arr[]) {
	if (node == NULL) {
		return NULL;
	}
	if (key < node->key) {
		node->left = dodelete(node->left, key,arr);
		return node;
	}
	if (node->key < key) {
		node->right = dodelete(node->right, key,arr);
		return node;
	}
	arr[0] = node->value;
	//1.删除节点没有左孩子，把右孩子托孤给parent
	if (node->left == NULL) {
		return node->right;
	}
	//2.删除节点没有右孩子，把左孩子托孤给parent
    if (node->right == NULL) {
	return node->left;
    }
	//3.删除节点没有左、右孩子，已经包含在情况1和2中
	//4.删除节点左、右孩子都有，分为相邻和不相邻两种情况
	Treenode* s = node->right;//后继节点为s
	while (s->left != NULL) {
		s = s->left;
	}
	s->right=dodelete(node->right, s->key,NULL);//从被删除节点的右孩子开始，把后继节点当做被删除的元素进行递归，返回给后继节点
	s->left = node->left;//把被删除节点的左孩子赋值给后继节点的左孩子
	return s;
 }
//根据关键字删除--递归方法-外部使用
string delete2(int key) {
	string value[2];
	root=dodelete(root,key,value);
	return value[0];
}


//找 < key 的所有value
void less1(int key) {
	Treenode* node = root;
	while (node != NULL || !stackObject.empty()) {
		if (node != NULL) {
			stackObject.push(node);
			node = node->left;
		}
		else {
			Treenode* top = stackObject.top();
			stackObject.pop();
			if (top->key<key) {
				w.push_back(top->value);
			}
			else {
				break;
			}
			
			node = top->right;
		}
	}
}

//找 > key 的所有value
void greater1(int key) {
	Treenode* node = root;
	while (node != NULL || !stackObject.empty()) {
		if (node != NULL) {
			stackObject.push(node);
			node = node->right;
		}
		else {
			Treenode* top = stackObject.top();
			stackObject.pop();
			if (top->key > key) {
				Y.push_back(top->value);
			}
			else {
				break;
			}

			node = top->left;
		}
	}
}
//找 >= key1 && <= key2 的所有value
void between1(int key1,int key2) {
	Treenode* node = root;
	while (node != NULL || !stackObject.empty()) {
		if (node != NULL) {
			stackObject.push(node);
			node = node->left;
		}
		else {
			Treenode* top = stackObject.top();
			stackObject.pop();
			if (top->key>=key1&&top->key<=key2) {
				Q.push_back(top->value);
			}
			else if(top->key>key2) {
				break;
			}

			node = top->right;
		}
	}
}

int main() {
	root = ctreantree();
	between1(3, 6);
	for (int i = 0; i < Q.size(); i++) {
		cout << Q[i] << endl;
	}

	system("pause");
	return 0;
}