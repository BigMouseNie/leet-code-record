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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int iL, int iR, int pL, int pR) {
        if (iL > iR || pL > pR) return nullptr;
        int rootVal = postorder[pR];
        TreeNode* root =  new TreeNode(rootVal);
        int i;
        for (i=iL;i<=iR;++i) {
            if (inorder[i]==rootVal) break;
        }

        root->left = dfs(inorder, postorder, iL, i-1, pL, pL+i-iL-1);
        root->right = dfs(inorder, postorder, i+1, iR-1, pL+i-iL, pR-1);;
        return root;
    }
};
