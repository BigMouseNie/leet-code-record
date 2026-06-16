#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        auto p = build(grid, {0,0}, {grid.size()-1, grid.size()-1});
        if (p.second) return p.second;
        return new Node(grid[0][0], 1, nullptr, nullptr, nullptr, nullptr);
    }

private:
    pair<int, Node*> build(vector<vector<int>>& grid, pair<int, int> tL, pair<int, int> bR) {
        if (tL.first == bR.first) {
            return {grid[tL.first][tL.second], nullptr};
        }
        int t1 = (tL.first+bR.first)/2;
        int t2 = (tL.second+bR.second)/2;
        pair<int, Node*> tLP = build(grid, tL, {t1, t2});
        pair<int, Node*> tRP = build(grid, {tL.first, t2+1}, {t1, bR.second});
        pair<int, Node*> bLP = build(grid, {t1+1, tL.second}, {bR.first, t2});
        pair<int, Node*> bRP = build(grid, {t1+1, t2+1}, bR);

        if (!tLP.second && !tRP.second && !bLP.second && !bRP.second
           && (tLP.first == tRP.first && tLP.first == bLP.first && tLP.first == bRP.first)) {
                return tLP;
        }

        if (!tLP.second) tLP.second = new Node(tLP.first, 1, nullptr, nullptr, nullptr, nullptr);
        if (!tRP.second) tRP.second = new Node(tRP.first, 1, nullptr, nullptr, nullptr, nullptr);
        if (!bLP.second) bLP.second = new Node(bLP.first, 1, nullptr, nullptr, nullptr, nullptr);
        if (!bRP.second) bRP.second = new Node(bRP.first, 1, nullptr, nullptr, nullptr, nullptr);
        return {0, new Node(0, 0, tLP.second, tRP.second, bLP.second, bRP.second)};
    }
};
