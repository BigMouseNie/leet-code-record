#include <stack>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> stk;
        int deep = 1;
        stk.push({root, deep});
        while (!stk.empty()) {
            pair<TreeNode*, int> p = stk.top();
            stk.pop();
            if (p.first->right) {
                stk.push({p.first->right, p.second + 1});
                deep = max(deep, p.second + 1);
            }
            if (p.first->left) {
                stk.push({p.first->left, p.second + 1});
                deep = max(deep, p.second + 1);
            }
        }
        return deep;
    }
};
