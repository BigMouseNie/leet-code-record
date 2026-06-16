#include <cmath>

using namespace std;

class Solution {
private:
    long long MAXVAL = pow(2, 16);
public:
    int mySqrt(int x) {
        if (x<=1) return x; 
        long long left = 0;
        long long right = x/2;
        if (right > MAXVAL) right = MAXVAL;

        while (left+1 < right) {
            long long mid = left + (right - left) / 2;
            long long val = mid*mid;
            if (val > x) right = mid-1;
            else left = mid;
        }
        if (right * right <= x) return right;
        return left;
    }
};
