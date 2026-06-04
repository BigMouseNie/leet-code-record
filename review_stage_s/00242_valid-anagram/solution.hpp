#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> record(128, 0);
        for (char c : s)
            ++record[c];
        for (char c : t)
            --record[c];
        for (int x : record)
            if (x != 0)
                return false;
        return true;
    }
};
