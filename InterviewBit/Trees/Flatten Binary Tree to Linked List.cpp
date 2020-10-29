//https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
/*
Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
pair<TreeNode*,TreeNode*> flattenTree(TreeNode*root) {
    
    pair<TreeNode*,TreeNode*> p;
    if(root == NULL) {
        p.first = p.second = NULL;
        return p;        
    }

        
    
    if(root->left == NULL && root->right==NULL) {
        return make_pair(root,root);
    }
    else if(root->left == NULL) {
        pair<TreeNode*,TreeNode*> rightPart = flattenTree(root->right);
        root->right = rightPart.first;
        p.first = root;
        p.second = rightPart.second;
    }
    else if(root->right == NULL) {
        pair<TreeNode*,TreeNode*> leftPart = flattenTree(root->left);
        // leftPart.second->right = root;
        root->right = leftPart.first;
        p.first = root;
        p.second = leftPart.second;
    }
    else {
        pair<TreeNode*,TreeNode*> leftPart = flattenTree(root->left);
        pair<TreeNode*,TreeNode*> rightPart = flattenTree(root->right);
        root->right = leftPart.first;
        leftPart.second->right = rightPart.first;
        p.first = root;
        p.second = rightPart.second;
    }
    
    return p;
}

void nullify(TreeNode*root) {
    
    while(root!=NULL) {
        root->left = NULL;
        root= root->right;
    }
}
TreeNode* Solution::flatten(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    pair<TreeNode*,TreeNode*> ans = flattenTree(root);
    nullify(root);
    return ans.first;
}


