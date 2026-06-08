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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> stk;
        if ((!p && !q)) return true;
        if (p && q && p->val == q->val)
            stk.push({p, q});
        else return false;

        while (!stk.empty()) {
            auto _pair = stk.top();
            stk.pop();
            TreeNode* f = _pair.first;
            TreeNode* s = _pair.second;
            if (f->left && s->left && f->left->val == s->left->val) {
                stk.push({f->left, s->left});
            } else if (!(!f->left && !s->left)) {
                return false;
            }

            if (f->right && s->right && f->right->val == s->right->val) {
                stk.push({f->right, s->right});
            } else if (!(!f->right && !s->right)) {
                return false;
            }
        }

        return true;
    }
};
