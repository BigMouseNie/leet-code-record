#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> record;
        vector<vector<string>> res;

        for (string &str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            auto it = record.find(tmp);
            if (it == record.end())
            {
                res.push_back({str});
                record[tmp] = res.size() - 1;
            }
            else
            {
                res[it->second].emplace_back(str);
            }
        }

        return res;
    }
};
