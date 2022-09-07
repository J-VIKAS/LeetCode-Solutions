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
    
    vector<string> path;
    
    void rec( TreeNode* root, string s ){
        
        if ( root == NULL ){
            return;
        }
        
        s += to_string(root->val) + "->";
        rec( root->left, s );
        rec( root->right, s );
        
        if ( root->left == NULL && root->right == NULL ){
            path.push_back(s.substr(0,s.size()-2));
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s = "";
        rec( root, s );
        return path;
        
    }
};