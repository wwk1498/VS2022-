#include<iostream>
#include<stack>//ջͷ�ļ�
#include<vector>
using namespace std;

typedef  struct Treenode {
	int key;//�ؼ���
	string value;//ֵ
	Treenode* left;//ǰ��
	Treenode* right;//���
}Treenode;

Treenode* root;//���ڵ�
std::stack<Treenode*> stackObject;//����ջ����
std::vector<string> w;
std::vector<string> Y;
std::vector<string> Q;

//�����в���Ԫ��
Treenode* pull(int key,string value, Treenode*node1, Treenode*node2) {
	Treenode* tep = new Treenode;
	tep->key = key;
	tep->value = value;
	tep->left = node1;
	tep->right = node2;
	return tep;
}

//������
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

//�ݹ鷵�عؼ��ֶ�Ӧ��ֵ
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


//���ҹؼ��ֶ�Ӧ��ֵ--�ݹ�ʵ��
string get2(int key) {
	return doget(root, key);
}

//���ҹؼ��ֶ�Ӧ��ֵ--�ǵݹ�ʵ��
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

//�ݹ鷵����С�ؼ��ֶ�Ӧ��ֵ
string domin(Treenode* node) {
	if (node == NULL) {
		return "NULL";
	}
	if (node->left == NULL) {
		return node->value;
	}
	return domin(node->left);
}

//������С�ؼ��ֶ�Ӧ��ֵ
string  min() {
	return domin(root);
}

//����������С�ؼ��ֶ�Ӧ��ֵ--�ǵݹ�
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


//�����������ؼ��ֶ�Ӧ��ֵ--�ǵݹ�
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

//�������ؼ��ֶ�Ӧ��ֵ--�ǵݹ�
string max() {
	return max1(root);
}

//�洢�ؼ��ֺͶ�Ӧֵ
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

//���ҹؼ��ֵ�ǰ��ֵ
string successor(int key) {
	Treenode* node = root;
	Treenode* nodefromleft = NULL;
	while (node!=NULL) {
		if (key<node->key) {
			node = node->left;
		}
		else if (node->key<key) {
			nodefromleft = node;//��¼������������Ƚڵ�
			node = node->right;
		}
		else {
			break;
		}
	}

	//û�ҵ��ڵ�
	if (node==NULL) {
		return "NULL";
	}

	//���1���ýڵ�����������ǰ���������������ֵ
	if (node->left!=NULL) {
		return max1(node->left);
	}
	//���2���ýڵ�������������������������������������ǰ��
	return nodefromleft != NULL ? nodefromleft->value : "NULL";
}



//���ҹؼ��ֵĺ��ֵ
string predecessor(int key) {
	Treenode* node = root;
	Treenode* nodefromright = NULL;
	while (node != NULL) {
		if (key < node->key) {
			nodefromright = node;//��¼���Ҷ��������Ƚڵ�
			node = node->left;
		}
		else if (node->key < key) {
			node = node->right;
		}
		else {
			break;
		}
	}

	//û�ҵ��ڵ�
	if (node == NULL) {
		return "NULL";
	}

	//���1���ýڵ��������������������������Сֵ
	if (node->right != NULL) {
		return min1(node->right);
	}
	//���2���ýڵ�����������������������Ҷ������������Ǻ��
	return nodefromright != NULL ? nodefromright->value : "NULL";
}



//�й·���   parent---��ɾ���ڵ�ĸ��ڵ�    deleted---ɾ���ڵ�    child---������ȥ�Ľ��
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



//���ݹؼ���ɾ��--�ǵݹ�
string  deletel(int key) {
	Treenode* node = root;
	Treenode* parent = NULL;
	while (node != NULL) {
		if (key < node->key) {
			parent = node;//��¼���ڵ�
			node = node->left;
		}
		else if (node->key < key) {
			parent = node;//��¼���ڵ�
			node = node->right;
		}
		else {
			break;
		}
	}

	//�Ҳ����ڵ�
	if (node==NULL) {
		return "NULL";
	}
	//1.ɾ���ڵ�û�����ӣ����Һ����й¸�parent
	if (node->left==NULL&&node->right!=NULL) {
		shift(parent, node, node->right);
	}
	//2.ɾ���ڵ�û���Һ��ӣ��������й¸�parent
	else if (node->left != NULL && node->right == NULL) {
		shift(parent, node, node->left);
	}
	//3.ɾ���ڵ�û�����Һ��ӣ��Ѿ����������1��2��
	


	//4.ɾ���ڵ����Һ��Ӷ��У���Ϊ���ںͲ������������
	//4.1��ɾ���ڵ��Һ��
	Treenode* s = node->right;//��̽ڵ�Ϊs
	Treenode* sparent =node;//��̵ĸ��ڵ�
	while (s->left!=NULL) {
		sparent = s;
		s = s->left;
	}
	if (sparent!=node) {//����̽ڵ��뱻ɾ���ڵ㲻����--����̽ڵ�ĸ��ڵ㲻�Ǳ�ɾ���ڵ�

		//4.2ɾ���ڵ�ͺ�̽ڵ㲻���ڣ����ȴ����̵ĺ���
		shift(sparent,s, s->right);//������������
		s->right = node->right;
	}
	//4.3���ȡ����ɾ���ڵ�
	shift(parent, node, s);
	s->left = node->left;//��̵�����==��ɾ���ڵ������

	return node->value;
}



//���ݹؼ���ɾ��--�ݹ鷽��-�ڲ�ʹ��
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
	//1.ɾ���ڵ�û�����ӣ����Һ����й¸�parent
	if (node->left == NULL) {
		return node->right;
	}
	//2.ɾ���ڵ�û���Һ��ӣ��������й¸�parent
    if (node->right == NULL) {
	return node->left;
    }
	//3.ɾ���ڵ�û�����Һ��ӣ��Ѿ����������1��2��
	//4.ɾ���ڵ����Һ��Ӷ��У���Ϊ���ںͲ������������
	Treenode* s = node->right;//��̽ڵ�Ϊs
	while (s->left != NULL) {
		s = s->left;
	}
	s->right=dodelete(node->right, s->key,NULL);//�ӱ�ɾ���ڵ���Һ��ӿ�ʼ���Ѻ�̽ڵ㵱����ɾ����Ԫ�ؽ��еݹ飬���ظ���̽ڵ�
	s->left = node->left;//�ѱ�ɾ���ڵ�����Ӹ�ֵ����̽ڵ������
	return s;
 }
//���ݹؼ���ɾ��--�ݹ鷽��-�ⲿʹ��
string delete2(int key) {
	string value[2];
	root=dodelete(root,key,value);
	return value[0];
}


//�� < key ������value
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

//�� > key ������value
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
//�� >= key1 && <= key2 ������value
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