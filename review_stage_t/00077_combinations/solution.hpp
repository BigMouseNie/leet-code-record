#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k>n) return res;
        vector<int> cur;
        vector<int> map(n+1, 0);
        dfs(res, map, cur, n, k);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& map, vector<int>& cur, int n, int k) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int i=1;i<=n;++i) {
            if (map[i] == 1 || (!cur.empty() && i > cur.back())) continue;
            map[i] = 1;
            cur.push_back(i);
            dfs(res, map, cur, n, k);
            cur.pop_back();
            map[i] = 0;
        }
    }
};
