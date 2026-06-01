#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), [](int x, int y){
            return x < y;
        });

        for (int i=0;i<citations.size();++i) {
            if (citations[i] >= citations.size() - i) return citations.size() - i;
        }

        return 0;
    }
};
