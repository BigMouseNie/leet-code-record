#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        {
            unordered_map<string, int> _map;
            swap(map, _map);
        }
        int idx = 0;
        for (const auto& ps : equations) {
            if (map.count(ps.front()) == 0) map[ps.front()] = idx++;
            if (map.count(ps.back()) == 0) map[ps.back()] = idx++;
        }

        {
            vector<int> _parent(idx, 0);
            vector<double> _wight(idx, 1.0);
            swap(parent, _parent);
            swap(wight, _wight);
        }

        for(int i=0;i<idx;++i) parent[i] = i;

        for (int i=0;i<equations.size();++i) {
            unite(map[equations[i].front()], map[equations[i].back()], values[i]);
        }

        vector<double> res;
        for (const auto& ps : queries) {
            auto it1 = map.find(ps.front());
            auto it2 = map.find(ps.back());
            if (it1 != map.end() && it2 != map.end() && same(it1->second, it2->second))
                res.push_back(wight[it2->second] / wight[it1->second]);
            else
                res.push_back(-1.0);
        }
        return res;
    }

private:
    int find(int x) {
        if (parent[x] != x) {
            int t = parent[x];
            parent[x] = find(parent[x]);
            wight[x] *= wight[t];
        }
        return parent[x];
    }

    void unite(int a, int b, double w){     // a / b = w
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return;
        
        /*
        a / b = w
        rootA / a = wight[a]
        rootB / b = wight[b]
        rootA / rootB = ?
        */
        parent[rootB] = rootA;
        wight[rootB] = wight[a] * w / wight[b];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }


private:
    vector<int> parent;
    vector<double> wight;
    unordered_map<string, int> map;
};
