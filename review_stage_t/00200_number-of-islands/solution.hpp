#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        res = 0;
        for (int i=0;i<grid.size();++i) {
            for (int j=0;j<grid.back().size();++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i<0 || i>=grid.size() || j <0 || j>=grid.back().size()) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = '2';
        for (const auto& p : v) {
            dfs(grid, i+p.first, j+p.second);
        }
    }

private:
    vector<pair<int, int>> v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int res = 0;
};
