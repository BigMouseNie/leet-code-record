#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res= nums.front();
        for (int i=1;i<nums.size();++i) {
            res ^= nums[i];
        }
        return res;
    }
};
