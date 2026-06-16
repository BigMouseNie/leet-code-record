using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for (int i=0;i<32;++i) {
            int k = 1 << i;
            if (k & n) {
                res += 1<<(31-i);
            }
        }
        return res;
    }
};
