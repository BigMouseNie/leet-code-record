#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> record;
        for (char c : magazine)
            record[c] += 1;
        for (char c : ransomNote)
        {
            auto it = record.find(c);
            if (it == record.end())
                return false;
            if ((*(it)).second <= 0)
                return false;
            --((*(it)).second);
        }
        return true;
    }
};
