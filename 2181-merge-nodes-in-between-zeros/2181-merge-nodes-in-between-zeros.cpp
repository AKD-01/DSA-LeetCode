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
    ListNode* mergeNodes(ListNode* head) {
         for (auto *p_z = head, *p = head->next; p != nullptr; p = p->next) {
        if (p->val != 0)
            p_z->val += p->val;
        else {
            p_z->next = p->next != nullptr ? p : nullptr;
            p_z = p;
        }
    }
    return head;
    }
};