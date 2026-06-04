#include <unordered_set>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> record;
        while (record.count(n) == 0)
        {
            record.insert(n);
            int s = 0;
            while (n > 0)
            {
                s += pow(n % 10, 2);
                n /= 10;
            }
            if (s == 1)
                return true;
            n = s;
        }
        return false;
    }
};
