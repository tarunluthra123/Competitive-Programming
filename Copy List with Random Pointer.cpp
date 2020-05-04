/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        Node *temp = head;
        while(temp != NULL) {
            Node *n = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = n;
            temp = n;
        }
        
        temp = head;
        
        while(temp!=NULL && temp->next!= NULL) {
            if(temp->random == NULL) {
                temp->next->random = NULL;
            }
            else { 
                temp->next->random = temp->random->next;
            }
            
            temp = temp->next->next;
        }
        
        Node *newList = head->next;
        
        temp = head;
        Node *temp2 = newList;
        
        while(temp!=NULL) {
            temp->next = temp2->next;
            if(temp->next == NULL) {
                temp2->next = NULL;
            }
            else {
                temp2->next = temp->next->next;
            }
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return newList;
    }
};
