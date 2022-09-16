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
    
    map<int,int> ind;
    
    TreeNode* rec( TreeNode* root, int si, int se, vector<int> &inorder, int pi, int pe, vector<int> &preorder ){
        if ( se-si < 0 || pe-pi < 0 )   return NULL;
        root = new TreeNode(preorder[pi]);
        int k = ind[preorder[pi]] - si;        
        root->left = rec(root->left,si,ind[preorder[pi]]-1,inorder,pi+1,pi+k+1,preorder);        
        root->right = rec(root->right,ind[preorder[pi]]+1,se,inorder,pi+k+1,pe,preorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for ( int i = 0; i<n; i++ ) ind[inorder[i]] = i;
        TreeNode* root = rec( root, 0, n-1, inorder, 0, n-1, preorder );
        return root;
    }
};