#include <vector>
#include <algorithm>

using namespace std;

/*
dp[i][0] 不持有
dp[i][1] 持有

dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>> dp(prices.size(), {0, 0});
        dp.front().first = 0;
        dp.front().second = -prices.front();
        for (int i=1; i<prices.size(); ++i) {
            dp[i].first = std::max(dp[i-1].first, dp[i-1].second + prices[i]);
            dp[i].second = std::max(dp[i-1].second, dp[i-1].first - prices[i]);
        }
        return dp[prices.size()-1].first;
    }
};