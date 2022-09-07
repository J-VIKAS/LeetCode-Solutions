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
    
    int widthOfBinaryTree(TreeNode* root) {
        
        if ( root == NULL ) return 0;
        
        long ans = 1;        
        queue<pair<TreeNode*,long>> q;
        if ( root->left != NULL )    q.push({root->left,1}); 
        if ( root->right != NULL )   q.push({root->right,2});

        while ( !q.empty() ){
            int k = q.size();
            long l = INT_MAX, r = INT_MIN;
            long sub = q.front().second;
            while ( k-- ){
                pair<TreeNode*,long> p = q.front();
                q.pop();
                l = min(l,p.second);
                r = max(r,p.second);
                if ( p.first->left != NULL )    q.push({p.first->left,(p.second-sub)*2}); 
                if ( p.first->right != NULL )   q.push({p.first->right,(p.second-sub)*2+1});
            }
            ans = max(ans,r-l+1);
        }
        
        return (int)ans;
    }
};