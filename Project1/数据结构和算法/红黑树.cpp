/*
* �����Ҳ����ƽ��Ķ�������������֮AVL��ɾ���Ͳ������ת��������
* 
* �����������
*   1.���нڵ㶼��������ɫ:�����
    2.����null��Ϊ��ɫ
    3.��ɫ�ڵ㲻������
    4.���ڵ��Ǻ�ɫ
    5.�Ӹ�������һ��Ҷ�ӽڵ㣬·���еĺ�ɫ�ڵ���һ������ɫ����ƽ�⣩
*/
#include<iostream>
using namespace std;

typedef struct Color {
    unsigned char red;
    unsigned char black;
}Color;

Color* col;
typedef struct TReeredback {
    int key;
    string value;
    struct TReeredback* left;
    struct TReeredback* right;
    struct TReeredback* parent;//���ڵ�
    char color = col->red;//��ɫ

}TReeredback;

TReeredback* root;

//�����в���Ԫ��
TReeredback* pull(int key, string value, TReeredback* node1, TReeredback* node2) {
    TReeredback* tep = new TReeredback;
    tep->key = key;
    tep->value = value;
    tep->left = node1;
    tep->right = node2;
    return tep;
}


//������
TReeredback* ctreantree() {
    /*
      4
     / \
    2    6
   / \  / \
  1   3 5  7

    */

    TReeredback* n1 = pull(1, "aaa", NULL, NULL);
    TReeredback* n3 = pull(3, "bbb", NULL, NULL);
    TReeredback* n2 = pull(2, "ccc", n1, n3);

    TReeredback* n5 = pull(5, "fff", NULL, NULL);
    TReeredback* n7 = pull(7, "yyy", NULL, NULL);
    TReeredback* n6 = pull(6, "uuu", n5, n7);

    TReeredback* n4 = pull(4, "mmm", n2, n6);
    return n4;
}





//�Ƿ�������
bool isleftchild(TReeredback*node) {
    if (node->parent != NULL&&node->parent->left==node) {
        return true;
    }
    return false;
}


//������
TReeredback* uncle1(TReeredback* node) {
    if (node->parent == NULL || node->parent->parent == NULL) {
        return NULL;
    }


    if (node->parent == node->parent->parent->left) {
        return node->parent->parent->right;
    }
    else{
        return node->parent->parent->left;
    }
}


//���ֵ�
TReeredback* sibling1(TReeredback* node) {
    if (node->parent==NULL) {
        return NULL;
    }

    if (node==node->parent->left) {
        return node->parent->right;
    }
    else {
        return node->parent->left;
    }
}


//�ж� ��
bool isRed(TReeredback* node) {
    return node != NULL && node->color == col->red;
}

//�ж� ��
bool isBlack(TReeredback* node) {
    //return !isRed(node);
    return node == NULL || node->color == col->black;
}

//����  1.parent�Ĵ���  2.��ת�����¸��ĸ��ӹ�ϵ
void rightrotate(TReeredback*pink) {
    TReeredback* parent = pink->parent;//��ɫ����

    TReeredback* yellow = pink->left;
    TReeredback* green = yellow->right;

    yellow->right = pink;
    pink->left = green;

    //1.parent�Ĵ���
    if (green!=NULL) {
        green->parent = pink;
    }
    yellow->parent = parent;
    pink->parent = yellow;

    //2.��ת�����¸��ĸ��ӹ�ϵ
    if (parent==NULL) {
        root = yellow;
    }
    else if (parent->left==pink) {
        parent->left = yellow;
    }
    else {
        parent->right = yellow;
    }
}

//����  1.parent�Ĵ���  2.��ת�����¸��ĸ��ӹ�ϵ
void leftrotate(TReeredback* pink) {

    TReeredback* parent = pink->parent;//��ɫ����

    TReeredback* yellow = pink->right;
    TReeredback* green = yellow->left;

    yellow->left = pink;
    pink->right = green;

    //1.parent�Ĵ���
    if (green!=NULL) {
        green->parent = pink;
    }
    
    pink->parent = yellow;
    yellow->parent = parent;

    //2.��ת�����¸��ĸ��ӹ�ϵ
    if (parent == NULL) {
        root = yellow;
    }
    else if (parent->left==pink) {
        parent->left = yellow;
    }
    else {
        parent->right = yellow;
    }
}


