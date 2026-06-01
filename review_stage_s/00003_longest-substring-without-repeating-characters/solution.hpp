#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> record;
        int result = 0;
        int curlen = 0;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            auto it = record.find(s[right]);
            if (it == record.end()) {   // 没有重复
                record.insert(s[right]);
                ++right; ++curlen;
                result = max(result, curlen);
            } else {   // 重复了
                while (left < right) {
                    if (s[left] != s[right]) {
                        record.erase(s[left]);
                        ++left; --curlen;
                    } else {
                        ++left;
                        break;
                    }
                }
                ++right;
            }
        }
        return result;
    }
};
