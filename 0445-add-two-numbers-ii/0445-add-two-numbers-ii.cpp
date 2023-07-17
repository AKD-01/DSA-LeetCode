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
    ListNode* rev(ListNode* h){
        ListNode* curr=h;
        ListNode* prev=NULL;
        while(curr){
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev_list1=rev(l1);
        ListNode* rev_list2=rev(l2);

        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int sum=0,rem=0;

        while(1){
            sum=0;
            sum+=rem;
            if(rev_list1) {sum+=rev_list1->val; rev_list1=rev_list1->next;}
            if(rev_list2) {sum+=rev_list2->val; rev_list2=rev_list2->next;}
            rem=sum/10;
            sum=sum%10;
            temp->next=new ListNode(sum);
            temp=temp->next;
            
            if(!rev_list1&&!rev_list2&&(rem==0)) break;
        }
        return rev(dummy->next);
    }
};