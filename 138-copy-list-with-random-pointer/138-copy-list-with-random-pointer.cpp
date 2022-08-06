/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*> pointing;

        Node* temp = new Node(NULL);
        Node* t_temp = temp;
        Node* t_head = head;
        
        Node* ans = temp;
        int i = 0;
        
        while ( head != NULL ){
            temp->next = new Node(head->val);
            pointing[head] = temp->next;
            // temp->next->random = pointing[head->random];
            head = head->next;
            temp = temp->next;
            i += 1;
        }
        
        while ( t_head != NULL ){
            t_temp->next->random = pointing[t_head->random];
            t_temp = t_temp->next;
            t_head = t_head->next;
        }
        
        return ans->next;        
        
    }
};