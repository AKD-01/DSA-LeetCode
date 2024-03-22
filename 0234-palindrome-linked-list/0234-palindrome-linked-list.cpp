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
    ListNode* reverseList(ListNode* head){
        if(head==NULL) return NULL;
        ListNode*p=NULL, *c=head, *n=head->next;
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;
        }
        return p;
    } 
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        ListNode *start=head, *mid=slow->next;
        while(mid!=NULL){
            if(mid->val!=start->val) return false;
            start=start->next;
            mid=mid->next;
        }
        slow->next=reverseList(slow->next);
        return true;
    }
};
