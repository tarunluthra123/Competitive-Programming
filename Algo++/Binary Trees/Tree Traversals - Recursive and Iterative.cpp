#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data ;
    node * left;
    node * right;
    node(int d) {
        data = d;
        left = right = NULL;
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
 
void inOrderRecursive(node *root) {
    if(root == NULL) 
        return ;

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

void inOrderIterative(node *root) {
    if(root == NULL)
        return ;
    stack<node*> s;

    s.push(root);
    while(root->left != NULL) {
        root = root->left;
        s.push(root);
    }

    while(!s.empty()) {
        node*temp = s.top();
        s.pop();
        cout << temp->data << " " ;
        if(temp->right != NULL) {
            temp = temp->right;
            s.push(temp);
            while(temp->left != NULL) {
                temp = temp->left;
                s.push(temp);
            }
        }
    }
}

void preOrderRecursive(node *root) {
    if(root == NULL) 
        return ;

    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

void preOrderIterative(node *root) {
    if(root == NULL)
        return ;
    stack<node*> s;
    s.push(root);
    while(!s.empty()) {
        node*temp = s.top();
        s.pop();
        cout << temp->data << " " ;
        if(temp->right != NULL) {
            s.push(temp->right);
        }
        if(temp->left != NULL) {
            s.push(temp->left);
        }
    }
}

void postOrderRecursive(node*root) {
    if(root == NULL) 
        return ;

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}

void postOrderIterative(node *root) {
    if(root == NULL) 
        return ;

    stack<node*> s1, s2;
    
    s1.push(root);

    while(!s1.empty()) {
        node * temp = s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left != NULL) {
            s1.push(temp->left);
        }
        if(temp->right != NULL) {
            s1.push(temp->right);
        }
    }

    while(!s2.empty()) {
        cout << s2.top()->data << " " ;
        s2.pop();
    }
}

int main() {
    node * root = NULL;

    root = buildTree();

    cout << "Inorder Recursive = " ;
    inOrderRecursive(root);

    cout << "\nInorder Iterative = " ;
    inOrderIterative(root);

    cout << "\nPreorder Recursive = ";
    preOrderRecursive(root);

    cout << "\nPreorder Iterative = " ;
    preOrderIterative(root);

    cout << "\nPostorder Recursive = ";
    postOrderRecursive(root);

    cout << "\nPostorder Iterative = " ;
    postOrderIterative(root);

    return 0;
}
