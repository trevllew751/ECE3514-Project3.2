#include "ExpConverter.hpp"
#include "Stack.hpp"
#include <math.h>

void ExpConverter::printError(string msg) {

}

bool ExpConverter::isOperator(char c) {
    return false;
}

bool ExpConverter::isOperator(string s) {
    return false;
}

bool ExpConverter::isOperand(string s) {
    return false;
}

bool ExpConverter::isNotNumericalOperand(string s) {
    return false;
}

string ExpConverter::calculate(string operand1, string operand2, string opt) {
    return std::string();
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
