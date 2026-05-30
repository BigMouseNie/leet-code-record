#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "best_solution.hpp"

void func(std::vector<int>& nums) {
    std::string line;
    std::getline(std::cin, line);

    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    if (line.front() == '[') line = line.substr(1);
    if (line.back() == ']') line.pop_back();

    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (!token.empty()) nums.push_back(std::stoi(token));
    }
}

int main(int argc, char** argv) {
    Solution solution;
    while (true) {
        std::vector<int> nums1;
        std::vector<int> nums2;
        func(nums1);
        func(nums2);
        int m = nums1.size();
        nums1.resize(nums1.size() + nums2.size(), 0);
        solution.merge(nums1, m, nums2, nums2.size());

        for (int x : nums1) {
            std::cout << x << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}
