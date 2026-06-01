#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        for (auto eml : dir) {
            int count = num / eml.first;
            num %= eml.first;
            for (int i=0;i<count;++i){
                result += eml.second;
            }
        }
        return result;
    }

private:
    inline static const vector<pair<int, string>> dir{
        {1000,  "M"},
        { 900, "CM"},
        { 500,  "D"},
        { 400, "CD"},
        { 100,  "C"},
        {  90, "XC"},
        {  50,  "L"},
        {  40, "XL"},
        {  10,  "X"},
        {   9, "IX"},
        {   5,  "V"},
        {   4, "IV"},
        {   1,  "I"}
    };
};
