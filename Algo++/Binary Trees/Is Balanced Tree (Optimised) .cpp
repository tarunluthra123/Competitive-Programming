#include <iostream>
#include <queue>
#define pib pair<int,bool>
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

pib isHeightBalancedOptimised(node *root){
    pib p ;
    if(root == NULL){
        p.first = 0 ;
        p.second = true ;
        return p;
    }

    pib left = isHeightBalancedOptimised(root->left);
    pib right = isHeightBalancedOptimised(root->right);
    
    p.first = max(left.first,right.first)+1;
    p.second = left.second && right.second && abs(left.first - right.first) <=1 ;

    return p;
}


int main() {
    node*root = build("true") ;

    cout<<boolalpha<<isHeightBalancedOptimised(root).second ;

    return 0 ;
}

