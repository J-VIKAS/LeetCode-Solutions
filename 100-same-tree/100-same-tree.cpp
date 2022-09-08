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
    
    bool check = true;
    
    void rec( TreeNode* p, TreeNode* q ){
    
        if ( p != NULL && q == NULL ){
            check = false;
            return;
        }
        
        if ( p == NULL && q != NULL ){
            check = false;
            return;
        }
        
        if ( p == NULL && q == NULL ){
            return;
        }
        
        if ( p->val != q->val ){
            check = false;
        }
        
        rec( p->left, q->left );
        rec( p->right, q->right );

    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        rec( p, q );
        return check;
        
    }
};