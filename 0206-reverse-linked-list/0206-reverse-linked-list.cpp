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
    ListNode* reverseList(ListNode* head) {
        //Recursive Approach
        /*if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;*/
        //Iterative Approach
        ListNode *prev=NULL, *current=head, *temp;
        while(current != NULL) {
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        return prev;
    }
};