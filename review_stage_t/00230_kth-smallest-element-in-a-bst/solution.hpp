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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

private:
    int res = 0;
    bool c = false;
    void dfs(TreeNode* root, int& k) {
        if (!root || c) return;
        //if (!root) return;
        dfs(root->left, k);
        --k;
        if (k==0) {res = root->val; c = true;return;}
        dfs(root->right, k);
    }

};
