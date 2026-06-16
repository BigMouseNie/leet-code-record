using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        for (int i=0;i<haystack.size()-needle.size()+1;++i) {
            bool flag = true;
            for (int j=0;j<needle.size();++j) {
                if (haystack[i+j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
};
