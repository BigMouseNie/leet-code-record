#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a.front() < b.front(); });

        pair<int, int> curRange{intervals.front().front(), intervals.front().back()};
        vector<vector<int>> res;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].front() >= curRange.first && intervals[i].front() <= curRange.second)
                curRange.second = max(curRange.second, intervals[i].back());
            else
            {
                res.push_back({curRange.first, curRange.second});
                curRange.first = intervals[i].front();
                curRange.second = intervals[i].back();
            }
        }
        res.push_back({curRange.first, curRange.second});

        return res;
    }
};