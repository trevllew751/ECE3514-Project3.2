#include "ExpConverter.hpp"
#include "Stack.hpp"
#include <math.h>

void ExpConverter::printError(string msg) {
    std::cout << msg << std::endl;
}

bool ExpConverter::isOperator(char c) {
    // TODO: Implement support for binary operators
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

bool ExpConverter::isOperator(string s) {
    // TODO: Implement support for binary operators
    return s == "+" || s == "-" || s == "/" || s == "*" || s == "^";
}

bool ExpConverter::isOperand(string s) {
    for (char &c : s) {
        if (!isdigit(c)) { return false; }
    }
    return true;
}

bool ExpConverter::isNotNumericalOperand(string s) {
    for (char &c : s) {
        if (!isdigit(c)) { return true; }
    }
    return false;
}

string ExpConverter::calculate(string operand1, string operand2, string opt) {
    double result = std::stod(operand1);
    double op2 = std::stod(operand2);
    if (opt == "+") {
        result += op2;
    } else if (opt == "-") {
        result -= op2;
    } else if (opt == "*") {
        result *= op2;
    } else if (opt == "/") {
        if (op2 == 0) {
            printError("Error: Division by Zero!");
            return "Undefined";
        } else {
            result /= op2;
        }
    } else {
        result = pow(result, op2);
    }
    std::string trimmed = to_string(result);
    trimmed.erase(trimmed.find_last_not_of('0') + 1, std::string::npos);
    if (trimmed.back() == '.') {
        return trimmed.substr(0, trimmed.size() - 1);
    }
    return trimmed;
}

string ExpConverter::evaluatePostfix(const string postfix) {
    Stack<std::string> operands;
    std::vector<std::string> tokens;
    std::string temp;
    std::string op1;
    std::string op2;
    for (char c : postfix) {
        if (!isspace(c)) {
            temp += c;
        } else {
            tokens.push_back(temp);
            temp = "";
        }
    }
    if (!temp.empty()) {
        tokens.push_back(temp);
    }
    for (std::string &s : tokens) {
        if ((isOperand(s) || isNotNumericalOperand(s)) && !isOperator(s)) {
            operands.push(s);
        } else {
            op2 = operands.peek();
            operands.pop();
            op1 = operands.peek();
            operands.pop();
            operands.push(calculate(op1, op2, s));
        }
    }
    return operands.peek();
}

string ExpConverter::convertInfix(const string &infix) {
    Stack<std::string> operators;
    std::string temp;
    std::string result;
    std::vector<std::string> tokens;
    int numOpenParen = 0;
    int numClosParen = 0;
    int numOperators = 0;
    int numOperands = 0;
    for (char c : infix) {
        if (!isspace(c)) {
            if (c == '(') {
                tokens.push_back("(");
                numOpenParen++;
            } else if (c == ')') {
                tokens.push_back(")");
                numClosParen++;
            } else {
                temp += c;
            }
        } else {
            tokens.push_back(temp);
            temp = "";
        }
    }
    if (!temp.empty()) { tokens.push_back(temp); }
    if (numOpenParen != numClosParen) {
        if (numOpenParen < numClosParen) {
            printError("Error: Missing left parenthesis!");
        } else {
            printError("Error: Missing right parenthesis!");
        }
        return "";
    }
    for (std::string &s : tokens) {
        if (isOperator(s)) {
            numOperators++;
            operators.push(s);
        } else if (isOperand(s) || isNotNumericalOperand(s)) {
            result += s;
            numOperands++;
        } else {
            printError("Error: Invalid input character!");
        }
    }
    if (numOperands != numOperators + 1) {
        if (numOperands <= numOperators) {
            printError("Error: Too few operands!");
        } else {
            printError("Error: Stack has more than one operand left in!");
        }
        return "";
    }
    return std::string();
}

bool ExpConverter::precedence(char lOperator, char rOperator) {
    if (lOperator == rOperator || lOperator == '+' || lOperator == '-') {
        return false;
    } else if (lOperator == '*' || lOperator == '/') {
        if (rOperator == '*' || rOperator == '/' || rOperator == '^') {
            return false;
        } else {
            return true;
        }
    } else {
        return true;
    }
}
