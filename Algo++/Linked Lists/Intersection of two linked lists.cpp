/*
Intersection of two linked lists
There are two linked lists. Due to some programming error, the end node of one of the linked list got linked into the second list, forming an inverted Y shaped list. Now it's your job to find the point(Node) at which the two linked lists are intersecting.


Input Format:
The first line of input is the size(N1) of the first linked list, followed by its content(Xi). The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).

Constraints:
1<=N, N2<=100
0<=Xi, Yi<=100

Output Format:
A single integer denoting the intersection point of two linked lists. If the linked lists are not intersecting at any point then print -1.

Sample Input:
5
10 20 30 40 50
4
15 25 40 50
Sample Output:
40
Explanation:
First and second linked list intersect at the node whose data value is 40.
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

bool isPresent(node *head,node *key){
    int data = key->data;
    while(head!=NULL){
        if(head->data == data){
            return true;
        }
        head = head->next;
    }
    return false;
}

node* findIntersection(node *a,node *b){
    while(b!=NULL){
        if(isPresent(a,b)){
            return b;
        }
        b = b->next;
    }
    return NULL;
}

int main() {
    node *a= NULL;
    node *b = NULL;
    long n1,n2;
    cin>>n1;
    getLinkedList(a,n1);
    cin>>n2;
    getLinkedList(b,n2);

    node *q = findIntersection(a,b);
    if(q == NULL)       //do not intersect
        cout<<"-1";
    else
        cout<<q->data;

    return 0;
}

