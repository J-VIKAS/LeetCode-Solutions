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
    
    vector<int> p;
    int sum = 0;
    vector<vector<int>> ans;
    
    void rec( TreeNode* root, int targetSum, int Sum ){
        if ( root == NULL ){
            return;
        }
        p.push_back(root->val);
        
        if ( Sum + root->val == targetSum && root->left == NULL && root->right == NULL ){
            ans.push_back(p);
        }
        
        rec( root->left, targetSum, Sum + root->val );
        rec( root->right, targetSum, Sum + root->val );
        p.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        rec( root, targetSum, 0 );
        return ans;
    }
};