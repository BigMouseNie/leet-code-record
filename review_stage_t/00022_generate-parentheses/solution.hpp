#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        vector<string> res;
        string cur;
        unordered_set<string> set;
        dfs(res, set, cur, n, 0, n);
        return res;
    }

private:
    void dfs(vector<string>& res, unordered_set<string> set, string& cur, int left, int right, int n) {
        if (left==0 && right==0) {
            res.push_back(cur);
            return;
        }

        for (int i=1;i<=left;++i) {
            cur.push_back('(');
            if (set.find(cur) == set.end()) {
                set.insert(cur);
                dfs(res, set, cur, left-1, right+1, n);
            }
            
            cur.pop_back();
        }

        for (int j=1;j<=right;++j) {
            cur.push_back(')');
            if (set.find(cur) == set.end()) {
                set.insert(cur);
                dfs(res, set, cur, left, right-1, n);
            }
            cur.pop_back();
        }
    }
};
