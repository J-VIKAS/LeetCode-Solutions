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
    ListNode* middleNode(ListNode* head) {
        
        int n = 0;
        ListNode* list = head;
        while ( list != NULL ){
            n += 1;
            list = list->next;
        }
        
        int k = 0;
        while ( k != n/2 ){
            k += 1;
            head = head->next;
        }
        return head;
        
                
    }
};