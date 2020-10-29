//https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
/*
Inorder Traversal of Cartesian Tree
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
*/
int maxIndex(vector<int> &A,int s,int e) {
    int index = s;
    for(int i=s;i<=e;i++) {
        if(A[i] > A[index]) {
            index = i;
        }
    }
    
    return index;
} 

TreeNode* build(vector<int> &A,int s,int e) {
    if(s > e){
        return NULL;
    }
    
    int index = maxIndex(A,s,e);
    TreeNode *root = new TreeNode(A[index]);
    root->left = build(A,s,index-1);
    root->right = build(A,index+1,e);
    
    return root;
}

 
TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode* root = build(A,0,A.size()-1);
    return root;
}
