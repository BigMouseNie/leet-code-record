using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 1) return nums.front() == target ? 0 : -1;
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left] && nums[mid] <= nums[right]) {
                if (nums[mid] > target) right = mid-1;
                else if (nums[mid] < target) left = mid+1;
                else return mid;
            } else {
                if (nums[mid] < nums[left]) {
                    if (nums[mid] > target) right = mid-1;
                    else if (nums[mid] < target) {
                        if (nums[left] <= target) right = mid-1;
                        else if (nums[right] >= target) left = mid+1;
                        else return -1;
                    }else return mid;
                } else {
                    if (nums[mid] > target) {
                        if (nums[left] <= target) right = mid-1;
                        else if (nums[right] >= target) left = mid+1;
                        else return -1;
                    }else if (nums[mid] < target) left = mid+1;
                    else return mid;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
};

/*

1 2 3 4 5

4 5 1 2 3

[4,5,6,7,0,1,2]

*/
