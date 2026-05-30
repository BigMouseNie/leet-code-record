#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "solution.hpp"

int main(int argc, char** argv) {
    Solution solution;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.front() == '[') line.substr(1);
        if (line.back() == ']') line.pop_back();
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        
        std::stringstream ss(line);
        std::string token;
        std::vector<int> nums;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) nums.push_back(std::stoi(token));
        }

        int k;
        std::cin >> k;
        std::cin.ignore();

        solution.rotate(nums, k);

        for(int x : nums) {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}
