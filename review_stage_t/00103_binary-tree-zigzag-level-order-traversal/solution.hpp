using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        int remain = 1;
        vector<int> level;
        bool flag = false;
        while (!que.empty()) {
            TreeNode* f = que.front();
            que.pop();
            level.push_back(f->val);
            --remain;
            if (f->left) que.push(f->left); 
            if (f->right) que.push(f->right);
            if (remain == 0) {
                res.push_back({});
                if (flag) {
                    reverse(level.begin(), level.end());
                    flag = false;
                } else flag = true;
                swap(res.back(), level);
                remain = que.size();
            }
        }
        return res;
    }
};
