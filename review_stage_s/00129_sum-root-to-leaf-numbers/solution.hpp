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
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;  
    }

private:
    bool dfs(TreeNode* root, int upVal) {
        if (!root) return true;
        upVal = upVal * 10 + root->val;
        int l = dfs(root->left, upVal);
        int r = dfs(root->right, upVal);
        if (l && r) sum += upVal;
        return false;
    }

private:
    int sum = 0;
};
