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
    
    TreeNode* rec( TreeNode* root, int si, int se, vector<int> &inorder, int pi, int pe, vector<int> &postorder ){
        if ( se-si < 0 || pe-pi < 0 )   return NULL;
        root = new TreeNode(postorder[pe]);
        int k = ind[postorder[pe]] - si;
        
//         cout << "k : " << k << "\n";
        
//         cout << "left : \n";
//         cout << "inorder : (" << si << "," << ind[postorder[pe]]-1 << ")\n";
//         cout << "postorder : (" << pi << "," << pi+k-1 << ")\n";
        
        root->left = rec(root->left,si,ind[postorder[pe]]-1,inorder,pi,pi+k-1,postorder);
        
        // cout << "right : \n";
        // cout << "inorder : (" << ind[postorder[pe]]+1 << "," << se << ")\n";
        // cout << "postorder : (" << pi+k << "," << pe-1 << ")\n";
        
        root->right = rec(root->right,ind[postorder[pe]]+1,se,inorder,pi+k,pe-1,postorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for ( int i = 0; i<n; i++ ) ind[inorder[i]] = i;
        TreeNode* root = rec( root, 0, n-1, inorder, 0, n-1, postorder );
        return root;
    }
};