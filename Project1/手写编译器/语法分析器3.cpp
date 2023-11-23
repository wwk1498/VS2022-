#include <iostream>

// AST�ڵ�����
enum
{
    A_ADD, A_SUB, A_MUL, A_DIV, A_MOD, A_INT
};

// �����﷨���ṹ
struct ASTnode
{
    int op;				        // �ڵ�Ĳ�������
    struct ASTnode* left;
    struct ASTnode* right;
    int intvalue;				// �����ڵ��ֵ��û������
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


// ����ASTҶ�ӽڵ�
struct ASTnode* mkastleaf(int op, int intvalue)
{
    return mkastnode(op, NULL, NULL, intvalue);
}

// ����ֻ��һ�����ӵ�һԪAST�ڵ�
struct ASTnode* mkastunary(int op, struct ASTnode* left, int intvalue)
{
    return (mkastnode(op, left, NULL, intvalue));
}
// ������ת��ΪAST����
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
struct token	Token;      //��ǰɨ�赥��
// ����һ���������ʲ����ر�ʾ����AST�ڵ�
struct ASTnode* primary()
{
    struct ASTnode* n;
    // �����������ʣ�Ϊ������һ��ASTҶ�ӽڵ㲢ɨ����һ�����ʡ�
    // �����﷨����
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

    // ��ȡ��ڵ��������ͬʱ��ȡ��һ������
    left = primary();

    // �����һ���������ļ���β���򷵻���ڵ�
    if (Token.token == T_EOF)   return left;

    // �ӵ���ӳ�䵽�ڵ�����
    nodetype = token_op(Token.token);

    // ��ȡ��һ������
    scan(&Token);

    // �ݹ�õ�������
    right = binexpr();

    // �����������ϲ���һ����
    n = mkastnode(nodetype, left, right, 0);
    return n;
}
// AST������
char* ASTop[] = { "+", "-", "*", "/", "%" };

// ����һ��AST������һ�����ʽ
int interpretAST(struct ASTnode* n)
{
    int leftval, rightval;

    // �����������ֵ
    if (n->left)    leftval = interpretAST(n->left);
    if (n->right)   rightval = interpretAST(n->right);

    // ���ԣ���ӡ��Ҫ��������
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
// �÷� compiler -o -s outfile infile
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
    scan(&Token);			            // �������л�õ�һ������
    n = binexpr();		                // �������ʽ
    printf("%d\n", interpretAST(n));	// �������յĽ��
}
