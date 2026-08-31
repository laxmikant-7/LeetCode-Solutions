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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int pos = 1;
        int firstCritical = -1;
        int prevCritical = -1;
        
        int minDistance = INT_MAX;
        int maxDistance = -1;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            int prevVal = prev->val;
            int currVal = curr->val;
            int nextVal = curr->next->val;

            if ((currVal > prevVal && currVal > nextVal) ||
                (currVal < prevVal && currVal < nextVal)) {
                
                if (firstCritical == -1) {
                    firstCritical = pos;
                } 
                else {
                    minDistance = min(minDistance, pos - prevCritical);
                    maxDistance = pos - firstCritical;
                }
                
                prevCritical = pos;
            }
            
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if (maxDistance == -1) {
            return {-1, -1};
        }
        
        return {minDistance, maxDistance};
    }
};