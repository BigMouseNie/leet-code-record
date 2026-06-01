#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c){ return ((c<'a' || c>'z') && (c<'A' || c>'Z') && (c<'0' || c>'9'));}), s.end());
        int rev = 'a' - 'A';
        for (auto& c : s) if (c >= 'A' && c <= 'Z') c += rev;
        
        int lptr = 0;
        int rptr = s.size()-1;
        while (lptr <= rptr) if (s[lptr++] != s[rptr--]) return false;
        
        return true;
    }
};
