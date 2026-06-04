#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = record.find(nums[i]);
            if (it == record.end())
                record[nums[i]] = i;
            else
            {
                if (i - it->second <= k)
                    return true;
                it->second = i;
            }
        }
        return false;
    }
};
