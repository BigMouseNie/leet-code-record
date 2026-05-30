#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "solution.hpp"

int main(int argc, char** argv) {
    Solution solution;
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.front() == '[') line.substr(1);
        if (line.back() == ']') line.pop_back();
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        std::stringstream ss(line);
        std::string token;
        std::vector<int> nums;

        while (std::getline(ss, token, ',')) {
            if (!token.empty()) nums.push_back(std::stoi(token));
        }

        std::cout << solution.majorityElement(nums) << std::endl;
    }

    return 0;
}
