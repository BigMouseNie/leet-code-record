using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        string xs = to_string(x);
        int left = 0;
        int right = xs.size()-1;
        while (left < right) {
            if (xs[left++] != xs[right--]) return false;
        }
        return true;
    }
};
