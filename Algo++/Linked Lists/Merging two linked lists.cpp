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
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

void buildList(node*&head){
    long x;
    cin>>x;
    head = new node(x);
    node *current = head;
    while(x!=-1){
        cin>>x;
        if(x==-1)
            break;
        node *n = new node(x);
        current->next = n;
        current = n;
    }
    current->next = NULL;
}

istream& operator>>(istream &is,node*&head){
    buildList(head);
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
    node*head = NULL;
   	node *head2 = NULL;
   	
    cin>>head>>head2;
    cout<<head<<head2<<endl;

    node *head3 = merge(head,head2);
    cout<<head3;
        
    return 0;
}

