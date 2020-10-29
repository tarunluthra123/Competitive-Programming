/*
MERGE SORTED LINKED LISTS
Given 2 sorted linked lists , Merge the two given sorted linked list and print the final LinkedList.


Input Format:
First Line contains T the number of test cases. For each test case : Line 1 : N1 the size of list 1 Line 2 : N1 elements for list 1 Line 3 : N2 the size of list 2 Line 4 : N1 elements for list 2

Constraints:
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= Ai <= 10^7

Output Format:
T lines of merged output

Sample Input:
1
4
1 3 5 7
3
2 4 6
Sample Output:
1 2 3 4 5 6 7 
*/
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    
    //Constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

void print(node*head){
    //node*temp = head;
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void getLinkedList(node *&head,long n){
    if(n == 0){
        head = NULL ; 
        return ; 
    }
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

istream& operator>>(istream &is,node*&head){
    long n ;
    cin >> n;
    getLinkedList(head,n);
    return is;
}

ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}

node* merge(node *a,node *b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}

int main() {
    int testCases;
    cin >> testCases ; 
    while(testCases--){
        node*head = NULL;
        node *head2 = NULL;
        
        cin >> head >> head2 ;
        //cout<<head<<head2<<endl;

        node *head3 = merge(head,head2);
        cout<<head3;
    }
            
    return 0;
}

