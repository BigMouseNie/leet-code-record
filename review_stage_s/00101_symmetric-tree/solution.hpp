#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({root->left, root->right});
        while (!stk.empty()) {
            TreeNode* f = stk.top().first;
            TreeNode* s = stk.top().second;
            stk.pop();
            if (!f && !s) continue;
            if (f && s && f->val == s->val){
                stk.push({f->left, s->right});
                stk.push({f->right, s->left});
                continue;
            }
            return false;
        }
        return true;
    }
};
