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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> q;
        for ( int i = 0; i<lists.size(); i++ ){
            if ( lists[i] != NULL ){
                q.push({lists[i]->val,lists[i]});
            }
        }
        
        while ( !q.empty() ){
            
            pair<int,ListNode*> p = q.top();
            q.pop();
            
            temp->next = p.second;
            temp = temp->next;
            
            p.second = p.second->next;
            if ( p.second != NULL ){
                q.push({ p.second->val, p.second });
            }
            
        }
        
        return ans->next;
    }
};