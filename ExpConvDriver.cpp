//
//  ExpConvDriver.cpp
//  

#include "ExpConverter.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>

void evaluateLine(std::string line, ExpConverter &ec);

int main(int argc, char *argv[]) {
    ExpConverter ec;
    std::string line;
    // File type
    if (argc == 3 && strcmp(argv[1], "-f") == 0) {
        std::ifstream file(argv[2]);
        if (file.is_open()) {
            while (getline(file, line)) {
                std::cout << "Infix Expression:\n" << line << std::endl;
                evaluateLine(line, ec);
            }
        } else {
            std::cout << "Could not open file.";
            return EXIT_FAILURE;
        }
    } else if (argc == 1) { // Interactive type
        while (true) {
            std::cout << "Infix Expression:" << std::endl;
            getline(std::cin, line);
            if (line == "exit") {
                std::cout << "Bye!";
                break;
            }
            evaluateLine(line, ec);
        }
    }
    return EXIT_SUCCESS;
}

void evaluateLine(std::string line, ExpConverter &ec) {
    std::string postFix;
    std::string evaluated;
    postFix = ec.convertInfix(line);
    if (!postFix.empty()) {
//        evaluated = ec.evaluatePostfix(postFix);
        std::cout << "Postfix Expression:" << std::endl;
        if (!evaluated.empty()) {
            std::cout << postFix << std::endl << std::endl;
        } else {
            std::cout << postFix << std::endl << std::endl;
        }
    } else {
        std::cout << std::endl;
    }
}