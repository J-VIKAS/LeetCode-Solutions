/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *sA = headA, *sB = headB;
        bool checkA = true, checkB = true;
        while ( headA != NULL && headB != NULL ){
            if ( headA == headB )
                return headA;
            headA = headA->next;
            headB = headB->next;
            if ( headA == NULL && checkA ){
                headA = sB;
                checkA = false;
            }
            if ( headB == NULL && checkB ){
                headB = sA;
                checkB = false;
            }
        }
        
        return headA;
    }
};