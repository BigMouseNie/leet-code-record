using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        long long i = 1;
        double cur = x;
        double res = 1.0;
        long long N = n;
        if (N < 0) N = -N;

        while (i <= N) {
            if (i & N) {
                res *= cur;
            }
            cur *= cur;
            i <<= 1;
        }

        if (n<0) return 1/res;
        return res;
    }
};


/*
2^7

7 = B(111)
10
1010
8421

2

4

16





*/
