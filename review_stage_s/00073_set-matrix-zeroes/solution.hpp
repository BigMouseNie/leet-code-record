#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<bool> raw(matrix.size(), false);
        vector<bool> col(matrix.back().size(), false);
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.back().size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    raw[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < raw.size(); ++i)
        {
            if (raw[i])
            {
                for (int j = 0; j < matrix.back().size(); ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < col.size(); ++i)
        {
            if (col[i])
            {
                for (int j = 0; j < matrix.size(); ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        return;
    }
};
