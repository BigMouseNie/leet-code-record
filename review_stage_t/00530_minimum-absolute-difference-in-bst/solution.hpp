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
    int getMinimumDifference(TreeNode* root) {
        res = -1;
        upVal = -1;
        dfs(root);
        return res;
    }
private:

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (upVal != -1) {
            if (res == -1) res = root->val - upVal;
            else res = min(res, root->val - upVal);
        }
        upVal = root->val;
        dfs(root->right);
    }

    int res = -1;
    int upVal = -1;
};
