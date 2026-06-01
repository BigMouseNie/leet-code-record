#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> stk;
        for (int i = 0;i<height.size();++i) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                result += (min(height[stk.top()],height[i]) - height[top]) * (i-stk.top()-1);
            }
            stk.push(i);
        }
        return result;
    }
};
