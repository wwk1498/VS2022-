/*
* 红黑树也是自平衡的二叉搜索树，较之AVL，删除和插入的旋转次数更少
* 
* 红黑树特征：
*   1.所有节点都有两种颜色:红与黑
    2.所有null视为黑色
    3.红色节点不能相邻
    4.根节点是黑色
    5.从根到任意一个叶子节点，路径中的黑色节点数一样（黑色完美平衡）
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
    struct TReeredback* parent;//父节点
    char color = col->red;//颜色

}TReeredback;

TReeredback* root;

//向树中插入元素
TReeredback* pull(int key, string value, TReeredback* node1, TReeredback* node2) {
    TReeredback* tep = new TReeredback;
    tep->key = key;
    tep->value = value;
    tep->left = node1;
    tep->right = node2;
    return tep;
}


//创建树
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





//是否是左孩子
bool isleftchild(TReeredback*node) {
    if (node->parent != NULL&&node->parent->left==node) {
        return true;
    }
    return false;
}


//找叔叔
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


//找兄弟
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


//判断 红
bool isRed(TReeredback* node) {
    return node != NULL && node->color == col->red;
}

//判断 黑
bool isBlack(TReeredback* node) {
    //return !isRed(node);
    return node == NULL || node->color == col->black;
}

//右旋  1.parent的处理  2.旋转后与新根的父子关系
void rightrotate(TReeredback*pink) {
    TReeredback* parent = pink->parent;//粉色他爹

    TReeredback* yellow = pink->left;
    TReeredback* green = yellow->right;

    yellow->right = pink;
    pink->left = green;

    //1.parent的处理
    if (green!=NULL) {
        green->parent = pink;
    }
    yellow->parent = parent;
    pink->parent = yellow;

    //2.旋转后与新根的父子关系
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

//左旋  1.parent的处理  2.旋转后与新根的父子关系
void leftrotate(TReeredback* pink) {

    TReeredback* parent = pink->parent;//粉色他爹

    TReeredback* yellow = pink->right;
    TReeredback* green = yellow->left;

    yellow->left = pink;
    pink->right = green;

    //1.parent的处理
    if (green!=NULL) {
        green->parent = pink;
    }
    
    pink->parent = yellow;
    yellow->parent = parent;

    //2.旋转后与新根的父子关系
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


//调整红红
void fixredred(TReeredback*node) {

    //case1 插入节点是根节点，变黑即可
    if (node == root) {
        node->color = col->black;
        return;
    }

    //case2 插入节点的父节点是黑色，无需调整
    else if(isBlack(node->parent)){
        return;
    }
    //case3  插入节点的父节点是红色(触发红红相邻)，且叔叔是红色：
    //需要将父亲、叔叔变黑，祖父变红，然后对祖父进行递归处理
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

    //case4   插入节点的父节点是红色(触发红红相邻)，且叔叔是黑色
    
    // 4.1 父节点是左孩子，插入节点是左孩子，此时LL不平衡
    if (isleftchild(parent)&& isleftchild(node)) {
        parent->color = col->black;//父节点变黑
        grandparent->color = col->red;//祖父节点变红
        rightrotate(grandparent);//祖父节点右旋

    }
    //4.2 父节点是左孩子，插入节点是右孩子，此时LR不平衡
    else if (isleftchild(parent)&& !isleftchild(node)) {
        leftrotate(parent);//父节点左旋
        node->color = col->black;//插入的节点此时成为父节点，令其为黑色
        grandparent->color = col->red;//祖父节点变红
        rightrotate(grandparent);//祖父节点右旋
    }
     //4.3 父节点是右孩子，插入节点是右孩子，此时RR不平衡
    else if (!isleftchild(parent) && !isleftchild(node)) {
        parent->color = col->black;//父节点变黑
        grandparent->color = col->red;//祖父节点变红
        leftrotate(grandparent);//祖父节点左旋
    }
    // 4.4 父节点是右孩子，插入节点是左孩子，此时RL不平衡
    else {
        rightrotate(parent);//父节点右旋
        node->color = col->black;//插入的节点此时成为父节点，令其为黑色
        grandparent->color = col->red;//祖父节点变红
        leftrotate(grandparent);//祖父节点左旋
    }
}



//新增或更新
//正常增，处理父子关系，遇到红红不平衡，进行调整
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

    fixredred(newnode);//调整红红

}

//找到要删除的节点
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


//找到删除节点的剩下的节点
TReeredback* findReplaced(TReeredback*deleted) {
    //删除节点没有孩子
    if (deleted->left==NULL&& deleted->right==NULL) {
        return NULL;
    }
    //删除节点只有一个孩子
    else if (deleted->left == NULL) {
        return deleted->right;
    }
    else if (deleted->right == NULL) {
        return deleted->left;
    }

    //删除节点有两个孩子
    TReeredback* s = deleted->right;//删除节点的后继节点
    while (s->left != NULL) {
        s = s->left;
    }
    return s;
}



//删除节点和剩余节点都是黑色，触发双黑---即少了一个黑
//处理双黑（case3 case4 case5)
void fixdoubleblack(TReeredback*x) {
    if (x == root) {
        return;
    }
    TReeredback* parent = x->parent;
    TReeredback* sibling = sibling1(x);
   // case3 被调整节点的兄弟为红色，此时两个侄子必为黑色
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
        // case4 被调整节点的兄弟为黑色，此时两个侄子都为黑色
        /*
        * 1.将兄弟变红，目的是将删除节点和兄弟那边的黑色高度同时减1
        * 2.如果父亲是红色，需将父亲变黑，避免红红，此时路径黑色节点数目不变
        * 3.如果父亲是黑色，说明这条路径少一个黑，再次让父节点触发黑黑
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
        // case5 被调整节点的兄弟为黑色，至少有个侄子为红色
        /*
        * 1.如果兄弟是左孩子，左侄子是红，LL不平衡（父亲颜色不影响操作）
        * 2.如果兄弟是左孩子，右侄子是红，LR不平衡
        * 3.如果兄弟是右孩子，右侄子是红，RR不平衡
        * 4.如果兄弟是右孩子，左侄子是红，RL不平衡
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


//删除--内部使用  

/*
  考虑删除节点的颜色：
  1.黑色-->必定失衡  
  2.红色-->可转换为删除黑色节点(此时红色节点必定有两个黑色孩子，因为红色节点只有一个孩子且为黑色，则不平衡)或无影响(此时红色节点为叶子节点)，
  因此红色节点无需考虑
*/
void doRemove(TReeredback* deleted) {

    TReeredback* replaced = findReplaced(deleted);//删除节点剩余的节点

    TReeredback* parent = deleted->parent;

    //1.即删除节点没有孩子
    if (replaced == NULL) {
        //case1.删除节点是根节点
        if (deleted==root) {
            root = NULL;
        }
        else {
            //若删除节点是黑色
            if (isBlack(deleted)) {
                fixdoubleblack(deleted);//触发黑黑
            }
            else {
                //红色叶子，无需操作
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

    //2.即删除节点有一个孩子
    if (deleted->left==NULL|| deleted->right==NULL) {
        //case1.删除节点是根节点
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

            //此时删除节点必是黑色，剩余节点是黑色或红色
            if (isBlack(deleted)&& isBlack(replaced)) {
                fixdoubleblack(replaced);//触发黑黑
            }
            else {
                //case 2 即 删除节点是黑色，剩余节点是红色 ，则需要把剩余节点变黑色 
                replaced->color = col->black;
            }
        }
        return;
    }

    //3.即删除节点左右孩子都有
    
    //把 删除节点 有两个孩子 转换为 只有一个孩子 或 没有孩子
    
    //交换删除节点与后继节点的key
    int tep = deleted->key;
    deleted->key = replaced->key;
    replaced->key = tep;

    //交换删除节点与后继节点的value
    string val = deleted->value;
    deleted->value= replaced->value;
    replaced->value = val;

    doRemove(replaced);
}



//删除，
//正常删除，用到李代桃僵技巧，遇到黑黑不平衡，进行调整
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