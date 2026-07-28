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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* p;
        ListNode* q;
        p=head;
        q = p->next;
        while(q!=nullptr) {
            if(p->val == q->val) {
                p->next = q->next;
                delete q;
                q = p->next;    
            } else {
                p = q;
                q = p->next;
            }
            
        }

        return head; 
    }
};