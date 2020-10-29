//https://www.interviewbit.com/problems/recover-binary-search-tree/
/*
Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST
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
 
pair<int,int> finalAns;
 
pair<int,int> check(TreeNode *root) {
    if(root == NULL) {
        return make_pair(INT_MAX,INT_MIN);
    }
    
    pair<int,int> leftChild = check(root->left);
    pair<int,int> rightChild = check(root->right);
    
    if(rightChild.first < leftChild.second) {
        finalAns.first = rightChild.first;
        finalAns.second = leftChild.second;
    } else if(leftChild.second > root->val){// && ((finalAns.first == 0 && finalAns.second == 0)||(finalAns.second==leftChild.second)||finalAns.first ==root->val))  {
        finalAns.first = root->val;
        finalAns.second = leftChild.second;
    } else if(rightChild.first < root->val){// && ((finalAns.first == 0 && finalAns.second == 0)||(finalAns.second==rightChild.first)||finalAns.first ==root->val)) {
        finalAns.first = root->val;
        finalAns.second = rightChild.first;
    } 
    
    pair<int,int> ans ;
    ans.first = min(leftChild.first, min(rightChild.first, root->val));
    ans.second = max(leftChild.second, max(rightChild.second, root->val));
    
    return ans;
} 

vector<int> Solution::recoverTree(TreeNode* A) {
    finalAns.first = finalAns.second = 0;
    check(A);
    vector<int> v;
    v.push_back(finalAns.first);
    v.push_back(finalAns.second);
    sort(v.begin(),v.end());
    return v;
}


