using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return 1;
        int lptr = 0;
        if (nums[lptr] == nums[lptr+1]) ++lptr;
        int rptr = lptr+1;

        while (rptr < nums.size()) {
            if (nums[rptr] > nums[lptr]) {
                nums[++lptr] = nums[rptr++];
                if (rptr < nums.size() && nums[rptr]==nums[lptr]) {
                    nums[++lptr] = nums[rptr++];
                }
            }
            else ++rptr;
        }

        return lptr + 1;
    }
};
