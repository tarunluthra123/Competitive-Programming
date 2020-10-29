/*
Kth element from last
Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.


Input Format:
First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

Constraints:
n < 10^5

Output Format:
Output a single line containing the node value at the kth element from last.

Sample Input:
1 2 3 4 5 6 -1
3
Sample Output:
4
Explanation:
The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4

*/
#include <iostream>
using namespace std;
class node {
public:
    long data;
    node *next;
    node(long d){
        data = d;
        next = NULL;
    }
};

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void buildList(node*&head){
    long x;
    cin>>x;
    head = new node(x);
    node *current = head;
    while(1){
        cin>>x;
        if(x==-1)
            break;
        node *n = new node(x);
        current->next = n;
        current = n;
    }
    current->next = NULL;
}

node* kFromLast(node* head,long k){
    node* slow = head;
    node* fast = head;
    while(k--){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


int main() {
    node *head = NULL;
    buildList(head);
    print(head);
    long k ;
    cin>>k;
    node*q = kFromLast(head,k);
    cout<<q->data;
    return 0;
}

