/*
* 如果一个节点的左右孩子，高度差超过1，则此节点失衡，需要旋转
* 
* 二叉搜索树在插入和删除时，节点可能失衡
* 如果在插入和删除时通过旋转，始终让二叉搜索树保持平衡，称为自平衡的二叉搜索树
* AVL是自平衡的二叉搜索树实现之一
*/
#include<iostream>
using namespace std;

typedef struct Treeavl {
	int key;
	int height=1;//高度
	string value;
	struct Treeavl* left;
	struct Treeavl* right;
}Treeavl;

Treeavl* root;

//向树中插入元素
Treeavl* pull(int key, string value, Treeavl* node1, Treeavl* node2) {
	Treeavl* tep = new Treeavl;
	tep->key = key;
	tep->value = value;
	tep->left = node1;
	tep->right = node2;
	return tep;
}


//创建树
Treeavl* ctreantree() {
	/*
	  4
	 / \
	2    6
   / \  / \
  1   3 5  7

	*/

	Treeavl* n1 = pull(1, "aaa", NULL, NULL);
	Treeavl* n3 = pull(3, "bbb", NULL, NULL);
	Treeavl* n2 = pull(2, "ccc", n1, n3);

	Treeavl* n5 = pull(5, "fff", NULL, NULL);
	Treeavl* n7 = pull(7, "yyy", NULL, NULL);
	Treeavl* n6 = pull(6, "uuu", n5, n7);

	Treeavl* n4 = pull(4, "mmm", n2, n6);
	return n4;
}


//获取节点的最大高度
int maxheight(Treeavl* node) {
	if (node == NULL) {
		return 0;
	}
	int d1 = maxheight(node->left);
	int d2 = maxheight(node->right);
	return max(d1, d2) + 1;
}

//更新节点高度（增、删 、旋转）
void updateheight(Treeavl* node) {
	node->height = maxheight(node);
}

/*
* 平衡因子 (balance factor)=左子树高度-右子树高度
* bf=0，-1，1，则左右平衡
* bf > 1,则左边太高
* bf < -1,则右边太高
*/
int bf(Treeavl* node) {
	return maxheight(node->left) - maxheight(node->right);
}

/*
* 失衡的4种状态：
* 
* LL :失衡节点的 bf > 1,即左边更高
*     失衡节点的左孩子的bf >= 0,即左孩子这边是左边更高或者等高
* 
* LR ：失衡节点的 bf > 1,即左边更高
*      失衡节点的左孩子的bf < 0,即左孩子这边是右边更高
* 
* RL ：失衡节点的 bf < -1,即右边更高
*     失衡节点的右孩子的bf >= 0,即右孩子这边是左边更高或等高
* 
* RR： 失衡节点的 bf < -1,即右边更高
*      失衡节点的右孩子的bf < 0,即右孩子这边是右边更高
*/


//右旋,返回新根节点
Treeavl* rightrotate(Treeavl*red) {
	Treeavl* yellow = red->left;
	Treeavl* green = yellow->right;
	yellow->right = red;//上位
	red->left = green;//换爹
	updateheight(red);//更新red节点高度
	updateheight(yellow);//更新yellow节点高度
	return yellow;
}

//左旋,返回新根节点
Treeavl* leftrotate(Treeavl* red) {
	Treeavl* yellow = red->right;
	Treeavl* green = yellow->left;
	yellow->left = red;//上位
	red->right = green;//换爹
	updateheight(red);//更新red节点高度
	updateheight(yellow);//更新yellow节点高度
	return yellow;
}

//右旋根节点
Treeavl* LL(Treeavl* node) {
	return rightrotate(node);
}

//先左旋左子树，再右旋根节点
Treeavl* LR(Treeavl*node) {
	node->left = leftrotate(node->left);
	return rightrotate(node);
}

//先右旋右子树，再左旋根节点
Treeavl* RL(Treeavl* node) {
	node->right= rightrotate(node->right);
	return leftrotate(node);
}

//左旋根节点
Treeavl* RR(Treeavl* node) {
	return leftrotate(node);
}


//检查节点是否失衡，重新平衡节点
Treeavl* balance(Treeavl* node) {
	if (node == NULL) {
		return NULL;
	}

	if (bf(node) > 1 && bf(node->left)>= 0){//LL
		return LL(node);
	}
	else if (bf(node) > 1 && bf(node->left) < 0) {//LR
		return LR(node);
	}
	else if (bf(node) < -1 && bf(node->right) > 0) {//RL
		return RL(node);
	}
	else if (bf(node) < -1 && bf(node->right) <= 0) {//RR
		return RR(node);
	}

	return node;//平衡，原路返回
}

//递归实现插入新节点--内部
Treeavl* doput(int key,string value, Treeavl*node) {

	//1.找到空位，创建节点
	if (node == NULL) {
		Treeavl* newnode = pull(key, value, NULL, NULL);
		return newnode;
	}

	//2.key已经存在，更新
	if (node->key == key) {
		node->value = value;
		return node;
	}


	//3.继续查找
	if (key < node->key) {
		node->left = doput(key, value, node->left);
	}
	else {
		node->right=doput(key, value, node->right);
	}

	updateheight(node);//更新节点高度
	return balance(node);//重新平衡节点,并返回
}


//递归实现插入新节点--外部
void put(int key, string value) {
	root = doput(key, value, root);
}

//递归实现删除节点--内部
Treeavl* doremove(int key, Treeavl*node) {

	//1.node=NULL
	if (node==NULL) {
		return NULL;
	}

	//2.没找到key
	if (key < node->key) {
		node->left = doremove(key, node->left);
	}
	else if (key > node->key) {
		node->right = doremove(key, node->right);
	}
	//3.找到key (1.只有一个孩子  2.没有孩子  3.两个孩子都有，分为相邻和不相邻两种情况)
	else {
		if (node->left == NULL && node->right == NULL) {
			return NULL;
		}
		else if (node->left==NULL) {
			node = node->right;
		}
		else if (node->right==NULL) {
			node = node->left;
		}
		else {
			Treeavl* s = node->right;//后继节点
			while (s->left!=NULL) {
				s = s->left;
			}
			//相邻已包含在不相邻内
			s->right=doremove(s->key, node->right);//从被删除节点的右孩子开始，把后继节点当做被删除的元素进行递归，返回给后继节点的右孩子
			s->left = node->left;//把被删除节点的左孩子赋值给后继节点的左孩子
			node = s;
		}
	}

	updateheight(node);//更新节点高度
	return balance(node);//重新平衡节点,并返回
}
//递归实现删除节点--外部
void remove1(int key) {
	root = doremove(key, root);
}



int main() {
	root=ctreantree();
	put(10, "ssssss");
	updateheight(root);
	cout << root->height;
	system("pause");
	return 0;
}