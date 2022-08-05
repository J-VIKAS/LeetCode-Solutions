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
    bool hasCycle(ListNode *head) {
        
        map<ListNode*,bool> vis;
        while ( head != NULL ){
            if ( !vis[head] ){
                vis[head] = true;
                head = head->next;
            } else {
                return true;
            }
        }
        return false;
        
    }
};