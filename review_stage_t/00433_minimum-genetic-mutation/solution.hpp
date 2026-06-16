#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<string> vec;
        vector<int> map(bank.size(), 0);
        vec.push_back(startGene);
        int step = 0;
        while (!vec.empty()) {
            vector<string> tmp;
            swap(vec, tmp);
            for (string& s : tmp) {
                if (s == endGene) return step;
                for (int i=0;i<bank.size();++i) {
                    if (map[i] == 1) continue;
                    int diff = check(bank[i], s);
                    if (diff == 1) {
                        vec.push_back(bank[i]);
                    }
                    if (diff <= 1) map[i] = 1;
                }
            }
            ++step;
        }
        return -1;
    }

private:
    int check(string& t, string& s) {
        int res = 0;
        for (int i=0;i<t.size();++i) {
            if (s[i] != t[i]) ++ res;
        }
        return res;
    }
};
