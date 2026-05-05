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
        if(!head) return head;
        int n=0;
        ListNode* temp=head;
        ListNode* tail;
        while(temp){
            n++;
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
        }
        k%=n;
        if(k==0) return head;
        int count=0;
        ListNode* temp1=head;
        while(temp1){
            count++;
            if(count==n-k){
                temp=temp1;
                break;
            }
            temp1=temp1->next;
        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        tail->next=head;
        return newhead;
    }
};