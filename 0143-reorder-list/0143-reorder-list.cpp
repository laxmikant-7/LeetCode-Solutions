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
    ListNode* solve(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newhead=solve(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* rev=solve(second);
        ListNode* first = head;
        while(rev){
            ListNode* nextFirst = first->next;
            ListNode* nextRev = rev->next;
            first->next = rev;
            rev->next = nextFirst;
            first = nextFirst;
            rev = nextRev;
        }
        return;
    }
};