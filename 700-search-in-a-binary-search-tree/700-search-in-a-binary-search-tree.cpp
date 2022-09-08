/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while ( !q.empty() ){
            int k = q.size();
            while ( k-- ){
                TreeNode* p = q.front();
                q.pop();
                if ( p->val == val ) return p;
                else if ( p->val > val && p->left != NULL ) q.push(p->left);
                else if ( p->right != NULL ) q.push(p->right);
            }
        }
        
        return NULL;
    }
};