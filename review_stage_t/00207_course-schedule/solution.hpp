#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        vector<int> record(numCourses, 0);
        for (const auto& v : prerequisites) { // v.front() -> v.back()
            ++record[v.back()];
            map[v.front()].push_back(v.back());
        }

        queue<int> que;
        for(int i=0;i<numCourses;++i) {
            if (record[i] == 0) que.push(i);
        }

        while (!que.empty()) {
            int course = que.front();
            que.pop();
            for (int c : map[course]) {
                --record[c];
                if (record[c] == 0) que.push(c);
            }
        }

        for (int c : record) {
            if (c != 0) return false;
        }

        return true;
    }
};
