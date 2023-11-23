#include <iostream>
#include <string>

using namespace std;

// �ڵ�����
enum class NodeType {
    NUMBER,//����
    BINARY_OPERATOR,//��Ԫ��������
};

// ��Ԫ�����
enum class BinaryOperatorType {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
};

// �ڵ���
class Node {
public:
    virtual ~Node() {};
};

// ���ֽڵ�
class NumberNode : public Node {
public:
    int value;
    NumberNode(int v) : value(v) {}
};

// ��Ԫ������ڵ�
class BinaryOperatorNode : public Node {
public:
    BinaryOperatorType op;
    Node* left, * right;
    BinaryOperatorNode(BinaryOperatorType o, Node* l, Node* r)
        : op(o), left(l), right(r) {}
};

// ��������
class Parser {
public:
    Parser(string input) : input_(input), pos_(0) {}
    Node* parse() {
        return parseExpression();
    }
private:
    string input_;
    int pos_;

    // ��ȡ��һ���ַ�
    char getNextToken() {
        if (pos_ > input_.length()) {
            return '\0'; // ����
        }
        return input_[pos_++];
    }

    // Ԥ����һ���ַ�
    char peekNextToken() {
        if (pos_ > input_.length()) {
            return '\0'; // ����
        }
        return input_[pos_];
    }

    // �������ֽڵ�
    Node* parseNumber() {
        int value = 0;
        char c;
        while (isdigit(c = getNextToken())) {
            value = value * 10 + (c - '0');
        }
        return new NumberNode(value);
    }

    // �������ʽ
    Node* parseExpression() {
        Node* left = parseTerm();
        BinaryOperatorType op;
        while (peekNextToken() == '+' || peekNextToken() == '-') {
            char c = getNextToken();
            if (c == '+') {
                op = BinaryOperatorType::PLUS;
            }
            else {
                op = BinaryOperatorType::MINUS;
            }
            Node* right = parseTerm();
            left = new BinaryOperatorNode(op, left, right);
        }
        return left;
    }

    // ������
    Node* parseTerm() {
        Node* left = parseFactor();
        BinaryOperatorType op;
        while (peekNextToken() == '*' || peekNextToken() == '/') {
            char c = getNextToken();
            if (c == '*') {
                op = BinaryOperatorType::MULTIPLY;
            }
            else {
                op = BinaryOperatorType::DIVIDE;
            }
            Node* right = parseFactor();
            left = new BinaryOperatorNode(op, left, right);
        }
        return left;
    }

    // ��������
    Node* parseFactor() {
        char c = getNextToken();
        if (isdigit(c)) {
            pos_--;
            return parseNumber();
        }
        else if (c == '(') {
            Node* n = parseExpression();
            pos_++; // ����������
            return n;
        }
        return nullptr; // ����
    }
};

// ����AST��������ʽ��ֵ
int eval(Node* node) {
    BinaryOperatorNode* binary_operator_node = dynamic_cast<BinaryOperatorNode*>(node);
    if (binary_operator_node != nullptr) {
        switch (binary_operator_node->op) {
        case BinaryOperatorType::PLUS:
            return eval(binary_operator_node->left) + eval(binary_operator_node->right);
        case BinaryOperatorType::MINUS:
            return eval(binary_operator_node->left) - eval(binary_operator_node->right);
        case BinaryOperatorType::MULTIPLY:
            return eval(binary_operator_node->left) * eval(binary_operator_node->right);
        case BinaryOperatorType::DIVIDE:
            return eval(binary_operator_node->left) / eval(binary_operator_node->right);
        }
    }

    NumberNode* number_node = dynamic_cast<NumberNode*>(node);
    if (number_node != nullptr) {
        return number_node->value;
    }

    // ����
    return -1;
}

int main() {
    string input = "1+3*(4-1)+2";
    Parser parser(input);
    Node* root = parser.parse();

    // ���AST
    system("pause");
    return 0;
}