#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "solution.hpp"

int main(int argc, char** argv) {
    Solution solution;
    while (true) {
        int val = 0;
        std::cin >> val;
        std::cout << "val set: " << val << std::endl;
        std::cin.ignore(); 
        
        std::string line;
        std::getline(std::cin, line);
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        
        std::stringstream ss(line);
        std::string token;
        std::vector<int> nums;
        while (std::getline(ss, token, ',')) {
            if (!token.empty()) nums.push_back(std::stoi(token));
        }

        int k = solution.removeElement(nums, val);
        for(int i = 0;i<k;++i) {
            std::cout << nums[i] << ",";
        }
        std::cout << std::endl;
    }
}

