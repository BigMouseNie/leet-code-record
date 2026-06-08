#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix.back().size();
        int size = row * col;
        int left = -1;
        int right = size;
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;

            int midR = mid / col;
            int midC = mid % col;

            if (matrix[midR][midC] > target) right = mid;
            else if (matrix[midR][midC] < target) left = mid;
            else return true;
        }

        return false;
    }
};
