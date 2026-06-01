#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rawStrs(numRows, "");
        vector<string*> vec;
        string res;
        for (int i=0;i<numRows;++i) vec.push_back(&(rawStrs[i]));
        for (int i=numRows-2;i>0;--i) vec.push_back(&(rawStrs[i]));
        for (int i=0;i<s.size();++i) (*(vec[i%vec.size()]))+=s[i];
        for (auto& str : rawStrs) res+=str;
        return res;
    }
};
