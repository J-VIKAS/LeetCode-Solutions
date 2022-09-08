/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if ( root == NULL ) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while ( !q.empty() ){
            int k = q.size();
            Node* last = NULL;
            while ( k-- ){
                Node* p = q.front();
                q.pop();
                p->next = last;
                last = p;
                if ( p->right != NULL ) q.push( p->right );
                if ( p->left != NULL ) q.push( p->left );
            }
        }
        
        return root;
    }
};