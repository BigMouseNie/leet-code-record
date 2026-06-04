#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int leftUp = 0;
        int rightDown = matrix.size() - 1;

        while (leftUp < rightDown)
        {
            for (int i = leftUp; i < rightDown; ++i)
            {
                swap(matrix[leftUp][i], matrix[i][rightDown]);
            }

            for (int i = rightDown; i > leftUp; --i)
            {
                swap(matrix[leftUp][leftUp + rightDown - i], matrix[rightDown][i]);
            }

            for (int i = rightDown; i > leftUp; --i)
            {
                swap(matrix[leftUp][leftUp + rightDown - i], matrix[i][leftUp]);
            }

            ++leftUp;
            --rightDown;
        }

        return;
    }
};
