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

bool path(TreeNode* root, TreeNode* node,vector<TreeNode*>& v)
{
    if(!root) return 0;

    v.push_back(root);

    if(root->val == node->val) return 1;
    if(path(root->left,node,v) 
    || path(root->right,node,v)) return 1;
    
    v.pop_back();
    return 0;
}


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> pathP,pathQ;
        path(root,p,pathP);
        path(root,q,pathQ);

        TreeNode* lca = root;

        int n = min(pathP.size(), pathQ.size());
        for(int i=1;i<n;i++)
        {
            if(pathP[i]->val == pathQ[i]->val) lca = pathP[i];
        }

        return lca;
    }
};
