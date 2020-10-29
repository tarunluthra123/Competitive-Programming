/*
BUILD BST
You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.


Input Format:
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the data and next line contains n space separated integers.

Constraints:
1 < t < 100
1< n < 1000

Output Format:
Print the preorder of the tree.

Sample Input:
1
7
1 2 3 4 5 6 7
Sample Output:
4 2 1 3 6 5 7
*/
#include <iostream>
using namespace std;

class node{
    public:
        node(int d){
            data = d;
        }
        int data ;
        node *right;
        node *left ;
};

void printPreOrder(node *root) {
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    printPreOrder(root->left) ; 
    printPreOrder(root->right) ; 
}

node* buildBalancedBST(int *a,int s,int e){
    if(s>e){
        return NULL ; 
    }
    int mid = (s+e)/2;
    node *root = new node(a[mid]);
    root->left = buildBalancedBST(a,s,mid-1);
    root->right = buildBalancedBST(a,mid+1,e);

    return root;
}

int main() {
    int testCases;
    cin >> testCases; 
    while(testCases--){
        int n ;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i] ; 
        }
        node*root = buildBalancedBST(a,0,n-1);
        printPreOrder(root) ; 
        cout<<endl ;
    }

    return 0;
}

