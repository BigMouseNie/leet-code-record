#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        stringstream ss(s);
        string word;

        int i = 0;
        while (getline(ss, word, ' '))
        {
            if (i >= pattern.size())
                return false;
            auto it1 = map1.find(pattern[i]);
            auto it2 = map2.find(word);
            if (it1 != map1.end() && it2 != map2.end())
            {
                if (it1->second != word || it2->second != pattern[i])
                    return false;
            }
            else if (it1 == map1.end() && it2 == map2.end())
            {
                map1[pattern[i]] = word;
                map2[word] = pattern[i];
            }
            else
                return false;
            ++i;
        }

        return i == pattern.size();
    }
};
