#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

    inline static std::unordered_map<char, std::string> record = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        dfs(digits, "", res);
        return res;
    }

    void dfs(string digits, string cur, vector<string>& res) {
        if (digits.empty() && !cur.empty()) {
            res.push_back(cur);
            return;
        }
        string s = record[digits.front()];
        for (char c : s) {
            cur.push_back(c);
            dfs(digits.substr(1), cur, res);
            cur.pop_back();
        }
    }
};
