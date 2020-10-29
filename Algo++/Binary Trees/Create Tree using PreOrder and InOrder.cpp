/*
CREATE TREE ( USING PREORDER AND INORDER)
Given preorder and inorder create the tree


Input Format:
Enter the size of the preorder array N then add N more elements and store in the array, then enter the size of the inorder array M and add M more elements and store in the array

Constraints:
None

Output Format:
Display the tree using the display function

Sample Input:
3
1
2
3
3
3
2
1
Sample Output:
2 => 1 <= END
3 => 2 <= END
END => 3 <= END
Time Limit: 4 sec
*/
#include <iostream>
#include <queue>
#define ll long long 
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

node* createTreeFromTrav(int *inOrder,int *preOrder,int s,int e){
    static int i = 0;
    //Base Case
    if(s>e){
        return NULL;
    }
    //Rec Case
    node *root = new node(preOrder[i]);

    int index = -1;
    for(int j=s; s <= e;j++){
        if(inOrder[j] == preOrder[i]){
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(inOrder, preOrder, s, index-1);
    root->right = createTreeFromTrav(inOrder, preOrder, index+1, e);
    return root;
}

void print(node*root)
{
    if(root==NULL){
        return;
    }
    if(root->left)
        cout << root->left->data;
    else
        cout << "END" ;

    cout<<" => "<<root->data<<" <= ";

    if(root->right)
        cout<<root->right->data;
    else
        cout<<"END";
    cout<<endl ;
    print(root->left);
    print(root->right);
}


int main() {
    int inOrder[100],preOrder[100],n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> preOrder[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> inOrder[i];
    }

    node *root = createTreeFromTrav(inOrder,preOrder,0,n-1) ; 

    print(root) ; 

    return 0 ;
}

