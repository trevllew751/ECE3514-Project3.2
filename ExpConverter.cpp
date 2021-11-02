#include "ExpConverter.hpp"
#include "Stack.hpp"
#include <math.h>
#include <algorithm>

std::string ExpConverter::printError(string msg) {
    std::cout << msg << std::endl;
    return msg;
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
    bool point = false;
    for (char &c : s) {
        if (!isalnum(c)) {
            if (c == '.') {
                if (point) {
                    return false;
                } else {
                    point = true;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

bool ExpConverter::isNotNumericalOperand(string s) {
    bool point = false;
    bool alpha = false;
    for (char &c : s) {
        if (isalpha(c)) {
            alpha = true;
        } else if (!isdigit(c)) {
            if (c == '.' && point) {
                return false;
            } else if (c == '.' && !point){
                point = true;
            } else {
                return false;
            }
        }
    }
    return alpha;
}

string ExpConverter::calculate(string operand1, string operand2, string opt) {
    try {
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
                return "Undefined";
            } else {
                result /= op2;
            }
        } else {
            result = pow(result, op2);
        }
        std::stringstream ss;
        std::string trimmed;
        ss << result;
        trimmed = ss.str();
        return trimmed;
    } catch (...) {
        return "";
    }
}

string ExpConverter::evaluatePostfix(const string postfix) {
    if (postfix.empty()) {
        return "";
    }
    Stack<std::string> operands;
    std::vector<std::string> tokens;
    std::string temp;
    std::string op1;
    std::string op2;
    std::string calculated;
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
            calculated = calculate(op1, op2, s);
            if (calculated == "Undefined") {
                return postfix;
            } else {
                operands.push(calculated);
            }
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
                if (!temp.empty()) {
                    tokens.push_back(temp);
                    temp = "";
                }
                tokens.push_back(")");
                numClosParen++;
            } else {
                if (isOperator(c)) {
                    if (!temp.empty()) {
                        tokens.push_back(temp);
                    }
                    tokens.push_back(std::string(1, c));
                    temp.clear();
                } else {
                    temp += c;
                }
            }
        } else {
            if (!temp.empty()) {
                tokens.push_back(temp);
                temp = "";
            }
        }
    }
    if (!temp.empty()) { tokens.push_back(temp); }
    if (std::all_of(tokens.begin(), tokens.end(), [this](std::string s){return isOperand(s);})) {
        for (auto &s : tokens) {
            result += s;
        }
        return result + " = " + result;
    }
    if (numOpenParen != numClosParen) {
        if (numOpenParen < numClosParen) {
            printError("Error: Missing left parenthesis!");
        } else {
            printError("Error: Missing right parenthesis!");
        }
        std::cout << "Postfix Expression:" << std::endl;
        return "";
    }
    for (std::string &s : tokens) {
        if (isOperator(s)) {
            numOperators++;
            while (!operators.isEmpty()
                   && !precedence(s.at(0), operators.peek().at(0))
                   && operators.peek() != "(") {
                result += operators.peek() + " ";
                operators.pop();
            }
            operators.push(s);
        } else if (s == "(") {
            operators.push("(");
        } else if (s == ")") {
            while (true) {
                if (operators.peek() == "(") {
                    operators.pop();
                    break;
                } else {
                    result += operators.peek() + " ";
                    operators.pop();
                }
            }
        } else if (isOperand(s)/* || isNotNumericalOperand(s)*/) {
            result += s + " ";
            numOperands++;
        } else {
            printError("Error: Invalid input character!");
            std::cout << "Postfix Expression:" << std::endl;
            return "";
        }
    }
    while (!operators.isEmpty()) {
        result += operators.peek() + " ";
        operators.pop();
    }
    result.pop_back();
    if (numOperands != numOperators + 1) {
        std::cout << "Postfix Expression:" << std::endl;
        if (numOperands <= numOperators) {
            printError(result + " Error: Too few operands!");
        } else {
            printError("Error: Stack has more than one operand left in!");
        }
        return "";
    }
    std::string evaluated = evaluatePostfix(result);
    if (evaluated == result) {
        std::cout << "Postfix Expression:" << std::endl;
        printError(result + " Error: Division by Zero!");
        return "";
    } else if (evaluated.empty()) {
        return result;
    }
    return result + " = " + evaluated;
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
