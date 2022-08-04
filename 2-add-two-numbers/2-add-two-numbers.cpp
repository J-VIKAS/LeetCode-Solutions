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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        
        int carry = 0;
        while ( l1 != NULL && l2 != NULL ){
            if ( l1->val + l2->val + carry <= 9 ){
                ans->next = new ListNode(l1->val + l2->val + carry);
                ans = ans->next;
                carry = 0;
            } else {
                ans->next = new ListNode((l1->val + l2->val + carry)%10);
                ans = ans->next;
                carry = (l1->val + l2->val + carry)/10;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while ( l1 != NULL ){
            if ( l1->val + carry <= 9 ){
                ans->next = new ListNode(l1->val + carry);
                ans = ans->next;
                carry = 0;
            } else {
                ans->next = new ListNode((l1->val + carry)%10);
                ans = ans->next;
                carry = (l1->val + carry)/10;
            }
            l1 = l1->next;
        }
        
        while ( l2 != NULL ){
            if ( l2->val + carry <= 9 ){
                ans->next = new ListNode(l2->val + carry);
                ans = ans->next;
                carry = 0;
            } else {
                ans->next = new ListNode((l2->val + carry)%10);
                ans = ans->next;
                carry = (l2->val + carry)/10;
            }
            l2 = l2->next;
        }
        
        if ( carry > 0 ){
            ans->next = new ListNode(carry);
        }
        
        return head->next;        
        
    }
};