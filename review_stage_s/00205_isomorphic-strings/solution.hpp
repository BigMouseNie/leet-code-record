#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> dirS;
        unordered_map<char, char> dirT;
        for (int i = 0; i < s.size(); ++i)
        {
            auto itS = dirS.find(s[i]);
            auto itT = dirT.find(t[i]);
            if (itS == dirS.end() && itT == dirT.end())
            {
                dirS[s[i]] = t[i];
                dirT[t[i]] = s[i];
            }
            else if ((itS != dirS.end() && itT != dirT.end()))
            {
                if (dirS[s[i]] != t[i] || dirT[t[i]] != s[i])
                    return false;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
