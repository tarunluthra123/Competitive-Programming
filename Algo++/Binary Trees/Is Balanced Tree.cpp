/*
Given a Binary tree check if it is balanced i.e. depth of the left and right sub-trees of every node differ by 1 or less.


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints:
None

Output Format:
Display the Boolean result

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output:
true
Time Limit: 4 sec
*/
#include <iostream>
#include <queue>
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
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
//In

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
int height(node*root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right) ; 
    return max(ls,rs)+1;
}

bool isHeightBalanced(node*root) {
    if(root == NULL){
        return true ;
    }
    int leftHeight = height(root->left) ;
    int rightHeight = height(root->right) ;
    bool isLeftBalanced = isHeightBalanced(root->left) ; 
    bool isRightBalanced = isHeightBalanced(root->right) ;
    if(abs(leftHeight-rightHeight)<=1 && isLeftBalanced && isRightBalanced) {
        return true;
    }
    return false ;
}
int main() {
    node*root = build("true") ;

    cout<<boolalpha<<isHeightBalanced(root) ;

    return 0 ;
}

