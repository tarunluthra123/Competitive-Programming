/*
Linked List - K Reverse
Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format:
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints:
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2


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

void getLinkedList(node *&head,long n){
    long x;
    cin>>x; //first input;
    head = new node(x);
    node *current = head;
    for(long i=1;i<n;i++){
        cin>>x;
        node *n = new node(x);
        current->next = n;
        current = n;
    }
    current->next = NULL;
}

void reverse(node*&head){
    node *c = head;
    node *p = NULL;
    node *n ;
    while(c!=NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
}

node* reverseK(node*head,long k){
    //Base case
    if(head == NULL)
        return head;

    //Rec case
    node *temp = head;
    for(long i=1;i<k;i++){
        temp = temp->next;
    }
    node *p = temp->next;
    temp->next = NULL;
    node *q = head;
    reverse(head);
    q->next = reverseK(p,k);

    return head;
}

int main() {
    node *head = NULL;
    long n;
    cin>>n;
    long k;
    cin>>k;
    getLinkedList(head,n);
    head = reverseK(head,k);
    print(head);

    return 0;
}

