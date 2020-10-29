/*
Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.


Input Format:
The first line contains a number n showing the length of the inorder array of BST.
The next n line contains an integer denoting the elements of the array

Constraints:
2 = N = 10^3

Output Format:
Print the preorder traversal of the new bst

Sample Input:
7
20 30 40 50 60 70 80
Sample Output:
260 330 350 300 150 210 80
Time Limit: 3 sec
*/
#include <iostream>
#include<queue>
#include<climits>
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

node* buildTreeFromArray(long int *a,long int s,long int e){
    //Base Case
    if(s>e){
        return NULL;
    }
    //Recursive Case
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;
}

long sumUpTheArray(long *a,long n,long i){
    if(i==n-1){
        return a[i];
    }
    a[i] = a[i] + sumUpTheArray(a,n,i+1);
    return a[i];
}

void printPreOrder(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main(){
    long n;
    cin >> n;
    long a[n];
    for(long i=0;i<n;i++){
        cin >> a[i];
    }
    sumUpTheArray(a,n,0);
    node *root = buildTreeFromArray(a,0,n-1);

    printPreOrder(root);


    return 0;
}
