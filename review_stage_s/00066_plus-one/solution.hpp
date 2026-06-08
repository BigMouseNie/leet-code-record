using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int upVal = 1;
        for (int i=digits.size()-1;i>=0;--i){
            digits[i]+=upVal;
            if (digits[i] < 10) return digits;
            upVal = 1;
            digits[i] %= 10;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
