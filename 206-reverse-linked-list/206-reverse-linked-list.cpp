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
    ListNode* reverseList(ListNode* head) {
        
        vector<int> a;
        while ( head != NULL ){
            a.push_back(head->val);
            head = head->next;
        }
        
        ListNode* ans = new ListNode();
        head = ans;
        for ( int i = a.size()-1; i>=0; i-- ){
            ans->next = new ListNode(a[i]);
            ans = ans->next;
        }
        
        return head->next;
    }
};