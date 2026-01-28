/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        if(temp==NULL || temp->next==NULL) return false;
        int count=0;
        while(true){
            count++;
            temp=temp->next;
            if(temp==NULL) return false;
            if(count>10000) return true;
        }
        return true;
    }
};