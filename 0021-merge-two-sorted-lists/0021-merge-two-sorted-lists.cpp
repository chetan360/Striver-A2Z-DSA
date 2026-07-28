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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* list=nullptr;
        ListNode* t=nullptr;
        if(list1->val<=list2->val) {
            list = t = list1; 
            list1 = list1->next;
        } else {
            list = t = list2; 
            list2 = list2->next;
        }
        t->next = nullptr;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val<list2->val) {
                t->next = list1;                
                t = list1;
                list1 = list1->next;
            } else {
                t->next = list2;                
                t = list2;
                list2 = list2->next;
            }
            t->next = nullptr;
        }

        t->next = (list1!=nullptr)?list1:list2;
        
        return list;
    }
};