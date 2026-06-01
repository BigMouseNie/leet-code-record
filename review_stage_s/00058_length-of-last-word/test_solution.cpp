#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "solution.hpp"

int main(int argc, char** argv) {
    Solution solution;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << solution.lengthOfLastWord(line) << std::endl;
    }
    return 0;
}
