#include <stack>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> stk;
        if (root) stk.push({root, root->val});
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            if (p.second == targetSum && !p.first->left && !p.first->right) return true;
            if (p.first->right) 
                stk.push({p.first->right, p.first->right->val + p.second});
            
            if (p.first->left) 
                stk.push({p.first->left, p.first->left->val + p.second});
        }
        return false;
    }
};
