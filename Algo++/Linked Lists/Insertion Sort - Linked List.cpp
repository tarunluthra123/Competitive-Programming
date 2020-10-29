//Insertion Sort
/*
Given a linked list with n nodes. Sort the linked list using insertion sort.

Input Format:
First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing the node values of the linked list.

Constraints:
n < 30

Output Format
Print the linked list after sorting it using insertion sort.

Sample Input
5
2 3 4 1 5
Sample Output
1 2 3 4 5
*/


#include <iostream>
#define INT_MIN -2147483648
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

void swap(node*&a,node*&b){
    if(b==NULL){
        return ;
    }
    node *c = b->next;
    b->next = a;
    a->next = c;
}

void insertionSort(node*&head){
    //Insertion sort works for j>=0 ... that is ..it would skip the first entry
    //First entry remains unsorted in the array
    //introduce a fake entry which is the smallest number and then remove it later so the rest of the 
    //array remains sorted
    node*fake = new node(INT_MIN);
    fake->next = head;
    head = fake;
    //i=1;
    node *i = head->next;
    //i<n
    while(i!=NULL){
        //key = a[i];
        int key = i->data;
        node *j = head;

        // j = i-1
        while(j->next!=i){
            j = j->next;
        }

        //while(j>=0 && a[j]>key)
        while(j!=NULL && j->data > key){
            //a[j+1] = a[j];
            j->next->data = j->data;
            //j--
            node*temp = head;
            while(temp->next!=j && temp!=j){
                temp = temp->next;
            }
            j = temp;
        }

        //a[j+1] = key;
        j->next->data = key;

        //i++
        i = i->next;
    }
    node *q = head;
    delete q;
    head = head->next;
}

int main() {
    node *head = NULL;
    long n;
    cin>>n;
    getLinkedList(head,n);
    insertionSort(head);
    print(head);
    return 0;
}

