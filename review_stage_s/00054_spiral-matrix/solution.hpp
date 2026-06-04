#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        pair<int, int> leftUp(0, 0);
        pair<int, int> rightDown(matrix.size() - 1, matrix.back().size() - 1);
        vector<int> res;
        while (leftUp.first < rightDown.first && leftUp.second < rightDown.second)
        {
            for (int i = leftUp.second; i < rightDown.second; ++i)
                res.push_back(matrix[leftUp.first][i]);

            for (int i = leftUp.first; i < rightDown.first; ++i)
                res.push_back(matrix[i][rightDown.second]);

            for (int i = rightDown.second; i > leftUp.second; --i)
                res.push_back(matrix[rightDown.first][i]);

            for (int i = rightDown.first; i > leftUp.first; --i)
                res.push_back(matrix[i][leftUp.second]);

            ++leftUp.first;
            ++leftUp.second;
            --rightDown.first;
            --rightDown.second;
        }

        if (leftUp.first == rightDown.first && leftUp.second <= rightDown.second)
        {
            for (int i = leftUp.second; i <= rightDown.second; ++i)
                res.push_back(matrix[leftUp.first][i]);
        }
        else if (leftUp.second == rightDown.second && leftUp.first <= rightDown.first)
        {
            for (int i = leftUp.first; i <= rightDown.first; ++i)
                res.push_back(matrix[i][leftUp.second]);
        }

        return res;
    }
};
