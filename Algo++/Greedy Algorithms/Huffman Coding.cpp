#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int freq;
    char data;
    node *left, *right;
    string code;

    node(int f = 0, char ch = '.')
    {
        freq = f;
        data = ch;
        left = right = NULL;
        code = "";
    }

    node(const node &x)
    {
        freq = x.freq;
        data = x.data;
        left = x.left;
        right = x.right;
        code = x.code;
    }
};

class MyCompare
{
public:
    bool operator()(node a, node b)
    {
        return a.freq > b.freq;
    }
};

void traverse(node *root)
{
    string s = root->code;
    if (root->left != NULL)
    {
        root->left->code = s + "0";
        root->right->code = s + "1";
        traverse(root->left);
        traverse(root->right);
    }
    else
    {
        cout << "Data = " << root->data << "   Code = " << root->code << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    priority_queue<node, vector<node>, MyCompare> pq;

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;
        cin >> ch >> freq;
        pq.push(node(freq, ch));
    }
    // cout << "thik hai";

    while (pq.size() > 1)
    {
        node *a = new node(pq.top());
        pq.pop();
        node *b = new node(pq.top());
        pq.pop();
        node c;
        c.freq = a->freq + b->freq;
        c.left = a;
        c.right = b;
        pq.push(c);
        // cout << "Pushing c - " << c.freq << endl;
    }

    node root = pq.top();
    root.code = "";

    // cout << "ok";
    traverse(&root);

    return 0;
}
