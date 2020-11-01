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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        q.push(NULL);
        int prev=0;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(f==NULL){
                res.push_back(prev);
                if(q.empty())break;
                else{
                    q.push(NULL);
                }
            }
            else {
                prev = f->val;
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }

        return res;
    }
};
