#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size();
        while (left+1 != right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < target) left = mid;
            else right = mid;
        }
        if (left == nums.size()-1 || nums[right] != target) return {-1, -1};

        int start = right;
        left = right;
        right = nums.size();

        while (left+1 != right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= target) left = mid;
            else right = mid;
        }

        return {start, left};
    }
};