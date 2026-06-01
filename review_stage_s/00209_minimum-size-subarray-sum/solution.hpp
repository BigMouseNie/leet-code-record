#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int windowSum = nums.front();
        if (windowSum >= target) return 1;
        int result = INT_MAX;
        int left = 0;
        int right = 0;
        while (left < nums.size() && right < nums.size()) {
            if (left > right){
                right = left;
                windowSum = nums[left];
                if (windowSum >= target) return 1;
                continue;
            }
            if (windowSum >= target) {
                result = min(result, right-left+1);
                windowSum -= nums[left++];
            } else {
                ++right;
                if (right < nums.size()) windowSum+=nums[right];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
