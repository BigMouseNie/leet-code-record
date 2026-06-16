#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> record;
        record.push_back(nums.front());
        int res = 1;
        for (int i=1;i<nums.size();++i) {
            if (nums[i] > record.back()) {
                record.push_back(nums[i]);
                ++res;
                continue;
            }
            if (nums[i] <= record.front()) {
                record.front() = nums[i];
                continue;
            }
            int l = -1;
            int r = res;
            while (l+1 != r) {
                int mid = l + (r-l)/2;
                if (record[mid] >= nums[i]) r = mid;
                else l = mid;
            }
            record[r] = nums[i];
        }
        return res;
    }
};
