#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int num : nums)
            set.insert(num);
        int res = 0;
        for (int num : set)
        {
            auto it = set.find(num - 1);
            if (it != set.end())
                continue;

            int count = 1;
            while (set.count(++num))
                ++count;
            res = max(res, count);
        }
        return res;
    }
};
