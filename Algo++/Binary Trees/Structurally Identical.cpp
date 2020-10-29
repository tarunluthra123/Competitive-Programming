/*
STRUCTURALLY IDENTICAL (BINARY TREE)
Given two trees check if they are structurally identically


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints:
None

Output Format:
Display the Boolean result

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
23 true 22 true 60 false false true 65 false false true 23 true 78 false false true 42 false false
Sample Output:
true
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

bool sameStructure(node*r1,node*r2) {
    if(r1 == NULL && r2 == NULL) {
        return true ;
    }
    if(r1 == NULL || r2 == NULL) {
        return false ;
    }
    bool leftPart = sameStructure(r1->left,r2->left) ;
    bool rightPart = sameStructure(r1->right,r2->right) ; 

    return (leftPart && rightPart)  ;
}

int main() {
    node*root1 = build("true") ;
    node*root2 = build("true") ;

    cout<<boolalpha<<sameStructure(root1,root2) ; 



    return 0 ;
}

