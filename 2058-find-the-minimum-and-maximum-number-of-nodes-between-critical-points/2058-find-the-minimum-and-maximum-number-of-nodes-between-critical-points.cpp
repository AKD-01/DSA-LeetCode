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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      vector<int>critical;
        ListNode* cur=head;
        ListNode* next=head->next;
        ListNode* prev=NULL;
        int index=0;
        while(next!=NULL){

            if((prev!=NULL && cur->val<prev->val && cur->val<next->val)||
            (prev!=NULL && cur->val>prev->val && cur->val>next->val)){
                critical.push_back(index);
            }
            prev=cur;
            cur=next;
            next=next->next;
            index++;
        }

        if(critical.size()<2) return {-1,-1};
        int maxDist=critical.back()-critical.front();
        int minDist=INT_MAX;

        for(int i=0;i<critical.size()-1;i++){
            minDist=min(minDist,critical[i+1]-critical[i]);
        }
        return {minDist,maxDist};  
    }
};