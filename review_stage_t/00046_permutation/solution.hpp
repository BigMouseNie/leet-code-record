#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<int> set;
        dfs(res, set, cur, nums);
        return res;
    }

    void dfs(vector<vector<int>>& res, unordered_set<int>& set, vector<int>& cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int num : nums) {
            if (set.count(num)) continue;
            set.insert(num);
            cur.push_back(num);
            dfs(res, set, cur, nums);
            cur.pop_back();
            set.erase(num);
        }
    }
};

