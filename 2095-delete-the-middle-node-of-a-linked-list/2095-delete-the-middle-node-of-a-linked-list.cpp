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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* pre=NULL;
        ListNode* s=head;
        ListNode* f=head;
        while(f && f->next){
            pre=s;
            s=s->next;
            f=f->next->next;
        }
        pre->next=s->next;
        s->next=NULL;
        return head;
    }
        
};