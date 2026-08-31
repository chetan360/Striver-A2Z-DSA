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
        vector<int>idxArr;
        int idx=1;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=nullptr && curr->next!=nullptr) {
            if(prev==nullptr) continue;
            if(curr->val > prev->val && curr->val > curr->next->val ||
            curr->val < prev->val && curr->val < curr->next->val) {
                idxArr.push_back(idx);
            }
            prev=curr;
            curr=curr->next;
            idx++;
        }
        
        int n=idxArr.size();
        if(n<2) {
            return {-1, -1};
        }

        int maxima=idxArr.back()-idxArr.front();
        int minima=INT_MAX;
        for(int i=1; i<n; i++) {
            minima=min(minima, idxArr[i]-idxArr[i-1]);
        }

        return {minima, maxima};
    }
};