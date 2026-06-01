#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        vector<pair<int,int>> record(nums.size(), {0,0});
        vector<int> result(nums.size(), 0);
        record[0].first = nums.front();
        record[nums.size()-1].second = nums.back();
        for (int i=1;i<nums.size();++i) record[i].first = nums[i] * record[i-1].first;
        for (int j=nums.size()-2;j>=0;--j) record[j].second = nums[j] * record[j+1].second;
        result.front() = record[1].second;
        result.back() = record[nums.size()-2].first; 
        for (int i=1;i<nums.size()-1;++i) result[i] = record[i-1].first * record[i+1].second;
        return result;
    }
}; 
