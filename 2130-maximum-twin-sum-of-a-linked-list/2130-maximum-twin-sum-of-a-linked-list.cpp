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
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        vector<int> v;
        temp=head;
        for(int i=0;i<=(n/2)-1;i++){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int maxi=0;
        for(int i=(n/2)-1;i>=0;i--){
            v[i]+=temp->val;
            maxi=max(maxi,v[i]);
            temp=temp->next;
        }
        return maxi;
    }
};