#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
class node {
public:
    int data;
    node *next;
    node(int d){
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

void getLinkedList(node *&head,int n){
    int x;
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

void checkPalindrome(node *&p, node * q, bool &flag) {
    if(q->next!=NULL) 
        checkPalindrome(p,q->next,flag);

    if(p->data != q->data) {
        flag = false;
        return;
    }

    p = p->next;
}

bool isPalindrome(node *head) {
    node *p = head;
    node *q = head;

    bool flag = true;

    checkPalindrome(p,q,flag);

    return flag;
}

int main() {
    node * head = NULL;
    int n;
    cin >> n;
    getLinkedList(head,n);

    cout << boolalpha << isPalindrome(head);


    return 0;
}

