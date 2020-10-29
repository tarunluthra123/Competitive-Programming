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

//Takes n inputs
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

node* midPoint(node*head){
    node *slow = head;
    node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node *a,node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
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

node* mergeSort(node *head){
    //Base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //Rec case
    //1. Find mid point
    node *mid = midPoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    //2. Recursively sort
    a = mergeSort(a);
    b = mergeSort(b);

    //3. Merge the two sorted lists
    node *c = merge(a,b);
    return c;
}

node* appendK(node *head,long k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i<k;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}

void swap(node*&a,node*&b){
    if(b==NULL){
        return ;
    }
    node *c = b->next;
    b->next = a;
    a->next = c;
}


//Takes input till get a -1
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

void printWithoutCycle(node *head){
    node *p = head;
    while(head!=NULL){
        int x = head->data;
        node *q = p;
        while(q!=head){
            if(q->data == x){
                return ;
            }
            q = q->next;
        }
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
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
    node *head = NULL;
    //long n;
    //cin>>n;
    //node *a= NULL;
    //node *b = NULL;
    //long n1,n2;
    //cin>>n1;
    //getLinkedList(a,n1);
    //cin>>n2;
    //getLinkedList(b,n2);
    head = buildList(head);
    print(head);
    //long k ;
    //cin>>k;
    //node*q = kFromLast(head,k);
    //node *q = findIntersection(a,b);
    //if(q == NULL) {}
    //else
     //   cout<<q->data;
    //k = k%n;
    //head = appendK(head,k);
    //head = mergeSort(head);
    //print(head);
    return 0;
}

