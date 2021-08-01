//https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root;
        
        ListNode *ans = &root;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val) {
                ans->next = l1;
                l1 = l1->next;
            }
            else{
                ans->next = l2;
                l2 = l2->next;
            }
            cout << ans->val << " ";
            ans = ans->next;
        }
        
        while(l1 != nullptr){
            ans->next = l1;
            l1 = l1->next;
            ans = ans->next;
        }
        while(l2 != nullptr){
            ans->next = l2;
            l2 = l2->next;
            ans = ans->next;
        }
        
        return root.next;
    }
};
