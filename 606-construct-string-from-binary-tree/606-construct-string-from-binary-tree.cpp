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
    
    string s = "";
    void rec( TreeNode* root ){
        
        if ( root == NULL ){
            return;
        }
        if ( root->left == NULL && root->right == NULL ){
            s += to_string(root->val);
            return;
        }
        if ( root->right == NULL ){
            s += to_string(root->val) + "(";
            rec( root->left );
            s += ")";
            return;
        }
        
        s += to_string(root->val) + "(";
        rec( root->left );
        s += ")(";
        rec( root->right );
        s += ")";
        
    }
    
    string tree2str(TreeNode* root) {
        
        rec( root );
        return s;
    }
};