#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> que;
        que.push(root);
        int remain = que.size();
        vector<int> res;
        while (!que.empty()) {
            TreeNode* f = que.front();
            que.pop();
            --remain;
            if (f->left) que.push(f->left);
            if (f->right) que.push(f->right);
            if (remain == 0) {
                res.push_back(f->val);
                remain = que.size();
            }
        }
        return res;
    }
};
