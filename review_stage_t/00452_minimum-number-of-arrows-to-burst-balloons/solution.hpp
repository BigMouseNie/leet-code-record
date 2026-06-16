#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            if (a.front() == b.front()) return a.back() < b.back();
            return a.front() < b.front();
        });

        int res = 1;
        int l = points[0].front();
        int r = points[0].back();
        for (int i=1;i<points.size();++i) {
            l = max(l, points[i].front());
            r = min(r, points[i].back());
            if (l > r) {
                ++res;
                l = points[i].front();
                r = points[i].back();
            }
        }

        return res;
    }
};
