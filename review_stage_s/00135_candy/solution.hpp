#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> leftRule(ratings.size(), 1);
        for(int i=1;i<ratings.size();++i){
            if (ratings[i] > ratings[i-1]) leftRule[i] = leftRule[i-1] + 1;
        }
        
        int result = max(leftRule.back(),  1);
        int record = 1;
        for(int i=ratings.size()-2;i>=0;--i){
            if (ratings[i] > ratings[i+1]) record += 1;
            else record = 1;
            result += max(leftRule[i],  record);
        }
        return result;
    }
};
