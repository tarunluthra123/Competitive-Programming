/*
Given a binary tree , print its nodes from root to bottom as visible from right side of tree


Input Format:
Level order input for the binary tree will be given.

Constraints:
No of nodes in the tree can be less than or equal to 10^7

Output Format:
A single line containing space separated integers representing the right view of the tree

Sample Input:
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output:
1 3 6
*/
#include <iostream>
#include <queue>
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

node *buildTreeLevelWise()
{

    int d;
    cin >> d;

    node *root = new node(d);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }
        if (c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    return root;
}

void printRightSide(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    int prev = 0;

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            cout << prev << " ";
        }
        else
        {
            prev = f->data;
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

int main()
{
    node *root = buildTreeLevelWise();
    printRightSide(root);

    return 0;
}
