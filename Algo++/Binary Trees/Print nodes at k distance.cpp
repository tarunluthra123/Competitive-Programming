/*
PRINT ALL NODES AT DISTANCE K FROM A GIVEN NODE
Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available. Print 0 if no such node exist at distance k.


Input Format:
The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT. The next line will contain an integer T. Then T lines follow you will be given 2 integers the first one denoting the value of Node and the second one denoting the value of k.

Constraints:
2 = N = 10^3

Output Format:
On T lines print space separated desired output for each test case in sorted form

Sample Input:
4
60 65 50 70
50 65 60 70
2
60 1
65 2
Sample Output:
65 70
70
Time Limit: 2 sec
*/
#include <bits/stdc++.h>
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
  
node* createTreeFromTrav(long int *inOrder,long int *preOrder,long int s,long int e){
    static long int i = 0;
    //Base Case
    if(s>e){
        return NULL;
    }
    //Rec Case
    node *root = new node(preOrder[i]);

    long int index=-1;
    for(long int j=s;s<=e;j++){
        if(inOrder[j]==preOrder[i]){
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(inOrder,preOrder,s,index-1);
    root->right = createTreeFromTrav(inOrder,preOrder,index+1,e);
    return root;
}
  
vector<int> v;

/* Recursive function to print all the nodes at distance k in the 
   tree (or subtree) rooted with given root. See  */
void printChildrenAtK(node *root, int k) { 
    if (root == NULL || k < 0)  
        return; 
  
    // If we reach a k distant node, print it 
    if (k==0) { 
       // cout << root->data << " "; 
        v.push_back(root->data);
        return; 
    } 
  
    printChildrenAtK(root->left, k-1); 
    printChildrenAtK(root->right, k-1); 
} 
  
int printkdistanceNode(node* root, int target , int k) { 
    if (root == NULL) 
        return -1; 
  
    
    if (root->data == target) { 
        printChildrenAtK(root, k); 
        return 0;
    } 
  
    // Recursive call for left subtree 
    
    //distanceLeft is Distance of root's left child from target 
    int distanceLeft = printkdistanceNode(root->left, target, k); 
  
    // Check if target node was found in left subtree 
    if (distanceLeft != -1) { 
         // If root is at distance k from target, print root 
         if (distanceLeft + 1 == k) {
            //cout << root->data << " "; 
            v.push_back(root->data);
         }
  
         // Else go to right subtree and print all k-distanceLeft-2 distant nodes 
         // Note that the right child is 2 edges away from left child 
         else
            printChildrenAtK(root->right, k-distanceLeft -2); 
  
         // Add 1 to the distance and return value for parent calls 
         return 1 + distanceLeft; 
    } 
  
    //Try the same for right subtree as well
    int distanceRight = printkdistanceNode(root->right, target, k); 
    if (distanceRight != -1) { 
         if (distanceRight + 1 == k) {
            //cout << root->data << " "; 
            v.push_back(root->data);
         }
         else
            printChildrenAtK(root->left, k-distanceRight-2); 

         return 1 + distanceRight; 
    } 
  
    return -1; 
} 


int main(){
    long n;
    cin >> n;
    long inOrder[n],preOrder[n];
    for(long i=0;i<n;i++){
        cin >> preOrder[i];
    }
    for(long i=0;i<n;i++){
        cin >> inOrder[i];
    }

    node *root = createTreeFromTrav(inOrder,preOrder,0,n-1);

    int testCases;
    cin >> testCases;
    while(testCases--){
        long k,target;
        cin >> target >> k;
        v.clear();
        printkdistanceNode(root,target,k);
        if(v.size() == 0){
            cout << "0";
        }
        else{
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
