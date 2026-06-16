#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board.back().size();
        vector<vector<char>> map(row, vector<char>(col, 0));
        string cur;
        for (int i=0;i<row;++i) {
            for (int j=0;j<col;++j) {
                if (dfs(board, map, cur, word, i, j)) return true;
            }
        }
        return false;
    }

private:
    bool dfs (vector<vector<char>>& board, vector<vector<char>>& map, string& cur, const string& target, int i, int j) {
        if (cur.size() >= target.size() || i<0 || i>=board.size() || j<0 || j>=board.back().size()) return false;
        if (map[i][j] != 0 || board[i][j] != target[cur.size()]) return false;
        cur.push_back(board[i][j]);
        map[i][j] = 1;
        if (cur.size() == target.size()) return true;
        for (const auto& t : v) {
            if (dfs(board, map, cur, target, i+t.front(), j+t.back())) return true;
        }
        map[i][j] = 0;
        cur.pop_back();
        return false;
    }

private:
    inline static const vector<vector<int>> v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
