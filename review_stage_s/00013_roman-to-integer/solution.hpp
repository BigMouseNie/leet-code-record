#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int result = 0;
        while (i < s.size()) {
            int t = nums[dir[s[i]]];

            if (dir[s[i]] != 0 && dir[s[i]] % 2 == 0 && i < s.size()-1 && dir[s[i+1]] < dir[s[i]] ) {
                t = dnums[dir[s[i+1]]];
                ++i;
            }

            result += t;
            ++i;
        }
        return result;
    }
private:
    unordered_map<char, int> dir{
        {'M', 0},
        {'D', 1},
        {'C', 2},
        {'L', 3},
        {'X', 4},
        {'V', 5},
        {'I', 6},
    };

    vector<int> nums  {1000, 500, 100, 50, 10, 5, 1};
    vector<int> dnums { 900, 400,  90, 40,  9, 4, 0}; 
};
