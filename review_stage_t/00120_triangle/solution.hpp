#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.back().size();
        vector<int> dp(n, 0);
        dp[0] = triangle.front().front();
        for(int i=1;i<triangle.size();++i) {
            int upVal = 0;
            // for (int x : dp) std::cout << x << ", ";;
            // std::cout << std::endl;
            for(int j=0;j<=i;++j) {
                if (j==0) {
                    upVal = dp[j];
                    dp[j] += triangle[i][j];
                } else if(j==i) {
                    dp[j] = upVal + triangle[i][j];
                    //std::cout << dp[j] << std::endl;
                } else {
                    int t = dp[j];
                    dp[j] = min(triangle[i][j] + upVal, triangle[i][j] + dp[j]);
                    upVal = t;
                }
            }
        }
        //for (int x : dp) std::cout << x << ", ";;
        int res = dp[0];
        for (int x : dp) res = min(x, res);
        return res;
    }
};
