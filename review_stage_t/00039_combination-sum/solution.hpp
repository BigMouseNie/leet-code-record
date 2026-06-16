#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), [](int a, int b){
            return a < b;
        });

        vector<vector<int>> res;
        vector<int> map(candidates.size(), 0);
        vector<int> cur;
        dfs(res, candidates, map, cur, target);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int>& map, vector<int>& cur, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i=0;i<candidates.size();++i) {
            if (candidates[i] > target || (!cur.empty() && candidates[i] >= cur.back())) break;
            if (map[i] == 1) continue;
            map[i] = 1;
            int j=1;
            for (;target - candidates[i] * j >= 0;++j) {
                cur.push_back(candidates[i]);
                dfs(res, candidates, map, cur, target-candidates[i]*j);
            }
            while (j-- > 1) cur.pop_back();
            map[i] = 0;
        }

    }

};
