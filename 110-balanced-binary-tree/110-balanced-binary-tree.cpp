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
    
    int rec( TreeNode* root ){
        
        if ( root == NULL )
            return 0;
        
        int left = 1 + rec( root->left );
        int right = 1 + rec( root->right );
        
        if ( abs(left-right) > 1 ) check = false;
        
        return max ( left, right );
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        rec( root );
        return check;
        
    }
};