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
    bool found;
    int ans,k;

    void helper(TreeNode* root){
        if(found || !root)
            return;
        helper(root->left);
        k--;
        if(k==0){
            ans = root->val;
            found = true;
            return;
        }
        helper(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        found = false;
        ans = -1;
        helper(root);
        return ans;
    }
};
