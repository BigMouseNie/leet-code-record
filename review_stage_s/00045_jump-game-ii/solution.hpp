#include <vector>
#include <algorithm>

using namespace std;

/*

dp[i][j] i步是否可达j点

dp[i][j] = 

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int k = 1;
        int start = 1;
        int tail = nums[0];
        while (tail < nums.size()-1) {
            int maxLen = 0;
            for (int i=start; i<=tail; ++i) {
                maxLen = std::max(maxLen, i+nums[i]);
            }
            start = tail;
            tail = maxLen;
            ++k;
        }
        return k;
    }
};
