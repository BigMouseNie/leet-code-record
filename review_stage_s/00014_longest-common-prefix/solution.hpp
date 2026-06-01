#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string curPrefix(strs[0]);
        for (int i=1;i<strs.size();++i) {
            if (curPrefix == "") return "";
            int j=0;
            for (; j<min(curPrefix.size(), strs[i].size()); ++j){
                if (curPrefix[j] == strs[i][j]) continue;
                break;
            }
            curPrefix = curPrefix.substr(0, j);
            std::cout << curPrefix << std::endl;
        }
        return curPrefix;
    }
};
