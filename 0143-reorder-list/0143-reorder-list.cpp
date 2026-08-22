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
    // ListNode* solve(ListNode* head){
    //     if(!head || !head->next) return head;
    //     ListNode* newhead=solve(head->next);
    //     ListNode* front=head->next;
    //     front->next=head;
    //     head->next=NULL;
    //     return newhead;
    // }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr){
            st.push(curr);
            curr=curr->next;
        }
        int k=st.size()/2;
        curr=head;
        while(k--){
            ListNode* nextNode=curr->next;
            curr->next=st.top();
            st.top()->next=nextNode;
            st.pop();
            curr=nextNode;
        }
        curr->next=NULL;
    }
};