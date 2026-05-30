#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int lptr = 0;
        int rptr = nums.size()-1;
        while (lptr < rptr) {
            if (nums[lptr] != val) {++lptr; continue;}
            while (lptr < rptr) {
                if (nums[rptr] != val) break;
                --rptr;
            }
            if (nums[rptr] == val) break;
            swap(nums[lptr++], nums[rptr--]);
        }
        if (nums[lptr] == val) {
            return lptr;
        }
        return lptr+1;
    }
};
