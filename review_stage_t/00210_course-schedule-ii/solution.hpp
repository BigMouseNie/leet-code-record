#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> record(numCourses, 0);
        unordered_map<int, vector<int>> map;
        for (const auto& v : prerequisites) {
            ++record[v.front()];
            map[v.back()].push_back(v.front());
        }
        vector<int> vec;
        vector<int> res;
        vec.reserve(numCourses);
        res.reserve(numCourses);
        for (int i=0;i<record.size();++i) {
            if (record[i]==0) vec.push_back(i);
        }

        while (!vec.empty()) {
            vector<int> tmp;
            swap(tmp, vec);
            for (int x : tmp) {
                res.push_back(x);
                for (int y : map[x]) {
                    --record[y];
                    if (record[y]==0) vec.push_back(y);
                }
            }
        }
        if (res.size() != numCourses) return {};
        return res;
        
    }
};
