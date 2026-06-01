#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr = 0;
        int tptr = 0;
        while (sptr < s.size() && tptr < t.size()) {
            if (s[sptr] == t[tptr++]) sptr++;
        }
        return sptr == s.size();
    }
};
