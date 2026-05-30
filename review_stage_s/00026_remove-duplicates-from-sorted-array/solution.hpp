#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lptr = 0;
        int rptr = 1;
        while (rptr < nums.size()) {
            if (nums[rptr] > nums[lptr]) {nums[++lptr] = nums[rptr++];}
            else ++rptr; 
        }
        return lptr + 1;
    }
};
