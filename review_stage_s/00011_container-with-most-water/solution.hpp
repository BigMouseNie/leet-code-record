#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = min(height.front(), height.back()) * (height.size()-1);
        int left = 0;
        int right = height.size()-1;
        while (left < right) {
            result = max(result, min(height[left], height[right]) * (right-left));
            if (height[left]>height[right]) --right;
            else ++left;
        }
        return result;
    }
};
