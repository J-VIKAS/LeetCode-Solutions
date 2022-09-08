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
    
    TreeNode* temp;
    
    void rec( TreeNode* root, int val ){
        
        if ( root == NULL ) return;
        
        if ( root->val > val ){
            rec( root->left, val );
        } else if ( root->val < val ){
            rec( root->right, val );
        } else {
            temp = root;
            return;
        }
        
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        rec( root, val );
        return temp;
        
    }
};