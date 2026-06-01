#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i=0;i<numbers.size();++i){
            if (target-numbers[i] < numbers[i]) return {0, 0};
            int second = search(numbers, i+1, numbers.size()-1, target-numbers[i]);
            if (second != -1) return {i+1, second+1};
        }
        return {0, 0};
    }

private:
    int search(vector<int>& numbers, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (numbers[mid] == target) return mid;
            else if (numbers[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};
