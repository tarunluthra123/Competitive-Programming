#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// head - Head pointer of the Linked List
// Return a boolean value indicating the presence of cycle
// If the cycle is present, modify the linked list to remove the cycle as well
bool floydCycleRemoval(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL && fast != slow)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL || fast->next == NULL)
    {
        //No cycle present
        return false;
    }

    if (fast->next == head)
    {
        fast->next = NULL;
        return true;
    }

    slow = head;
    fast = fast->next;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return true;
}

Node *buildCycleList()
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    Node *head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            current->next = hash[x];
            return head;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = buildCycleList();

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent)
    {
        cout << "Cycle was present\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}
