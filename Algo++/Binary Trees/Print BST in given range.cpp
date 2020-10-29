//https://hack.codingblocks.com/contests/c/537/1280
/*
PRINT BST KEYS IN THE GIVEN RANGE
You are given an array of integers. First of all , You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).


Input Format:
First line contains integer t as number of test cases. Each test case contains three lines. First line contains an integer n which is length of the array and second line contains n space separated integer. Third line contains the value of k1 and k2.

Constraints:
1 < t < 20
1 < n < 50

Output Format:
For each test case you have to print preorder traversal of the tree first and then print all nodes within the range k1 and k2 (inclusive).

Sample Input:
1
5
4 3 2 5 6					//this is not preorder given ..this is a random array
3 5
Sample Output:
# Preorder : 4 3 2 5 6 
# Nodes within range are : 3 4 5 
*/


#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data ;
    node *right ;
    node *left;
    node(int d){
        data = d ;
    }
};

void printNodesWithinRange(node*root,int k1,int k2){
    if(root == NULL){
        return ;
    }
    printNodesWithinRange(root->left,k1,k2);
    if(root->data >= k1 && root->data <= k2){
        cout<<root->data<<" ";
    }
    printNodesWithinRange(root->right,k1,k2);
}

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


node* ArrToBST(int* arr, node* root, int n){
	for(int i=0; i<n; i++){
		root = insertInBST(root,arr[i]);
	}
	return root;
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


int main() {
    int testCases;
    cin >> testCases;
    while(testCases --){
        int n ;
        cin >> n;
        int a[100]={0};
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int k1,k2;
        cin >> k1 >> k2 ;
        
        node *root = NULL ; 
        root = ArrToBST(a,root,n)  ;

        cout<<"# Preorder : ";
        printPreOrder(root);

        cout<<endl;
        cout<<"# Nodes within range are : ";
        printNodesWithinRange(root,k1,k2);
        cout << endl;
    }


    return 0 ;
}

