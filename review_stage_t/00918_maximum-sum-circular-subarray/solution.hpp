#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int upVal = nums.front();
        int res = upVal;
        int n = nums.size();
        int total = upVal;
        bool flag = false;
        if (nums.front() >= 0) flag = true; 
        for (int i=1;i<n;++i) {
            if (nums[i] >= 0) flag = true; 
            total += nums[i];
            if (nums[i]+upVal > nums[i]) upVal += nums[i];
            else upVal = nums[i];
            res = max(res, upVal);
        }

        if (!flag) return res;

        int mV = nums.front();
        upVal = mV;
        for (int i=1;i<n;++i) {
            if (nums[i]+upVal > nums[i]) upVal = nums[i];
            else upVal += nums[i];
            mV = min(mV, upVal);
        }

        return max(res, total - mV);
    }
};
