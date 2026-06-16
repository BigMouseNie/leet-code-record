using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<vector<int>>> dp(
            matrix.size(), 
            vector<vector<int>>(matrix.front().size(), vector<int>(3, 0))
        );

        int res = 0;
        if (matrix[0][0] == '0') dp[0][0] = {0,0,0};
        else {dp[0][0] = {1,1,1}; res = 1;}
        for (int i=1;i<matrix.size();++i) {
            if (matrix[i][0] == '0') dp[i][0] = {0,0,0};
            else {
                dp[i][0] = {1,dp[i-1][0][1]+1,1};
                res = 1;
            }
        }

        for (int j=1;j<matrix.front().size();++j) {
            if (matrix[0][j] == '0') dp[0][j] = {0,0,0};
            else {
                dp[0][j] = {dp[0][j-1][0]+1,1,1};
                res = 1;
            }
        }

        for (int i=1;i<matrix.size();++i) {
            for (int j=1;j<matrix.front().size();++j) {
                //std::cout << i << ", " << j << std::endl;;
                if (matrix[i][j] == '0') dp[i][j] = {0,0,0};
                else {
                    int left = dp[i][j-1][0];
                    int up = dp[i-1][j][1];
                    int leftUp = dp[i-1][j-1][2];
                    int len = min(leftUp, min(left, up));
                    dp[i][j][2] = len+1;
                    dp[i][j][0] = left+1;
                    dp[i][j][1] = up+1;
                    res = max(res, dp[i][j][2] * dp[i][j][2]);
                }
            }
        }
        return res;
    }
};
