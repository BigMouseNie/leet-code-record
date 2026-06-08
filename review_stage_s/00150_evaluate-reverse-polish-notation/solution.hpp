#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const auto& str : tokens) {
            if (str.size()==1 && (str == "+"||str=="-"||str=="*"||str=="/")) {
                int b = stk.top();stk.pop();
                int a = stk.top();stk.pop();
                switch (str.front())
                {
                case '*':
                    stk.push(a*b);
                    break;
                case '/':
                    stk.push(a/b);
                    break;
                case '-':
                    stk.push(a-b);
                    break;
                default '+':
                    stk.push(a+b);
                    break;
                }
            } else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};
