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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        k%=count;
        if(k==0) return head;
        int n=count-k;
        temp=head;
        while(n>1){
            temp=temp->next;
            n--;
        }
        ListNode* newHead=temp->next;
        temp->next=NULL;
        ListNode* tail=newHead;
        while(tail->next){
            tail=tail->next;
        }
        tail->next=head;
        return newHead;
    }
};