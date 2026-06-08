#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pL, int pR, int iL, int iR) {
        if (pL > pR || iL > iR) return nullptr;
        int rootVal = preorder[pL];
        TreeNode* root = new TreeNode(preorder[pL]);
        int i = iL;
        for (;i<=iR;++i){
            if (inorder[i] == rootVal) {
                break;
            }
        }
        root->left = dfs(preorder, inorder, pL+1, pL+i-iL, iL, i-1);
        root->right = dfs(preorder, inorder, pL+i-iL+1, pR, i+1, iR);
        return root;
    }
};
