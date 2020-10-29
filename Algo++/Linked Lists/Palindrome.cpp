/*
PALINDROME
Check if a linked list is a palindrome.( Boolean return type )


Input Format:
Add N space separated elements in the list

Constraints:
None

Output Format:
Boolean answer( true or false)

Sample Input:
5
1 2 3 6 8
Sample Output:
False
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

node* kFromLast(node* head,long k){
    node* slow = head;
    node* fast = head;
    while(k--){
        fast = fast->next;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(node*head,long n){
    node *tempHead = head;
    for(long i=0;i<n;i++){
        if(head->data != kFromLast(tempHead,i)->data){
            return false;
        }
        head = head->next;
    }
    return true;
}

int main(){
    node *head = NULL;
    long n;
    cin>>n;
    getLinkedList(head,n);
    cout<<boolalpha<<isPalindrome(head,n);
    return 0;
}