//�������
void fixredred(TReeredback*node) {

    //case1 ����ڵ��Ǹ��ڵ㣬��ڼ���
    if (node == root) {
        node->color = col->black;
        return;
    }

    //case2 ����ڵ�ĸ��ڵ��Ǻ�ɫ���������
    else if(isBlack(node->parent)){
        return;
    }
    //case3  ����ڵ�ĸ��ڵ��Ǻ�ɫ(�����������)���������Ǻ�ɫ��
    //��Ҫ�����ס������ڣ��游��죬Ȼ����游���еݹ鴦��
    TReeredback* parent = node->parent;
    TReeredback* uncle= uncle1(node);
    TReeredback* grandparent = parent->parent;
    if (isRed(uncle)) {
        parent->color = col->black;
        uncle->color = col->black;
        grandparent->color = col->red;
        fixredred(grandparent);
        return;
    }

    //case4   ����ڵ�ĸ��ڵ��Ǻ�ɫ(�����������)���������Ǻ�ɫ
    
    // 4.1 ���ڵ������ӣ�����ڵ������ӣ���ʱLL��ƽ��
    if (isleftchild(parent)&& isleftchild(node)) {
        parent->color = col->black;//���ڵ���
        grandparent->color = col->red;//�游�ڵ���
        rightrotate(grandparent);//�游�ڵ�����

    }
    //4.2 ���ڵ������ӣ�����ڵ����Һ��ӣ���ʱLR��ƽ��
    else if (isleftchild(parent)&& !isleftchild(node)) {
        leftrotate(parent);//���ڵ�����
        node->color = col->black;//����Ľڵ��ʱ��Ϊ���ڵ㣬����Ϊ��ɫ
        grandparent->color = col->red;//�游�ڵ���
        rightrotate(grandparent);//�游�ڵ�����
    }
     //4.3 ���ڵ����Һ��ӣ�����ڵ����Һ��ӣ���ʱRR��ƽ��
    else if (!isleftchild(parent) && !isleftchild(node)) {
        parent->color = col->black;//���ڵ���
        grandparent->color = col->red;//�游�ڵ���
        leftrotate(grandparent);//�游�ڵ�����
    }
    // 4.4 ���ڵ����Һ��ӣ�����ڵ������ӣ���ʱRL��ƽ��
    else {
        rightrotate(parent);//���ڵ�����
        node->color = col->black;//����Ľڵ��ʱ��Ϊ���ڵ㣬����Ϊ��ɫ
        grandparent->color = col->red;//�游�ڵ���
        leftrotate(grandparent);//�游�ڵ�����
    }
}



//���������
//�������������ӹ�ϵ��������첻ƽ�⣬���е���
void put(int key,string value) {

    TReeredback* p = root;
    TReeredback* parent = NULL;

    while (p!=NULL) {
        parent = p;
        if (key < p->key) {
            p = p->left;
        }
        else if (key > p->key) {
            p = p->right;
        }
        else {
            p->value = value;
            return;
        }
    }

    TReeredback* newnode = pull(key,value,NULL,NULL);

    if (parent==NULL) {
        root = newnode;
        return;
    }
    else if (key < parent->key) {
        parent->left = newnode;
    }
    else {
        parent->right = newnode;
    }

    newnode->parent = parent;

    fixredred(newnode);//�������

}

//�ҵ�Ҫɾ���Ľڵ�
TReeredback* find(int key) {
    TReeredback* tep = root;
    while (tep!=NULL) {
        if (key < tep->key) {
            tep = tep->left;
        }
        else if (tep->key < key) {
            tep = tep->right;
        }
        else {
            return tep;
        }
    }
    return NULL;
}


//�ҵ�ɾ���ڵ��ʣ�µĽڵ�
TReeredback* findReplaced(TReeredback*deleted) {
    //ɾ���ڵ�û�к���
    if (deleted->left==NULL&& deleted->right==NULL) {
        return NULL;
    }
    //ɾ���ڵ�ֻ��һ������
    else if (deleted->left == NULL) {
        return deleted->right;
    }
    else if (deleted->right == NULL) {
        return deleted->left;
    }

    //ɾ���ڵ�����������
    TReeredback* s = deleted->right;//ɾ���ڵ�ĺ�̽ڵ�
    while (s->left != NULL) {
        s = s->left;
    }
    return s;
}



