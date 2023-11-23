#include <iostream>
#include <string>

using namespace std;

// 节点类型
enum class NodeType {
    NUMBER,//数字
    BINARY_OPERATOR,//二元混合运算符
};

// 二元运算符
enum class BinaryOperatorType {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
};

// 节点类
class Node {
public:
    virtual ~Node() {};
};

// 数字节点
class NumberNode : public Node {
public:
    int value;
    NumberNode(int v) : value(v) {}
};

// 二元运算符节点
class BinaryOperatorNode : public Node {
public:
    BinaryOperatorType op;
    Node* left, * right;
    BinaryOperatorNode(BinaryOperatorType o, Node* l, Node* r)
        : op(o), left(l), right(r) {}
};

// 解析器类
class Parser {
public:
    Parser(string input) : input_(input), pos_(0) {}
    Node* parse() {
        return parseExpression();
    }
private:
    string input_;
    int pos_;

    // 获取下一个字符
    char getNextToken() {
        if (pos_ > input_.length()) {
            return '\0'; // 结束
        }
        return input_[pos_++];
    }

    // 预览下一个字符
    char peekNextToken() {
        if (pos_ > input_.length()) {
            return '\0'; // 结束
        }
        return input_[pos_];
    }

    // 解析数字节点
    Node* parseNumber() {
        int value = 0;
        char c;
        while (isdigit(c = getNextToken())) {
            value = value * 10 + (c - '0');
        }
        return new NumberNode(value);
    }

    // 解析表达式
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

    // 解析项
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

    // 解析因子
    Node* parseFactor() {
        char c = getNextToken();
        if (isdigit(c)) {
            pos_--;
            return parseNumber();
        }
        else if (c == '(') {
            Node* n = parseExpression();
            pos_++; // 跳过右括号
            return n;
        }
        return nullptr; // 错误
    }
};

// 遍历AST并计算表达式的值
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

    // 错误
    return -1;
}

int main() {
    string input = "1+3*(4-1)+2";
    Parser parser(input);
    Node* root = parser.parse();

    // 输出AST
    system("pause");
    return 0;
}