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

TreeNode* helper(TreeNode* root,int l_inorder, int r_inorder, int& indx,vector<int>& preorder, map<int,int>& indx_inorder,bool isLeft = 0)
{
    // base case
    if(indx >= preorder.size()) return root;
    if(l_inorder > r_inorder) return root;


    // transition
    int nodeVal = preorder[indx];
    TreeNode* node = new TreeNode(nodeVal);

    if(!root) root = node;
    else if(isLeft) root->left = node;
    else root->right = node;
    

    int pivot = indx_inorder[nodeVal];
    indx++;
    helper(node,l_inorder,pivot-1,indx,preorder,indx_inorder,1);
    helper(node,pivot+1,r_inorder,indx,preorder,indx_inorder,0);

    return root;

}


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int,int> index;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            index[inorder[i]] = i;
        }

        TreeNode* root = nullptr;
        int indx = 0;
        return helper(root,0,n-1,indx,preorder,index,0);
    }
};
