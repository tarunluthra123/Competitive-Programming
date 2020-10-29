#include <iostream>
#include<queue>
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

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
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

void printIn(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}


int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

void printKthLevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;

}

void printAllLevels(node*root){
    int H = height(root);

    for(int i=1;i<=H;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}

int count(node*root){
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
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


class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}


int replaceSum(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    //Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}


class HBPair{
public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node *root){
    HBPair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recurisve Case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = max(left.height,right.height) + 1;

    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}


void mirror(node*root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
    return;
}

node* buildTreeFromArray(int *a,int s,int e){
    //Base Case
    if(s>e){
        return NULL;
    }
    //Recursive Case
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;
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

//Deletes the temp node from the tree
node* deleteUsingMerging(node *root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data > key) {
        //We have to delete some node in left subtree
        root->left = deleteUsingMerging(root->left, key);
        return root;
    }
    else if(root->data < key) {
        //We have to delete some node in right subtree
        root->right = deleteUsingMerging(root->right, key);
        return root;
    }

    //We have to delete the current node at which we are standing

    //If it is a leaf node , simply delete it and do nothing
    if(root->left == NULL && root->right == NULL) {
        //If it is a leaf node , simply delete it and do nothing
        delete root;
        return NULL;
    }
    else if(root->left == NULL) {
        //Only right child exists
        node * temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL) {
        //Only left child exists
        node * temp = root->left;
        delete root;
        return temp;
    }
    else {
        //Both the children exist. Delete using merging
        //Find its inorder predecessor
        node *p = root->left;
        while(p->right != NULL) {
            p = p->right;
        }

        p->right = root->right;
        p = root;
        root = root->left;
        delete p;

        return root;
    }

}


int main(){ 
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(in)/sizeof(int);

    node*root = createTreeFromTrav(in,pre,0,n-1);
    bfs(root);
    
    
    root = deleteUsingMerging(root, 5);

    


return 0;
}











