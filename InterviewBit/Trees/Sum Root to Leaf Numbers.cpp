//https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
/*
Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
*/
int MOD = 1003;
int rev(TreeNode* root, int sum) {
    if(root == NULL)
        return 0;
    sum =( (sum*10) + root->val ) %MOD;
    if(root->left == NULL && root->right == NULL) {
        return sum % MOD;
    }
    int ans = 0;
    if(root->left) {
        ans = (ans + rev(root->left,sum))%MOD;
    }
    
    if(root->right) {
        ans = (ans + rev(root->right,sum))%MOD;
    }
    
    return ans%MOD;
}
 
int Solution::sumNumbers(TreeNode* A) {
    return rev(A, 0);
}
