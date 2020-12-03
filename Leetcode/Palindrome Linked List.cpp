/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = prev->next;
        prev->next = NULL;
        l2 = reverse(l2);

        while(head and l2){
            if(head->val != l2->val)
                return false;

            head = head->next;
            l2 = l2->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head){
        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n;
        while(c!=NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
};
