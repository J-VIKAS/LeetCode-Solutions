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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        vector<int> a;
        while ( head != NULL ){
            a.push_back(head->val);
            head = head->next;
        }
        
        for ( int i = k-1; i<a.size(); i+=k ){
            int l = i-k+1, r = i;
            while ( l <= r ){
                swap(a[l],a[r]);
                l += 1;
                r -= 1;
            }
        }
        
        ListNode* temp = new ListNode(a[0]);
        ListNode* ans = temp;
        for ( int i = 1; i<a.size(); i++ ){
            temp->next = new ListNode(a[i]);
            temp = temp->next;
        }
        
        return ans;       
        
    }
};