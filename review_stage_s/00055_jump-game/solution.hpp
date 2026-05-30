#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = nums[0];
        for (int i=1;i<nums.size();++i) {
            if (flag == 0) return false;
            --flag;
            flag = std::max(flag, nums[i]);
        }
        return true;
    }
};
