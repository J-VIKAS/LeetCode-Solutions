/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        queue<Node*> q;
        if ( root != NULL )
            q.push(root);
        
        while ( !q.empty() ){
            int k = q.size();
            vector<int> temp;
            while ( k-- ){
                Node* p = q.front();
                q.pop();
                temp.push_back(p->val);
                for ( auto i : p->children ){
                    if ( i != NULL )
                        q.push(i);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;        
    }
};