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
    
    int ans = 0;
    
    int rec( TreeNode* root ){
        
        if ( root == NULL ){
            return 0;
        }
        
        
        int suml = rec( root->left );
        int sumr = rec( root->right );
        
        ans=max({ans,suml+sumr+root->val, sumr+root->val, suml+root->val,root->val});
        
        return max({root->val, suml + root->val,sumr + root->val});
        
        
    }
    
    int maxPathSum(TreeNode* root) {
     
        if ( root ) ans = root->val;
        rec(root);
        return ans;
    }
};