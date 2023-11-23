#include<iostream>
#include<vector>
#include<climits>
#include <string>
#include <stdexcept>
using namespace std;


//定义节点类
class Node {
public:
    string op="";
    Node* left;
    Node* right;
    int value = INT_MAX;
    Node(string o, Node* l, Node* r,int val) : op(o), left(l), right(r),value(val) {}
};

//语法分析器
class Parse {
public:
    //处理表达式
    Node* expression(vector<pair<string, string>>& tokens, int& index);
    //处理因子
    Node* factor(vector<pair<string, string>>& tokens, int& index);
    //处理项
    Node* term(vector<pair<string, string>>& tokens, int& index);
    //输出语法树
    int evaluate(Node* node);
};

//优先级3
Node* Parse::expression(vector<pair<string, string>>& tokens, int& index) {
    Node* left = term(tokens, index);

    while (index < tokens.size()) {
        string op = tokens[index].second;
        if (op == "+" || op == "-") {
            index++;
            Node* right = term(tokens, index);
            left = new Node(op, left, right, INT_MAX);
        }
        else {
            break;
        }
    }
    return left;
}

//优先级1
Node* Parse::factor(vector<pair<string, string>>& tokens, int& index) {
    if (tokens[index].first == "NUMBER") {
        int val = stoi(tokens[index].second);
        index++;
        return new Node("", NULL, NULL, val);
    }
    else if (tokens[index].first == "MINUS") {
        index++;
        Node* node = factor(tokens, index);
        return new Node("-", new Node("", NULL, NULL, 0), node, INT_MAX);
    }
    else if (tokens[index].first == "LPAREN") {
        index++;
        Node* node = expression(tokens, index);
        if (tokens[index].first != "RPAREN") {
            throw runtime_error("Mismatched parentheses");
        }
        index++;
        return node;
    }
    else {
        throw runtime_error("Unexpected token");
    }
}

//优先级2
Node* Parse::term(vector<pair<string, string>>& tokens, int& index) {
    Node* left = factor(tokens, index);

    while (index < tokens.size()) {
        string op = tokens[index].second;
        if (op == "*" || op == "/" || op == "%") {
            index++;
            Node* right = factor(tokens, index);
            left = new Node(op, left, right, INT_MAX);
        }
        else {
            break;
        }
    }

    return left;
}


int Parse::evaluate(Node* node) {
    if (node->value!=INT_MAX) {
        return node->value;
    }
    else if (node->op!="") {
        int left_value = evaluate(node->left);
        int right_value = evaluate(node->right);

        if (node->op=="+") return left_value + right_value;
        else if (node->op == "-")return left_value - right_value;
        else if (node->op == "*")return left_value * right_value;
        else if (node->op == "/")return left_value / right_value;
        else if (node->op == "%")return left_value % right_value;
        else throw runtime_error("Unknown operator");
    }
    else {
        throw runtime_error("Unknown node type");
    }
}

int main() {
    vector<pair<string, string>> tokens = {
        {"MINUS", "-"},
        {"NUMBER", "2"},
        {"PLUS", "+"},
        {"NUMBER", "3"},
        {"MULT", "*"},
        {"NUMBER", "4"},
        {"DIV", "/"},
        {"NUMBER", "5"},
        {"MOD", "%"},
        {"NUMBER", "6"},
        {"MINUS", "-"},
        {"NUMBER", "7"},
        {"PLUS", "+"},
        {"NUMBER", "8"}
    };
    Parse par;
    int index = 0;
    Node* root = par.expression(tokens, index);
    int result = par.evaluate(root);
    cout << result << endl;
    system("pause");
    return 0;
}
