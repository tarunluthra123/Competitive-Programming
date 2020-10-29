/*
https://hack.codingblocks.com/contests/c/537/961
VERTICAL ORDER PRINT BINARY TREE
You will be given a Binary Tree. Your task is to print the binary tree in Vertical Fashion. The image below describes how we define a vertical traversal of a tree.


Input Format:
You will be given an Integer N denoting the number of levels in the corresponding tree. On the next line you will be given (2^N)-1 integers denoting the level order input for the tree. If at any level any node is absent then that will denoted by -1 and every integer other than -1 shows the presence of a node at that level.

Output Format:
Print all nodes of a given column in the same line.

Sample Input:
4 
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
Sample Output:
4
2
1 5 6
3 8 
7
9
*/
#include <iostream>
#include <map>
#include <vector>
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


node* buildTreeLevelWise(){

	int d;
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void verticalOrderPrint(node*root,map<int,vector<int> > &m,int d=0){
    if(root == NULL){
        return ;
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left,m,d-1);
    verticalOrderPrint(root->right,m,d+1);
}


int main(){
    int levels ;
    cin >> levels ;
    node *root = buildTreeLevelWise() ;
   // bfs(root);
    //cout <<"\n\n\n";
    map<int,vector<int> > m;
    verticalOrderPrint(root,m);
    for(auto itr = m.begin();itr!=m.end() ; itr++){
        for(int j=0;j<itr->second.size();j++){
            cout<<itr->second[j]<<" ";
        }
        cout << endl;
    }

    return 0;
}
