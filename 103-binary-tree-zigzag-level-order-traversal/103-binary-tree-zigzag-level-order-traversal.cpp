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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if ( root == NULL ) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool check = true;
        
        while ( !q.empty() ){
            int k = q.size();
            vector<int> temp;
            while ( k-- ){
                TreeNode* p = q.front();
                q.pop();
                temp.push_back(p->val);
                if ( p->right != NULL )     q.push(p->right);
                if ( p->left != NULL )      q.push(p->left);
            }
            check = !check;
            if ( !check ) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        
        return ans;        
    }
};