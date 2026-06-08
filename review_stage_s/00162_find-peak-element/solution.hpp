#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = -1;
        int right = nums.size();

        while (left + 2 < right) {
            int mid = left + (right - left) / 2;
            //std::cout << left << ", " << right << ", " << mid << std::endl;
            if (nums[mid] < nums[mid+1]) {
                left = mid;
            } else {
                right = mid+1;
            }
        }
        return left + 1;
    }
};
