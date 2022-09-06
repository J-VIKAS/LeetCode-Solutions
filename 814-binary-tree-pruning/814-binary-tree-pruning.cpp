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
    
    int rec( TreeNode* root ){
        
        if ( root == NULL )
            return 0;
        
        int left = rec( root->left );
        int right = rec( root->right );
        
        if ( left == 0 ){
            root->left = NULL;
        }
        if ( right == 0 ){
            root->right = NULL;
        }
        
        return left + right + root->val;
    }
        
    TreeNode* pruneTree(TreeNode* root) {
        
        int value = rec( root );
        if ( value == 0 ) return NULL;
        return root;
        
    }
};