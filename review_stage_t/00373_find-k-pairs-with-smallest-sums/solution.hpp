#include <vector>
#include <priority_queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](vector<int>& a, vector<int>& b){
            return nums1[a.front()]+nums2[a.back()] > nums1[b.front()]+nums2[b.back()];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i=0;i<nums1.size();++i) pq.push({i,0});
        vector<vector<int>> res;
        while (k>0 && !pq.empty()) {
            vector<int> v = pq.top();
            pq.pop();
            res.push_back({nums1[v.front()], nums2[v.back()]});
            if (v.back()+1<nums2.size()) pq.push({v.front(), v.back()+1});
            --k;
        }

        return res;
    }
};
