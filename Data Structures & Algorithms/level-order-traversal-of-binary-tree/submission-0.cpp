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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        int lvl_sz = q.size();

        while(q.size())
        {

            vector<int> lvl;
            while(lvl_sz--)
            {
                TreeNode* node = q.front();
                q.pop();

                lvl.push_back(node->val);

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);

            }

            ans.push_back(lvl);
            lvl_sz = q.size();
        }

        return ans;
    }
};
