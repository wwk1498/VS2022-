#include <iostream>

// AST节点类型
enum
{
    A_ADD, A_SUB, A_MUL, A_DIV, A_MOD, A_INT
};

// 抽象语法树结构
struct ASTnode
{
    int op;				        // 节点的操作类型
    struct ASTnode* left;
    struct ASTnode* right;
    int intvalue;				// 整数节点的值，没有子树
};
struct ASTnode* mkastnode(int op, struct ASTnode* left, struct ASTnode* right, int intvalue)
{
    struct ASTnode* n;
    n = (struct ASTnode*)malloc(sizeof(struct ASTnode));
    if (n == NULL)
    {
        fprintf(stderr, "Unable to malloc in mkastnode()\n");
        exit(1);
    }
    n->op = op;
    n->left = left;
    n->right = right;
    n->intvalue = intvalue;
    return n;
}


// 生成AST叶子节点
struct ASTnode* mkastleaf(int op, int intvalue)
{
    return mkastnode(op, NULL, NULL, intvalue);
}

// 生成只有一个左孩子的一元AST节点
struct ASTnode* mkastunary(int op, struct ASTnode* left, int intvalue)
{
    return (mkastnode(op, left, NULL, intvalue));
}
// 将单词转换为AST操作
int token_op(int token)
{
    switch (token)
    {
    case T_ADD:    return A_ADD;
    case T_SUB:    return A_SUB;
    case T_MUL:    return A_MUL;
    case T_DIV:    return A_DIV;
    case T_MOD:    return A_MOD;
    default:    fprintf(stderr, "unknown token in token_op() on line %d\n", Line);
        exit(1);
    }
}
struct token	Token;      //当前扫描单词
// 解析一个整数单词并返回表示它的AST节点
struct ASTnode* primary()
{
    struct ASTnode* n;
    // 对于整数单词，为其生成一个AST叶子节点并扫描下一个单词。
    // 否则，语法错误。
    switch (Token.token)
    {
    case T_INT:
        n = mkastleaf(A_INT, Token.intvalue);
        scan(&Token);
        return n;
    default:
        fprintf(stderr, "syntax error on line %d\n", Line);
        exit(1);
    }
}
struct ASTnode* binexpr()
{
    struct ASTnode* n, * left, * right;
    int nodetype;

    // 获取左节点的整数，同时获取下一个单词
    left = primary();

    // 如果下一个单词是文件结尾，则返回左节点
    if (Token.token == T_EOF)   return left;

    // 从单词映射到节点类型
    nodetype = token_op(Token.token);

    // 获取下一个单词
    scan(&Token);

    // 递归得到右子树
    right = binexpr();

    // 将左、右子树合并成一棵树
    n = mkastnode(nodetype, left, right, 0);
    return n;
}
// AST操作符
char* ASTop[] = { "+", "-", "*", "/", "%" };

// 给定一个AST，返回一个表达式
int interpretAST(struct ASTnode* n)
{
    int leftval, rightval;

    // 获得左、右子树值
    if (n->left)    leftval = interpretAST(n->left);
    if (n->right)   rightval = interpretAST(n->right);

    // 调试：打印将要做的事情
    if (n->op == A_INT)    printf("int %d\n", n->intvalue);
    else    printf("%d %s %d\n", leftval, ASTop[n->op], rightval);

    switch (n->op)
    {
    case A_ADD:    return leftval + rightval;
    case A_SUB:    return leftval - rightval;
    case A_MUL:    return leftval * rightval;
    case A_DIV:    return leftval / rightval;
    case A_MOD:    return leftval % rightval;
    case A_INT:    return n->intvalue;
    default:    fprintf(stderr, "Unknown AST operator %d\n", n->op);
        exit(1);
    }
}
// 用法 compiler -o -s outfile infile
int main(int argc, char* argv[])
{
    struct ASTnode* n;
    if (argc != 5)
    {
        fprintf(stderr, "compiler -o -s outfile infile\n");
        exit(1);
    }
    init();
    if ((Infile = fopen(argv[4], "r")) == NULL)
    {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }
    scan(&Token);			            // 从输入中获得第一个单词
    n = binexpr();		                // 解析表达式
    printf("%d\n", interpretAST(n));	// 计算最终的结果
}
