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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if ( head == NULL )
            return head;
        
        int n = 0;
        vector<int> a;
        while ( head != NULL ){
            a.push_back(head->val);
            n += 1;
            head = head->next;
        }
        
        k = k%n;
        
        for ( int i = 0; i<n; i++ ){
            a.push_back(a[i]);
        }
        
        ListNode* temp = new ListNode();
        ListNode* ans = temp;
        for ( int i = n-k; i<2*n-k; i++ ){
            temp->next = new ListNode(a[i]);
            temp = temp->next;
        }
        
        return ans->next;
    }
};