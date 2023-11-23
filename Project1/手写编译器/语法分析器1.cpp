#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

struct token {
    string type;
    string value;
};

class Parser {
public:
    Parser(vector<token>& tokens) : tokens(tokens) {}
    //解析整数
    int parse_number() {
        int result = stoi(tokens[current_token].value);
        current_token++;
        return result;
    }
    //解析因子
    int parse_factor() {
        if (tokens[current_token].type == "NUMBER") {
            cout << "NUMBER" << "  ";
            int num = parse_number();
            cout << num << endl;
            return num;
        }
        else if (tokens[current_token].type == "LPAREN") {
            cout << "LPAREN" << "  ";
            cout << tokens[current_token].value << endl;
            current_token++; // 消耗左括号
            int result = parse_expression();
            if (tokens[current_token].type != "RPAREN") {
                throw runtime_error("Expected RPAREN");
            }
            cout << "RPAREN" << "  ";
            cout << tokens[current_token].value << endl;
            current_token++; // 消耗右括号
            return result;
        }
        else {
            throw runtime_error("Invalid syntax");
        }
    }
    //解析单项式
    int parse_term() {
        int result = parse_factor();
        while (current_token < tokens.size() &&(tokens[current_token].type == "MULT" ||tokens[current_token].type == "DIV"|| tokens[current_token].type == "MOD")) {
            string op = tokens[current_token].type;
            string val = tokens[current_token].value;
            current_token++; // 消耗运算符
            int factor = parse_factor();
            if (op == "MULT") {
               /* cout << "MULT" << " ";
                cout << val << endl;*/
                cout << result << "*" << factor << endl;
                result *= factor;

            }
            else if (op=="MOD") {
                /*cout << "MOD" << " ";
                cout << val << endl;*/
                cout << result << "%" << factor << endl;
                result %= factor;
            }
            else {
                /*cout << "DIV" << " ";
                cout << val << endl;*/
                cout << result << "/" << factor << endl;
                result /= factor;
            }
        }
        return result;
    }
    //解析表达式2+5*(9-8)
    int parse_expression() {
        int result = parse_term();
        while (current_token < tokens.size()&&(tokens[current_token].type == "PLUS" ||tokens[current_token].type == "MINUS")){
            string op = tokens[current_token].type;
            current_token++; // 消耗运算符
            int term = parse_term();
            if (op == "PLUS") {
                cout << result << "+" << term << endl;
                result += term;
            }
            else {
                cout << result << "-" << term << endl;
                result -= term;
            }
        }
        return result;
    }

    void parse() {
        current_token = 0;
        parse_expression();
    }

private:
    vector<token> tokens;
    int current_token;
};

int main() {//2+3*(5+3)
    vector<token> tokens = {
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
        {"NUMBER", "8"},
    };
    Parser parser(tokens);
    parser.parse();
    system("pause");
    return 0;
}

/*
      NUMBER 2
      PLUS +
      NUMBER 3
      MULT *
      NUMBER 4
      DIV /
      NUMBER 5
      MOD %
      NUMBER 6
      MINUS -
      NUMBER 7
      LUS +
      NUMBER 8


*/