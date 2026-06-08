#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> vec;
        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") continue;
            if (token == "..") {
                if(!vec.empty()) vec.pop_back();
                continue;
            }
            vec.emplace_back(token);
        }
        if (vec.size() == 0) return "/";
        string res;
        for (const auto& str : vec) {
            res += '/';
            res += str;
        }

        return res;
    }
};

