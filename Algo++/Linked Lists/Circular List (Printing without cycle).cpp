/*
We are given a linked list which contains a cycle. Detect that cycle and break it. Print the linked list after removing the cycle.


Input Format:
The first line contains space separated integers.
The integers are such that all the values are distinct but the value start repeating once the cycle gets completed.
The list of integers given ends when -1 is input.

Constraints:
n < 10^5 where n is the length of list without the cycle

Output Format:
Output single line containing space separated integers representing the list

Sample Input:
1 2 3 4 5 2 3 -1
Sample Output:
1 2 3 4 5
Explanation:
Initially the first five elements are unique but starts repeating from 2.
This means there is a link from 5 back to 2. So it represents a cycle.
 We have to break this cycle and print the list after breaking the cycle.
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

int main() {
    node *head = NULL;
    buildList(head);
    printWithoutCycle(head);
    return 0;
}

