using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> m {-1, -1, -1, 0, 1, 1,  1,  0};
        vector<int> n {-1,  0,  1, 1, 1, 0, -1, -1};
        for (int i=0;i<board.size();++i) {
            for (int j=0;j<board.front().size();++j) {
                int life = 0;
                for (int v=0;v<8;++v) {
                    int x = i + m[v];
                    int y = j + n[v];
                    if (x>=0 && x<board.size() && y>=0 && y<board.front().size()) {
                        if (board[x][y] % 3 == 1) ++life;
                    }
                }
                if (board[i][j] == 0) {
                    if (life==3) board[i][j] = 9;
                    else board[i][j] = 3;
                } else {
                    if (life<2 || life>3) board[i][j] = 4;
                    else board[i][j] = 10;
                }
            }
        }

        for (auto& row : board) {
            for (int& eml : row) {
                eml /= 9;
            }
        }

        return;
    }
};

/*

0 0  3
0 1  9
1 0  4
1 1  10


*/
