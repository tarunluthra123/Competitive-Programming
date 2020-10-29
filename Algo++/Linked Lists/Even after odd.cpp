/*
EVEN-AFTER-ODD
Arrange elements in a Linked List such that all even numbers are placed after odd numbers.


Input Format:
Enter N space separated Elements

Constraints:
None

Output Format:
Linked list with all the odd numbers before even numbers

Sample Input:
5
1 2 2 2 1
Sample Output:
1 1 2 2 2
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

node* evenAfterOdd(node*head){
    node *odd = NULL;
    node *even = NULL;
    node *oddTemp = NULL;
    node *evenTemp = NULL ;
    node *temp = head ;
    while(temp!=NULL){
        if(temp->data & 1){
            //Number is odd
            if(odd == NULL){
                odd = temp ;
                oddTemp = temp ;
            }
            else {
                oddTemp->next = temp;
                oddTemp = temp;
            }
        }
        else {
            //Number is even
            if(even == NULL){
                even = temp ; 
                evenTemp = temp ;
            }
            else {
                evenTemp->next = temp;
                evenTemp = temp ;
            }
        }
        temp = temp->next ;
    }
    if(evenTemp!=NULL)
        evenTemp->next = NULL ;
    
    if(odd == NULL){
        //In case there were no odd numbers
        return even ;
    }

    oddTemp->next = even ;
    return odd ;
}

int main() {
    node *head = NULL;
    long n;
    cin>>n;
    getLinkedList(head,n);
  //  print(head);
    head = evenAfterOdd(head);
    print(head);

    return 0;
}

