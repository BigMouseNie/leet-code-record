#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int row = board.size();
        vector<int> map(row*row+1, 0);
        map[1] = 1;
        vector<int> q = {1}; // 起点
        //for (int i=1;i<=6;++i) {
        for (int step = 0; !q.empty(); step++) {
            auto tmp = move(q); // move 后 q 为空
            for (int n : tmp) {
                if (n == row*row) return step;
                for (int k=n+1;k<=min(n + 6, row*row);++k) {
                    auto xy = toXY(k, row);
                    
                    int next = board[xy.first][xy.second];
                    if (next < 0) {
                        next = k;
                    }
                    if (map[next] == 0) {
                        map[next] = 1;
                        q.push_back(next);
                    }
                }
            }
        }
        return -1;
    }


private:
    pair<int, int> toXY(int n, int r) {
        int x = n / r; // 能填满的行数
        int y = n % r; // 填满之后剩余的个数
        if (y==0) {
            if (x%2==0) y = 1;
            else y = r;
        } else {
            ++x;
            if (x%2 == 0) {y = r-y+1;}
        }
        x = r-x;
        y -= 1;
        return {x, y};
    }

    int toN(pair<int, int> XY, int r) {
        int x = XY.first;
        int y = XY.second;
        ++x;
        ++y;
        x = r-x;
        int res = x*r;
        if (x%2 == 0) res += y;
        else res += (r-y+1);
        return res;
    }
};
