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
        int idx=1;
        int prevIdx=0, firstIdx=0;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int minDist=INT_MAX;
        while(curr!=nullptr && curr->next!=nullptr) {
            if(prev==nullptr) continue;
            if(curr->val > prev->val && curr->val > curr->next->val ||
            curr->val < prev->val && curr->val < curr->next->val) {
                if(prevIdx==0) {
                    prevIdx=idx;
                    firstIdx=idx;
                } else {
                    minDist=min(minDist, idx-prevIdx);
                    prevIdx=idx;
                }
            }
            prev=curr;
            curr=curr->next;
            idx++;
        }
        
        
        if(minDist==INT_MAX) return {-1,-1}; 
        int maxDist=prevIdx-firstIdx;

        return {minDist, maxDist};
    }
};