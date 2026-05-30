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

        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        std::stringstream ss(line);
        std::vector<int> nums;
        std::string token;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) nums.push_back(std::stoi(token));
        }

        int k = solution.removeDuplicates(nums);
        for (int i = 0;i<k;++i) {
            std::cout << nums[i] << ",";
        }
        std::cout << std::endl;
        return 0;
    }
}
