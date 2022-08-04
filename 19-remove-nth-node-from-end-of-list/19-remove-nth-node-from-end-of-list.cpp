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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* ans = head;
        int m = 0;
        ListNode* list = head;
        while ( list != NULL ){
            m += 1;
            list = list->next;
        }
        
        if ( n == m ){
            return head->next;
        }
        
        int k = 0;
        while ( k < m-n-1 ){
            k += 1;
            head = head->next;
        }
        
        if ( n == 1 ){
            head->next = NULL;
        } else {
            head->next = head->next->next;
        }
        
        return ans;
    }
};