//ɾ���ڵ��ʣ��ڵ㶼�Ǻ�ɫ������˫��---������һ����
//����˫�ڣ�case3 case4 case5)
void fixdoubleblack(TReeredback*x) {
    if (x == root) {
        return;
    }
    TReeredback* parent = x->parent;
    TReeredback* sibling = sibling1(x);
   // case3 �������ڵ���ֵ�Ϊ��ɫ����ʱ����ֶ�ӱ�Ϊ��ɫ
    if (isRed(sibling)) {
        if (isleftchild(x)) {
            leftrotate(parent);
        }
        else {
            rightrotate(parent);
        }
        parent->color = col->red;
        sibling->color = col->black;
        fixdoubleblack(x);
        return;
   }
    
   
    if (sibling!=NULL) {
        // case4 �������ڵ���ֵ�Ϊ��ɫ����ʱ����ֶ�Ӷ�Ϊ��ɫ
        /*
        * 1.���ֵܱ�죬Ŀ���ǽ�ɾ���ڵ���ֵ��Ǳߵĺ�ɫ�߶�ͬʱ��1
        * 2.��������Ǻ�ɫ���轫���ױ�ڣ������죬��ʱ·����ɫ�ڵ���Ŀ����
        * 3.��������Ǻ�ɫ��˵������·����һ���ڣ��ٴ��ø��ڵ㴥���ں�
        */
        if (isBlack(sibling->left) && isBlack(sibling->right)){
            sibling->color = col->red;
            if (isRed(parent)) {
                parent->color = col->black;
            }
            else {
                fixdoubleblack(parent);
            }
        }
        // case5 �������ڵ���ֵ�Ϊ��ɫ�������и�ֶ��Ϊ��ɫ
        /*
        * 1.����ֵ������ӣ���ֶ���Ǻ죬LL��ƽ�⣨������ɫ��Ӱ�������
        * 2.����ֵ������ӣ���ֶ���Ǻ죬LR��ƽ��
        * 3.����ֵ����Һ��ӣ���ֶ���Ǻ죬RR��ƽ��
        * 4.����ֵ����Һ��ӣ���ֶ���Ǻ죬RL��ƽ��
        */
        else {
            //1.LL
            if (isleftchild(sibling)) {
                if (isRed(sibling->left)) {
                    rightrotate(parent);
                    sibling->left->color = col->black;
                    sibling->color = parent->color;
                    
                }
                //2.LR
                else if (isRed(sibling->right)){
                    sibling->right->color = parent->color;
                    leftrotate(sibling);
                    rightrotate(parent);
                   
                }
                parent->color = col->black;
            }
            else {
                //3.RR
                if (isRed(sibling->right)) {
                    leftrotate(parent);
                    sibling->color = parent->color;
                    sibling->right->color = col->black;

                }
                //4.RL
                else if (isRed(sibling->left)) {
                    sibling->left->color = parent->color;
                    rightrotate(sibling);
                    leftrotate(parent);
                    
                }
                parent->color = col->black;
            }
        }
    }
    else {
        fixdoubleblack(parent);
    }

}


//ɾ��--�ڲ�ʹ��  

/*
  ����ɾ���ڵ����ɫ��
  1.��ɫ-->�ض�ʧ��  
  2.��ɫ-->��ת��Ϊɾ����ɫ�ڵ�(��ʱ��ɫ�ڵ�ض���������ɫ���ӣ���Ϊ��ɫ�ڵ�ֻ��һ��������Ϊ��ɫ����ƽ��)����Ӱ��(��ʱ��ɫ�ڵ�ΪҶ�ӽڵ�)��
  ��˺�ɫ�ڵ����迼��
*/
void doRemove(TReeredback* deleted) {

    TReeredback* replaced = findReplaced(deleted);//ɾ���ڵ�ʣ��Ľڵ�

    TReeredback* parent = deleted->parent;

    //1.��ɾ���ڵ�û�к���
    if (replaced == NULL) {
        //case1.ɾ���ڵ��Ǹ��ڵ�
        if (deleted==root) {
            root = NULL;
        }
        else {
            //��ɾ���ڵ��Ǻ�ɫ
            if (isBlack(deleted)) {
                fixdoubleblack(deleted);//�����ں�
            }
            else {
                //��ɫҶ�ӣ��������
            }


            if (isleftchild(deleted)) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            deleted->parent = NULL;
        }

        return;
    }

    //2.��ɾ���ڵ���һ������
    if (deleted->left==NULL|| deleted->right==NULL) {
        //case1.ɾ���ڵ��Ǹ��ڵ�
        if (deleted == root) {
            root->key = replaced->key;
            root->value = replaced->value;
            root->left = root->right = NULL;
        }
        else {
        
            if (isleftchild(deleted)) {
                parent->left = replaced;
            }
            else {
                parent->right= replaced;
            }

            replaced->parent = parent;
            deleted->left=deleted->right=deleted->parent = NULL;

            //��ʱɾ���ڵ���Ǻ�ɫ��ʣ��ڵ��Ǻ�ɫ���ɫ
            if (isBlack(deleted)&& isBlack(replaced)) {
                fixdoubleblack(replaced);//�����ں�
            }
            else {
                //case 2 �� ɾ���ڵ��Ǻ�ɫ��ʣ��ڵ��Ǻ�ɫ ������Ҫ��ʣ��ڵ���ɫ 
                replaced->color = col->black;
            }
        }
        return;
    }

    //3.��ɾ���ڵ����Һ��Ӷ���
    
    //�� ɾ���ڵ� ���������� ת��Ϊ ֻ��һ������ �� û�к���
    
    //����ɾ���ڵ����̽ڵ��key
    int tep = deleted->key;
    deleted->key = replaced->key;
    replaced->key = tep;

    //����ɾ���ڵ����̽ڵ��value
    string val = deleted->value;
    deleted->value= replaced->value;
    replaced->value = val;

    doRemove(replaced);
}



//ɾ����
//����ɾ�����õ�����ҽ����ɣ������ںڲ�ƽ�⣬���е���
void remove1(int key) {
    TReeredback* deleted = find(key);
    if (deleted==NULL) {
        return;
    }

    doRemove(deleted);
}



int main() {

	system("pause");
	return 0;
}