//Linked List
//Inserting ,searching and deleting elements

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

void insertAtHead(node*&head,int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

int length(node*head){
    
    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}

void insertAtTail(node*&head,int data){
    
    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(node*&head,int data,int p){
    
    if(head==NULL||p==0){
        insertAtHead(head,data);
    }   
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        //Insert in the middle 
        //Take p-1 jumps
        int jump=1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump += 1;
        }
        
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
        
    }
}

void print(node*head){
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}
void deleteAtTail(node* &head){
    node *prev = NULL;
    node *temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}
void deleteInTheMiddle(node*&head,int p){
    
    if(head == NULL || p==0){
        deleteAtHead(head);
    }
    else if(p>length(head)){
        deleteAtTail(head);
    }
    else{
        int jumps = 1 ;
        node *n = head;
        while(jumps<p-1){
            jumps++;
            n = n->next;
        }
        node *temp = n->next;
        n->next = temp->next;
        delete temp;
    }    
}


bool searchRecursive(node*head,int key){
    if(head==NULL){
        return false;
    }
    //Rec Case 
    if(head->data ==key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}
bool searchIterative(node*head,int key){
    
    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main() {
    node*head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtTail(head,6);
    
    insertInMiddle(head,2,3);
    print(head);
    
    
    if(searchRecursive(head,4)){
        cout<<"Element is present !"<<endl;
    }
    else{
        cout<<"Not present !";
    }
    if(searchIterative(head,14)){
        cout<<"Element is present !";
    }
    else{
        cout<<"Not present !";
    }
    
    
    deleteAtHead(head);
    print(head);
    deleteAtTail(head);
    print(head);
    deleteInTheMiddle(head,3);
    print(head);
    
    return 0;
}


