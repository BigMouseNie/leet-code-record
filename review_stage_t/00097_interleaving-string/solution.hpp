using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s1.size() == 0 || s2.size() == 0) return s1 == s3 || s2 == s3;
        vector<int> dp(s2.size()+1, 0);
        dp[0] = 1;
        for (int i=1;i<=s2.size();++i) {
            if (s2[i-1] == s3[i-1]) dp[i] = 1;
            else break;
        }
        for (int i=1;i<=s1.size();++i) {
            for (int j=0;j<=s2.size();++j) {
                if ((dp[j] == 1 && s3[i+j-1] == s1[i-1]) 
                  || j >=1 && dp[j-1] == 1 && s3[i+j-1] == s2[j-1]) {
                    dp[j] = 1;
                } else {
                    dp[j] = 0;
                }
            }
        }

        return dp[s2.size()] == 1;
    }
};
/*
dp[i][j]   s1[i] s1[j] ==> max s3 len
dp[i][j] = ?

dp[i-1][0] ~ dp[i-1][j]
dp[i][0] ~ dp[i][j-1]


"abbcc"
"acbca"
"acdbbcbcac"

dp[2][0]
dp[0][2]


dp[0][0] = 0
dp[1][0] = 1
dp[0][1] = 0;


*/



