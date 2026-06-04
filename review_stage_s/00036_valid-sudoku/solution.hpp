#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<char>> rowSets(9);
        vector<unordered_set<char>> colSets(9);
        vector<unordered_set<char>> gridSets(9);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    auto rIt = rowSets[i].find(board[i][j]);
                    if (rIt != rowSets[i].end())
                        return false;
                    rowSets[i].insert(board[i][j]);

                    auto cIt = colSets[j].find(board[i][j]);
                    if (cIt != colSets[j].end())
                        return false;
                    colSets[j].insert(board[i][j]);

                    int t = ((i / 3) * 3) + (j / 3);
                    auto gIt = gridSets[t].find(board[i][j]);
                    if (gIt != gridSets[t].end())
                        return false;
                    gridSets[t].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};
