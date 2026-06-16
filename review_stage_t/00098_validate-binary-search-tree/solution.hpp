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
    bool isValidBST(TreeNode* root) {
        int upVal = 0;
        bool flag = false;
        return dfs(root, upVal, flag);
    }

private:
    bool dfs(TreeNode* root, int& upVal, bool& flag) {
        if (!root) {
            return true;
        }
        if (dfs(root->left, upVal, flag)) {
            if (flag && root->val <= upVal){
                return false;
            }
            flag = true;
        } else {
            return false;
        }
        upVal = root->val;
        return dfs(root->right, upVal, flag);
    }

};
