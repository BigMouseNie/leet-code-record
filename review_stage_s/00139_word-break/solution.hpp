using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, 0);
        unordered_set<string> dir;
        for(const auto& word : wordDict) {
            dir.insert(word);
        }

        for(int i=0;i<n;++i) {
            if (dir.count(s.substr(0,i+1))) {
                dp[i] = 1;
                continue;
            }
            for (int j=0;j<i;++j) {
                if (dp[j]==1 && dir.count(s.substr(j+1,i-j))){
                    dp[i] = 1;
                    continue;
                }
            }
        }
        return dp[n-1] == 1;
    }
};
