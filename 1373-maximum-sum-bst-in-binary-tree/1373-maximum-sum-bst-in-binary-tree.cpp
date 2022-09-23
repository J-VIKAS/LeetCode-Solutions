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
    
    // {isbst, Max, Min, sum}
    
    vector<int> rec( TreeNode* root ){
        
        vector<int> le = {1,INT_MIN,INT_MAX,0}, re = {1,INT_MIN,INT_MAX,0};
        if ( root->left )   le = rec( root->left );
        if ( root->right )  re = rec( root->right );
        
        int sum = root->val + le[3] + re[3];
        int isbst = 0;
        
        // cout << "for root->val : " << root->val << "\n";
        // cout << "l, r : " << le[1] << " " << re[2] << "\n";
        // cout << "bstl, bstr : " << le[0] << " " << re[0] << "\n";
        // cout << "sum = " << sum << "\n";
        
        if ( le[1] < root->val && re[2] > root->val && le[0] && re[0] ){
            ans = max(ans,sum);
            isbst = 1;
        }
        
        int Max = max({root->val,le[1],re[1]});
        if ( re[2] != INT_MAX ) Max = max(Max,re[2]);
        int Min = min({root->val,re[2],le[2]});
        if ( le[1] != INT_MIN ) Min = min(Min,le[1]);
        
        // cout << "returning : {"<<isbst<<","<<Max<<","<<Min<<","<<sum<<"}\n\n";

        return {isbst, Max, Min, sum};
        
    }
    
    int maxSumBST(TreeNode* root) {
        
        if ( root != NULL ) rec( root );
        return ans;
    
    }
};