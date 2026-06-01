#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (getline(ss, word, ' ')) if (!word.empty()) words.emplace_back(word);
        string res;
        for (int i=words.size()-1;i>=0;--i) {
            res += words[i];
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};
