/*
Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left. Each level should be printed at a new line.


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints:
None

Output Format:
Display the values in zigzag level order in which each value is separated by a space

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output:
10 30 20 40 50 60 73 
Time Limit: 4 sec
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

node*build(string s){
	if(s=="true"){
        int d;
        cin>>d;
        node*root = new node(d);
        string l;
        cin>>l;
        if(l=="true"){
        root->left=build(l);
        }
        string r;
        cin>>r;
        if(r=="true"){
        root->right=build(r);
        }
        return root;
	}
	return NULL;
}

void printKthLevel(node*root,int k,bool flag){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    if(flag){
        printKthLevel(root->left,k-1,flag);
        printKthLevel(root->right,k-1,flag);
    }
    else {
        printKthLevel(root->right,k-1,flag);
        printKthLevel(root->left,k-1,flag);
    }
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

void printZigzag(node*root){
    bool flag = true ;
    for(int i=0;i<height(root);i++){
        printKthLevel(root,i,flag);
        flag = !flag ;
        cout << endl ;
    }
}

int main() {
    node*root = build("true") ;

    printZigzag(root);

    return 0 ;
}

