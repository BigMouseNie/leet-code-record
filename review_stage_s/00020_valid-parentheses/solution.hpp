#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        string t = "()[]{}";
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stk.push(c);
            }
            else
            {
                if (stk.empty() || (c == ')' && stk.top() != '(') || (c == ']' && stk.top() != '[') || (c == '}' && stk.top() != '{'))
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
