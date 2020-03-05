// Contest - 2010 North American Rockey Mountain
// Problem 4882 - Parenthesis
// Vincent Cote - CPSC 3200
// Approach -
#include <iostream>
#include <stack>

int main(void) {
    while (!std::cin.eof()) {
        std::string eq;
        std::getline(std::cin, eq);
        std::stack<int> s;

        bool addToS = false;

        for (int i = 0; i < eq.length; i++) {
            if (eq[i] != ')') {
                s.push(eq[i]);
            } else {
                std::string temp = "";
                while (!s.empty()) {
                    if (s.top() != '(') {
                        temp += s.top();
                    } else {
                        // check the equation type
                    }
                }
            }
        }
    }
}