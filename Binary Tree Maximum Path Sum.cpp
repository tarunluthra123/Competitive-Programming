/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int ans ;
    int maxPath(TreeNode *root) {
        if(root == NULL)
            return 0;
        int leftPath = max(0, maxPath(root->left));
        int rightPath = max(0, maxPath(root->right));
        
        ans = max(ans, root->val + leftPath + rightPath);
        
        return root->val + max(leftPath,rightPath);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        
        maxPath(root);
        
        return ans;
    }
};
