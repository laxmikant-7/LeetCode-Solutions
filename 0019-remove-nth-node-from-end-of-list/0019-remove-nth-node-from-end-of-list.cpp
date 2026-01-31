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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        while(n--){
            fast=fast->next;
        }
        if(fast==NULL){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        ListNode* slow=head;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* deleteNode=slow->next;
        slow->next=slow->next->next;
        delete deleteNode;
        return head;
    }
};