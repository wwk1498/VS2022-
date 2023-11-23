/*
* ���һ���ڵ�����Һ��ӣ��߶Ȳ��1����˽ڵ�ʧ�⣬��Ҫ��ת
* 
* �����������ڲ����ɾ��ʱ���ڵ����ʧ��
* ����ڲ����ɾ��ʱͨ����ת��ʼ���ö�������������ƽ�⣬��Ϊ��ƽ��Ķ���������
* AVL����ƽ��Ķ���������ʵ��֮һ
*/
#include<iostream>
using namespace std;

typedef struct Treeavl {
	int key;
	int height=1;//�߶�
	string value;
	struct Treeavl* left;
	struct Treeavl* right;
}Treeavl;

Treeavl* root;

//�����в���Ԫ��
Treeavl* pull(int key, string value, Treeavl* node1, Treeavl* node2) {
	Treeavl* tep = new Treeavl;
	tep->key = key;
	tep->value = value;
	tep->left = node1;
	tep->right = node2;
	return tep;
}


//������
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


//��ȡ�ڵ�����߶�
int maxheight(Treeavl* node) {
	if (node == NULL) {
		return 0;
	}
	int d1 = maxheight(node->left);
	int d2 = maxheight(node->right);
	return max(d1, d2) + 1;
}

//���½ڵ�߶ȣ�����ɾ ����ת��
void updateheight(Treeavl* node) {
	node->height = maxheight(node);
}

/*
* ƽ������ (balance factor)=�������߶�-�������߶�
* bf=0��-1��1��������ƽ��
* bf > 1,�����̫��
* bf < -1,���ұ�̫��
*/
int bf(Treeavl* node) {
	return maxheight(node->left) - maxheight(node->right);
}

/*
* ʧ���4��״̬��
* 
* LL :ʧ��ڵ�� bf > 1,����߸���
*     ʧ��ڵ�����ӵ�bf >= 0,�������������߸��߻��ߵȸ�
* 
* LR ��ʧ��ڵ�� bf > 1,����߸���
*      ʧ��ڵ�����ӵ�bf < 0,������������ұ߸���
* 
* RL ��ʧ��ڵ�� bf < -1,���ұ߸���
*     ʧ��ڵ���Һ��ӵ�bf >= 0,���Һ����������߸��߻�ȸ�
* 
* RR�� ʧ��ڵ�� bf < -1,���ұ߸���
*      ʧ��ڵ���Һ��ӵ�bf < 0,���Һ���������ұ߸���
*/


//����,�����¸��ڵ�
Treeavl* rightrotate(Treeavl*red) {
	Treeavl* yellow = red->left;
	Treeavl* green = yellow->right;
	yellow->right = red;//��λ
	red->left = green;//����
	updateheight(red);//����red�ڵ�߶�
	updateheight(yellow);//����yellow�ڵ�߶�
	return yellow;
}

//����,�����¸��ڵ�
Treeavl* leftrotate(Treeavl* red) {
	Treeavl* yellow = red->right;
	Treeavl* green = yellow->left;
	yellow->left = red;//��λ
	red->right = green;//����
	updateheight(red);//����red�ڵ�߶�
	updateheight(yellow);//����yellow�ڵ�߶�
	return yellow;
}

//�������ڵ�
Treeavl* LL(Treeavl* node) {
	return rightrotate(node);
}

//�����������������������ڵ�
Treeavl* LR(Treeavl*node) {
	node->left = leftrotate(node->left);
	return rightrotate(node);
}

//�����������������������ڵ�
Treeavl* RL(Treeavl* node) {
	node->right= rightrotate(node->right);
	return leftrotate(node);
}

//�������ڵ�
Treeavl* RR(Treeavl* node) {
	return leftrotate(node);
}


//���ڵ��Ƿ�ʧ�⣬����ƽ��ڵ�
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

	return node;//ƽ�⣬ԭ·����
}

//�ݹ�ʵ�ֲ����½ڵ�--�ڲ�
Treeavl* doput(int key,string value, Treeavl*node) {

	//1.�ҵ���λ�������ڵ�
	if (node == NULL) {
		Treeavl* newnode = pull(key, value, NULL, NULL);
		return newnode;
	}

	//2.key�Ѿ����ڣ�����
	if (node->key == key) {
		node->value = value;
		return node;
	}


	//3.��������
	if (key < node->key) {
		node->left = doput(key, value, node->left);
	}
	else {
		node->right=doput(key, value, node->right);
	}

	updateheight(node);//���½ڵ�߶�
	return balance(node);//����ƽ��ڵ�,������
}


//�ݹ�ʵ�ֲ����½ڵ�--�ⲿ
void put(int key, string value) {
	root = doput(key, value, root);
}

//�ݹ�ʵ��ɾ���ڵ�--�ڲ�
Treeavl* doremove(int key, Treeavl*node) {

	//1.node=NULL
	if (node==NULL) {
		return NULL;
	}

	//2.û�ҵ�key
	if (key < node->key) {
		node->left = doremove(key, node->left);
	}
	else if (key > node->key) {
		node->right = doremove(key, node->right);
	}
	//3.�ҵ�key (1.ֻ��һ������  2.û�к���  3.�������Ӷ��У���Ϊ���ںͲ������������)
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
			Treeavl* s = node->right;//��̽ڵ�
			while (s->left!=NULL) {
				s = s->left;
			}
			//�����Ѱ����ڲ�������
			s->right=doremove(s->key, node->right);//�ӱ�ɾ���ڵ���Һ��ӿ�ʼ���Ѻ�̽ڵ㵱����ɾ����Ԫ�ؽ��еݹ飬���ظ���̽ڵ���Һ���
			s->left = node->left;//�ѱ�ɾ���ڵ�����Ӹ�ֵ����̽ڵ������
			node = s;
		}
	}

	updateheight(node);//���½ڵ�߶�
	return balance(node);//����ƽ��ڵ�,������
}
//�ݹ�ʵ��ɾ���ڵ�--�ⲿ
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