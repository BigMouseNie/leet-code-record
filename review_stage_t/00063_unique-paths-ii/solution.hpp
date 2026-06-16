#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp(obstacleGrid.back().size(), 0);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i=1;i<dp.size();++i) {
            if (obstacleGrid[0][i] == 0) dp[i] = dp[i-1];
        }
        //for (int x : dp) std::cout << x << ", "; std::cout << std::endl;
        for (int i=1;i<obstacleGrid.size();++i) {
            if (obstacleGrid[i][0] == 1) dp[0] = 0;
            for (int j=1;j<dp.size();++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[j] = dp[j] + dp[j-1];
                } else dp[j] = 0;
            }
            //for (int x : dp) std::cout << x << ", "; std::cout << std::endl;
        }

        return dp.back();
    }
};