#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() < 1)
            return res;
        int left = nums[0];
        int right = nums[0];
        string token = to_string(left);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == right + 1)
                right = nums[i];
            else
            {

                if (left == right)
                    res.emplace_back(to_string(left));
                else
                    res.emplace_back(to_string(left) + "->" + to_string(right));
                left = nums[i];
                right = nums[i];
            }
        }
        if (left == right)
            res.emplace_back(to_string(left));
        else
            res.emplace_back(to_string(left) + "->" + to_string(right));
        return res;
    }
};
