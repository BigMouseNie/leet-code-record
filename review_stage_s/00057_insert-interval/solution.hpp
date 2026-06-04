#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        bool flag = false;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (!(newInterval.front() > intervals[i].back() || newInterval.back() < intervals[i].front()))
            {
                flag = true;
                int left = min(newInterval.front(), intervals[i].front());
                int right = max(newInterval.back(), intervals[i].back());
                for (int j = i + 1; j < intervals.size(); ++j)
                {
                    if (!(left > intervals[j].back() || right < intervals[j].front()))
                    {
                        left = min(left, intervals[j].front());
                        right = max(left, intervals[j].back());
                        intervals[j].front() = 0;
                        intervals[j].back() = -1;
                    }
                    else
                        break;
                }

                intervals[i].front() = left;
                intervals[i].back() = right;
                intervals.erase(remove_if(intervals.begin() + i + 1, intervals.end(), [](const vector<int> &v)
                                          { return v.front() > v.back(); }),
                                intervals.end());
                break;

                return intervals;
            }
        }

        if (flag)
            return intervals;

        for (int i = 0; i < intervals.size(); ++i)
        {
            if (newInterval.back() < intervals[i].front())
            {
                intervals.insert(intervals.brgin() + i, newInterval);
                return intervals;
            }
        }
    }
};
