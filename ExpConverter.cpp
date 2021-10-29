#include "ExpConverter.hpp"
#include "Stack.hpp"
#include <math.h>

void ExpConverter::printError(string msg) {
    std::cout << msg << std::endl;
}

bool ExpConverter::isOperator(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

bool ExpConverter::isOperator(string s) {
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
    return to_string(result);
}

string ExpConverter::evaluatePostfix(const string postfix) {
    return std::string();
}

string ExpConverter::convertInfix(const string &infix) {
    return std::string();
}

bool ExpConverter::precedence(char lOperator, char rOperator) {
    return false;
}
