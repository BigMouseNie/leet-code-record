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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* upNode = nullptr;
        while (!stk.empty()) {
            TreeNode* curNode = stk.top();
            stk.pop();
            if (!curNode) continue;
            if (upNode) upNode->right = curNode;
            stk.push(curNode->right);
            stk.push(curNode->left);
            curNode->right = nullptr;
            curNode->left = nullptr;
            upNode = curNode;
        }
        return;
    }
};
