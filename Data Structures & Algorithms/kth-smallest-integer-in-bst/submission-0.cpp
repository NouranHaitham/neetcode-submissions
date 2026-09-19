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

void inorderTraversal(TreeNode* root, int& k, int& val)
{
    // base case
    if(!root) return;

    // transition
    inorderTraversal(root->left,k,val);
    cout<<root->val<<"\n";
    k--;
    if(k == 0) val = root->val;
    inorderTraversal(root->right,k,val);
    
}


public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorderTraversal(root,k,ans);
        return ans;
    }
};
