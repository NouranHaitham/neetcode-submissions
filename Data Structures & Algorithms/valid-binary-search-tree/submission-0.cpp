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

private:

bool isValid(TreeNode* root, int mn = -2e9, int mx = 2e9)
{
    // base case
    if(!root) return 1;

    // transition
    if(root->val > mn && root->val < mx)
    {
        bool left = isValid(root->left,mn,root->val);
        bool right = isValid(root->right,root->val,mx);

        return left && right;
    }
    else
    {
        return 0;
    }

}


public:
    bool isValidBST(TreeNode* root) {
        return isValid(root);
    }
};
