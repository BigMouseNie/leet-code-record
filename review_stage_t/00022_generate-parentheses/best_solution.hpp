#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        vector<string> res;
        string cur;
        dfs(res, cur, n, 0, n);
        return res;
    }

private:
    void dfs(vector<string>& res, string& cur, int left, int right, int n) {
        if (left==0 && right==0) {
            res.push_back(cur);
            return;
        }

        if (left > 0) {
            cur.push_back('(');
            dfs(res, cur, left-1, right+1, n);
            cur.pop_back();
        }

        if (right > 0) {
            cur.push_back(')');
            dfs(res, cur, left, right-1, n);
            cur.pop_back();
        }
    }
};
