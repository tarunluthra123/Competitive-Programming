//https://www.interviewbit.com/problems/identical-binary-trees/
/*
Identical Binary Trees
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True
*/

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL) {
        return 1;
    }
    else if(A == NULL || B == NULL) {
        return 0;
    }
    else {
        if(A->val == B->val) {
            return (isSameTree(A->left,B->left) && isSameTree(A->right,B->right));
        }
        else {
            return 0;
        }
    }
}

