#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "solution.hpp"

int main(int argc, char** argv) {
    Solution solution;
    string line;

    while (std::getline(std::cin, line)) {
        if (line.front() == '[') line = line.substr(1);
        if (line.back() == ']') line.pop_back();
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        
        std::stringstream ss(line);
        string token;
        std::vector<std::string> strs;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) {
                if (token.front() == '"') token = token.substr(1);
                if (token.back() == '"') token.pop_back();
            }
            strs.emplace_back(token);
        }

        for(auto str : strs) {
            std::cout << str << ", ";
        }
        std::cout << std::endl;

        std::cout << solution.longestCommonPrefix(strs) << std::endl;
    }
}
