#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
    bool isWhitespace(char ch) {
        return ch == ' ' || ch == '\t' ||
               ch == '\n' || ch == '\r';
    }

    bool isOperand(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' ||
               ch == '*' || ch == '/' ||
               ch == '%' || ch == '^';
    }

    int precedence(char op) {
        if(op == '^') return 3;
        if(op == '*' || op == '/' || op == '%') return 2;
        if(op == '+' || op == '-') return 1;
        return 0;
    }

public:
    string infixToPostfix(const string& expression) {
        string postfix;
        stack<char> operators;
        bool expectingOperand = true;

        for(int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            if(isWhitespace(ch)) {
                continue;
            }

            if(isOperand(ch)) {
                if(!expectingOperand) return "";

                if(ch >= '0' && ch <= '9') {
                    while(i < expression.length() &&
                          expression[i] >= '0' &&
                          expression[i] <= '9') {
                        postfix += expression[i];
                        i++;
                    }
                    postfix += ' ';
                    i--;
                } else {
                    postfix += ch;
                    postfix += ' ';
                }

                expectingOperand = false;
            }
            else if(ch == '(') {
                if(!expectingOperand) return "";

                operators.push(ch);
            }
            else if(ch == ')') {
                if(expectingOperand) return "";

                while(!operators.empty() &&
                      operators.top() != '(') {
                    postfix += operators.top();
                    postfix += ' ';
                    operators.pop();
                }

                if(operators.empty()) return "";

                operators.pop();
                expectingOperand = false;
            }
            else if(isOperator(ch)) {
                if(expectingOperand) return "";

                while(!operators.empty() &&
                      operators.top() != '(' &&
                      (precedence(operators.top()) > precedence(ch) ||
                       (precedence(operators.top()) == precedence(ch) &&
                        ch != '^'))) {
                    postfix += operators.top();
                    postfix += ' ';
                    operators.pop();
                }

                operators.push(ch);
                expectingOperand = true;
            }
            else {
                return "";
            }
        }

        if(expectingOperand) return "";

        while(!operators.empty()) {
            if(operators.top() == '(') return "";

            postfix += operators.top();
            postfix += ' ';
            operators.pop();
        }

        if(!postfix.empty()) postfix.pop_back();

        return postfix;
    }
};

int main() {
    string expression;

    cout << "Enter an infix expression: ";
    getline(cin, expression);

    Solution solution;
    string postfix = solution.infixToPostfix(expression);

    if(postfix.empty()) {
        cout << "Invalid infix expression" << endl;
        return 1;
    }

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
