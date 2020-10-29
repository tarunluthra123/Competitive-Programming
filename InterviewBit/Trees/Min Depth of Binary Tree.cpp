//https://www.interviewbit.com/problems/min-depth-of-binary-tree/
/*
Min Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.
*/
int Solution::minDepth(TreeNode* A) {
    if(A == NULL)   return 100000000;
    if(A->left == NULL & A->right == NULL)
        return 1;
        
    int h1 = minDepth(A->left);
    int h2 = minDepth(A->right);
    
    return min(h1,h2)+1;
}
