using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int l=0;
        int r=0;
        for (int i=0;i<s.size();++i) dp[i][i] = 1;
        for(int len=2;len<=s.size();++len) {
            for (int i=0;i<s.size()-len+1;++i) {
                int j=i+len-1;
                if (i+1 <= j-1) {
                    if (dp[i+1][j-1] == 1 && s[i]==s[j]) dp[i][j] = 1;
                } else {
                    dp[i][j] = s[i]==s[j] ? 1 : 0;
                }
                if (dp[i][j]==1 && j-i > r-l) {
                    l = i;
                    r = j;
                }
            }
        }
        return s.substr(l, r-l+1);
    }
};
