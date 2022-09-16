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
    
    void rec( TreeNode* l, TreeNode* r ){
        if ( l == NULL && r == NULL ) return;
        else if ( l != NULL && r != NULL ){
            if ( l->val != r->val ){
                check = false;
                return;
            }
            rec( l->right, r->left );
            rec( l->left, r->right );
        } else {
            check = false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        rec(root->left,root->right);
        return check;
    }
};