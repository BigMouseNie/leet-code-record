#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int minVal = nums.back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) {
                minVal = min(minVal, nums[left]);
                left = mid+1;
            } else {
                minVal = min(minVal, nums[mid]);
                right = mid-1;
            }
        }
        return min(minVal, nums[left]);
    }
};
