//
//  InfixConverter.hpp
//
//  C++ implementation of the Infix to Postfix Arithmatic Expression Converter
//  Created by Sook Shin Ha on 10/23/21.
//

#ifndef ExpConverter_HPP
#define ExpConverter_HPP

#include <string>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

class ExpConverter
{
public:
    /** default constructor
     */
    ExpConverter() { };
    
    /** default destructor
     */
    ~ExpConverter() { };
    
    /** print an error message for the errors detected in parsing or evaluating process
     @param msg - an error message for an error detected in the process of parsing an infix espression or evaluating a postfix expression
     */
    void printError(string msg);

    /** check if a character is a valid arithematic operator
     @param c - a character to check if it is a valid arithmetic operator
     @return true if character c is a valid arithmatic operator
     */
    bool isOperator(char c);

    /** check if a string is a valid arithematic operator
     @param s - a string to check if it is a valid arithmetic operator
     @return true if string s is a valid arithmatic operator
     */
    bool isOperator(string s);

    /** check if s stromg is a valid arithematic operand
     @param s - a string to check if it is a valid alpha numeric operand
     @return true if string s is a valid arithmatic operand
     */
    bool isOperand(string s);

    /** check if a string is not a numerical operand
     @param s - a string to check if it is a valid numerical operand
     @return true if the string s is a valid numerical operand
    */
    bool isNotNumericalOperand(string s);

    /** calculate the string value of an arithmatic arithmetic expression
     @param operand1 - the first operand (left operand)
     @param operand2 - the second operand (right operand)
     @param opt - arithmetic operator
     @return a postfix arithmetic expression computation result in the string form
     */
    string calculate(string operand1, string operand2, string opt);
    
    /** evaulate the postfix arithmetic expression if all operands are numerical strings.
     Return the postfix string and the evaluation result. But if all operands are not numerical,  just return the postfix string only.
     @param postfix - a constant string of postfix arithmetic expression to be calculated
     @return a calculation result of the postfix arithmatic expression
     */
    string evaluatePostfix(const string postfix);
    
    /** convert the infix arithmetic expression string to the postfix expression string
     @param infix - an infix arithmetic expression string to convert
     @return a postfix arithmetic expression string converted from the given infix expression if conversion is successul. if not returns a null string*/
    string convertInfix(const string& infix);
    
    /** check if left arithmetic operator has higher precedence than right arithmetc operator
     @param lOperator - an arithmetic operator in the left side
     @param rOperator - an arithmetic operator in the right side
     @return true if '^', '*', or '/' is lOperator; false if rOperator
     */
    bool precedence(char lOperator, char rOperator);

};

#endif
