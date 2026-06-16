#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int upVal = -0xffffff;
        int res = upVal;
        for (int x : nums) {
            if (x+upVal > x) upVal += x;
            else upVal = x;
            res = max(res, upVal);
        }
        return res;
    }
};
