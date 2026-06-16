using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board.front().size();
        for (int i=0;i<col;++i) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[row-1][i] == 'O') dfs(board, row-1, i);
        }

        for (int i=0;i<row;++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][col-1] == 'O') dfs(board, i, col-1);
        }


        for (int i=0;i<board.size();++i) {
            for (int j=0;j<board.back().size();++j) {
                if (board[i][j] == 'A') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i<0 || i>=board.size() || j <0 || j>=board.back().size()) return;
        if (board[i][j] != 'O') return;
        board[i][j] = 'A';
        for (const auto& p : v) {
            dfs(board, i+p.first, j+p.second);
        }
    }

private:
    vector<pair<int, int>> v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
