#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> res(32, 0);
        for (int x : nums) {
            for (int i=0;i<32;++i) {
                if (x & (1<<i)) ++res[i];
            }
        }
        int result = 0;
        for (int i=0;i<32;++i) {
            if (res[i]%3!=0) result += (1<<i);
        }
        return result;
    }
};
