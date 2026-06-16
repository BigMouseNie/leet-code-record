#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {return a < b;});
        unordered_map<int, int> map;
        vector<vector<int>> res;
        for (int x : nums) {map[x]++;}

        int upValI = INT_MAX;
        int upValJ = INT_MAX;
        for (int i=0;i<nums.size();++i) {
            if (upValI != INT_MAX && nums[i] == upValI) continue;
            upValI = nums[i];
            for (int j=i+1;j<nums.size();++j) {
                if (upValJ != INT_MAX && nums[j] == upValJ) continue;
                upValJ = nums[j];
                int target = -nums[i] - nums[j];
                int cnt = 1;
                if (target == nums[i]) ++cnt;
                if (target == nums[j]) ++cnt;
                if (map.count(target) != 0 && map[target] >= cnt && target >= nums[j]) {
                    res.push_back({nums[i],nums[j],target});
                }

            }
        }

        return res;

    }
};
