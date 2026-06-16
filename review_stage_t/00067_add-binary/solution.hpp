#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        char upVal = '0';
        int m = a.size()-1;
        int n = b.size()-1;
        for (int i=0;i<max(a.size(), b.size());++i) {
            char cnt = '0';
            if (m-i>=0 && a[m-i]=='1') ++cnt;
            if (n-i>=0 && b[n-i]=='1') ++cnt;
            if (upVal == '1') ++cnt;
            if (cnt <= '1') {
                res.push_back(cnt);
                upVal = '0';
            } else if (cnt == '2') {
                res.push_back('0');
                upVal = '1';
            } else {
                res.push_back('1');
                upVal = '1';
            }
        }
        if (upVal == '1') res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};


/*
11 3
11 3
110

*/
