/*
Given a Binary Tree, write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST)


Input Format:
The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT.

Constraints:
2 = N = 10^3

Output Format:
A single integer denoting the largest bst in a bt.

Sample Input:
4
60 65 50 70
50 65 60 70
Sample Output:
2
Time Limit: 5 sec
*/
#include <bits/stdc++.h>
using namespace std;

class node{
public:
    long data;
    node*left;
    node*right;

    node(long d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


node* createTreeFromTrav(long int *in,long int *pre,long int s,long int e){
    static long int i = 0;
    //Base Case
    if(s>e){
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    long int index=-1;
    for(long int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in,pre,s,index-1);
    root->right = createTreeFromTrav(in,pre,index+1,e);
    return root;
}

bool isBST(node *root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}

long count(node*root){
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

long sizeOfMaxBST(node*root){
    long maxSize = 0;
    if(root == NULL){
        return 0;
    }
    if(isBST(root)){
        maxSize = max(maxSize,count(root));
    }
    return max(maxSize,max(sizeOfMaxBST(root->left),sizeOfMaxBST(root->right)));
}

int main(){
    long n;
    cin >> n;
    
    long preOrder[n],inOrder[n];
    for(int i=0;i<n;i++){
        cin >> preOrder[i];
    }
    for(int i=0;i<n;i++){
        cin >> inOrder[i];
    }
    node*root = createTreeFromTrav(inOrder,preOrder,0,n-1);

    cout<<sizeOfMaxBST(root);
    return 0;
}


/*
Better Approach 


#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}
class Info
{
public:
    bool is_bst;
    int maxBSTsize;
    int leftmax;
    int rightmin;
    Info()
    {
        is_bst = true;
        maxBSTsize = 0;
        leftmax = INT_MIN;
        rightmin = INT_MAX;
    }
};

Info greatestBSTinBT(node *root)
{

    if (root == NULL)
    {
        return Info();
    }

    Info left = greatestBSTinBT(root->left);
    Info right = greatestBSTinBT(root->right);
    Info ans;
    if (root->data >= left.leftmax && root->data < right.rightmin &&
        left.is_bst && right.is_bst)
    {
        ans.maxBSTsize = left.maxBSTsize + right.maxBSTsize + 1;
        ans.is_bst = true;
        ans.leftmax = max(left.leftmax, root->data);
        ans.rightmin = min(right.rightmin, root->data);
    }
    else
    {
        ans.is_bst = false;
        ans.maxBSTsize = max(left.maxBSTsize, right.maxBSTsize);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int preOrder[10000], inOrder[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    node *root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

    cout << greatestBSTinBT(root).maxBSTsize;
    return 0;
}
*/
