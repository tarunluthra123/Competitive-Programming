/*
FIND SUM AT LEVEL K
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.


Input Format:
Tree Input and an integer K

Constraints:
1<K<10

Output Format:
A single line containing the sum

Sample Input:
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2
Sample Output:
20
*/
#include <iostream>
#include <queue>
using namespace std;
class node {
    public :
        int noOfChildren ;
        int data ; 
        node(int d,int n) {
            data = d ;
            noOfChildren = n ;
            right = left = NULL ; 
        }
        node *right ;
        node *left ;
};
int sum = 0;
void printKthLevel(node*root,int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
    //    cout<<"ok"<<endl ;
        sum += root->data;
        return ;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;

}

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

node* buildTree(node*root){
    int d,n ;
    cin >> d >> n;
    root = new node(d,n);
    if(n==0){
        return root ; 
    }
    else if(n==1){
        root->left = buildTree(root->left);
        return root ;
    }
    else {
        root->left = buildTree(root->left);
        root->right = buildTree(root->right) ; 
        return root ;
    }
}



int main() {
    node *root = buildTree(new node(0,0));
 //   bfs(root) ; 
    int k ;
    cin >> k;
//    cout << " k= "<< k <<endl ;
    printKthLevel(root,k);
    cout << sum ; 
    return 0;
}

