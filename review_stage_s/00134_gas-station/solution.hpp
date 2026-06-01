#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minPrefixSum = gas.front() - cost.front();
        int minPrefixSumIdx = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            if (minPrefixSum > sum) {
                minPrefixSum = sum;
                minPrefixSumIdx = i;
            }
        }

        if (sum >= 0) return (minPrefixSumIdx + 1) % gas.size();
        return -1;
    }
};
