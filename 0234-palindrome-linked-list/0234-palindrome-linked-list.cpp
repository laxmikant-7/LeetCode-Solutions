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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        if(n==1) return true;
        n=(n/2)+1;
        temp=head;
        while(true){
            temp=temp->next;
            n--;
            if(n==1) break;
        }
        ListNode* last=reverse(temp);
        ListNode* first=head;
        while(last){
            if(last->val!=first->val) return false;
            first=first->next;
            last=last->next;
        }
        return true;
    }
};