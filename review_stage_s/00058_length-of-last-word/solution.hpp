#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string token;
        string lastWord;
        while (getline(ss, token, ' ')) {
            std::cout << token << std::endl;
            if (!token.empty()) {lastWord = token;};
        }
        return lastWord.size();
    }
};
