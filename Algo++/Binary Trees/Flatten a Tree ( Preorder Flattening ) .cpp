#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

pair<node *, node *> flattenTree(node *root)
{

    pair<node *, node *> p;
    if (root == NULL)
    {
        p.first = p.second = NULL;
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return make_pair(root, root);
    }
    else if (root->left == NULL)
    {
        pair<node*, node*> rightPart = flattenTree(root->right);
        root->right = rightPart.first;
        p.first = root;
        p.second = rightPart.second;
    }
    else if (root->right == NULL)
    {
        pair<node *, node *> leftPart = flattenTree(root->left);
        leftPart.second->right = root;
        p.first = leftPart.first;
        p.second = root;
    }
    else
    {
        pair<node *, node *> leftPart = flattenTree(root->left);
        pair<node *, node *> rightPart = flattenTree(root->right);
        leftPart.second->right = root;
        root->right = rightPart.first;
        // leftPart.second->right = rightPart.first;
        p.first = leftPart.first;
        p.second = rightPart.second;
    }

    return p;
}

void nullify(node *root)
{
    // cout << "ok";
    while (root != NULL)
    {
        // cout << root->data << "-" ;
        root->left = NULL;
        root = root->right;
    }
}
node *flatten(node *root)
{
    pair<node *, node *> ans = flattenTree(root);
    nullify(ans.first);
    return ans.first;
}

void printLinkedList(node *head) {
    node *temp = head;
    while(temp != NULL) {
        if(temp->left != NULL) {
            cout << "-1" << endl;
        }
        cout << temp->data << " " ;
        temp = temp->right;
    }
}

node *createTreeFromTrav(const vector<int> &inOrder, const vector<int> &preOrder, int s, int e)
{
    static int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(preOrder[i]);

    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (inOrder[j] == preOrder[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(inOrder, preOrder, s, index - 1);
    root->right = createTreeFromTrav(inOrder, preOrder, index + 1, e);
    return root;
}


int main()
{
    int n;
    cin >> n;

    vector<int> inOrder(n), preOrder(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    node *root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

    // print(root);


    // cout << "Preorder = " ;
    // printPreOrder(root);

    // cout << endl;

    node *head = flatten(root);


    printLinkedList(head);

    return 0;
}

