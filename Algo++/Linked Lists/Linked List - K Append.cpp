/*
Linked List - K Append
Append the last K elements of a linked list to the front.K can be greater than N.


Input Format:
Enter the size N, N space separated elements and number of elements that are to be appended(n).

Constraints:
None

Output Format:
Display all the elements in the list

Sample Input:
7
1 2 2 1 8 5 6
3
Sample Output:
8 5 6 1 2 2 1
Explanation:
for 1-> 2-> 3 -> 4 -> 5 -> 6 -> null and n = 2 return 5? 6? 1? 2? 3 ? 4 ? null
*/
//https://hack.codingblocks.com/contests/c/537/316
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

node* appendK(node *head,long k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i<k && fast->next!=NULL ;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}

int main() {
    node *head = NULL;
    long n;
    cin>>n;
    getLinkedList(head,n);
    //print(head);
    long k ;
    cin>>k;
    k=k%n;
    if(k==0)
        print(head);
    else {
        head = appendK(head,k);
        print(head);
    }
    return 0;
}

