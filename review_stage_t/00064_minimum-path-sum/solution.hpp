#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid.front().size(), 0);
        dp[0] = grid[0][0];
        for (int i=1;i<grid.front().size();++i) {
            dp[i] = dp[i-1] + grid[0][i];
        }

        for (int i=1;i<grid.size();++i) {
            dp[0] += grid[i][0];
            for (int j=1;j<dp.size();++j) {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp.back();
    }
};
