#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int minP = prices[0];
        int result = 0;
        for(int i=1;i<prices.size();++i){
            result = std::max(result, prices[i]-minP);
            minP=std::min(minP, prices[i]);
        }

        return result;
    }
};
