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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder, postorder, preorder;
        stack<pair<TreeNode*,int>> st;
        
        if ( root == NULL ) return inorder;
        
        st.push({root,1});
        
        while ( !st.empty() ){
            pair<TreeNode*,int> p = st.top();
            st.pop();
            if ( p.second == 1 ){
                preorder.push_back(p.first->val);
                st.push({p.first,p.second+1});
                if ( p.first->left ) st.push({p.first->left,1});
            } else if ( p.second == 2 ){
                inorder.push_back(p.first->val);
                st.push({p.first,p.second+1});
                if ( p.first->right ) st.push({p.first->right,1});
            } else if ( p.second == 3 ){
                postorder.push_back(p.first->val);                
            }
        }
        
        return inorder;      
    }
};