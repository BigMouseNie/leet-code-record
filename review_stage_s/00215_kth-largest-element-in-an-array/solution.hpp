#include <vector>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int a, int b) {return a < b;};
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto x : nums) pq.push(x);
        while (k != 1 && !pq.empty()) {
            pq.pop();
            --k;
        }
        return pq.top();
    }
};
