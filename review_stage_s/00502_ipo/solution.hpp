#include <vector>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> cpVec;
        for(int i=0;i<profits.size();++i) cpVec.push_back({capital[i], profits[i]});
        auto cmp = [](pair<int, int> a, pair<int, int> b) {return a.second < b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        sort(cpVec.begin(), cpVec.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });

        int res = w;
        int curIdx = 0;
        for (int i=0;i<k;++i){
            while (curIdx < cpVec.size() && cpVec[curIdx].first <= res) {
                pq.push(cpVec[curIdx++]);

            }
            if (pq.empty()) break;
            res += pq.top().second;
            pq.pop();
        }
        return res;
    }
};
