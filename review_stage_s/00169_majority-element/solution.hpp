#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int count = 1;
        for(auto it = nums.begin()+1; it!=nums.end(); ++it) {
            if (count == 0) {result = *it; ++count;}
            else if (*it == result) {++count;}
            else --count;
        }
        return result;
    }
};
