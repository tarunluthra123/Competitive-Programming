/*
You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree.


Input Format:
First line contains integer t as number of test cases. Each test case It contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers.

Constraints:
1 < t < 100
1< n,m < 1000

Output Format:
Print the preorder of the tree

Sample Input:
1
7
5 3 2 4 7 6 8
3
2 3 5
Sample Output:
4 7 6 8
*/
#include <iostream>
#include<queue>
#include<climits>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* ArrToBST(int* arr, int n){
    node*root = NULL;
    for(int i=0; i<n; i++){
        root = insertInBST(root,arr[i]);
    }
    return root;
}


node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root; 
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            node* temp = root->right;
            delete root;
            return temp;
            }
        //3. Case 2 children
        node *replace = root->right;
        //Find the inorder successor from right subtree
        while(replace->left!=NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right,replace->data);
        return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }
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
    int testCases;
    cin >> testCases ;
    while(testCases--){
        int n ;
        cin >> n;
        int a1[n];
        for(int i=0;i<n;i++){
            cin>>a1[i];
        }

        node*root = ArrToBST(a1,n);

        int m;
        cin >> m;
        int temp;

        for(int i=0;i<m;i++){
            cin >> temp;
            root = deleteInBST(root,temp);
        }

        printPreOrder(root);
        cout<<endl ;
    }


    return 0;
}
