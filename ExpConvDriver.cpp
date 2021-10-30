//
//  ExpConvDriver.cpp
//  

#include "ExpConverter.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>

int main(int argc, char *argv[]) {
    ExpConverter ec;
    std::string line;
    std::string postFix;
    std::string evaluated;
    // File type
    if (argc == 3 && strcmp(argv[1], "-f") == 0) {

    } else if (argc == 1) { // Interactive type
        while (true) {
            std::cout << "Infix Expression:" << std::endl;
            getline(std::cin, line);
            if (line == "exit") {
                break;
            }
            postFix = ec.convertInfix(line);
            if (!postFix.empty()) {
                std::cout << "Postfix Expression:" << std::endl;
                evaluated = ec.evaluatePostfix(postFix);
                if (!evaluated.empty()) {
                    std::cout << postFix + " = " + evaluated << std::endl << std::endl;
                } else {
                    std::cout << postFix << std::endl << std::endl;
                }
            } else {
                std::cout << std::endl;
            }
        }
    }
    return EXIT_SUCCESS;
}
