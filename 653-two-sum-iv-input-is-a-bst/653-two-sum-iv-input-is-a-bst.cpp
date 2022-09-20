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
    
    vector<int> r;
    
    void rec( TreeNode* root ){
        if ( root == NULL ) return;
        rec( root->left );
        r.push_back( root->val );
        rec( root->right );
    }
    
    bool findTarget(TreeNode* root, int k) {
        rec( root );
        cout << "r : ";
        for ( int i = 0; i<r.size(); i++ ) cout << r[i] << " ";
        cout << "\n";
        int l = 0, h = r.size()-1;
        while( l < h ){
            if ( r[l] + r[h] == k ) return true;
            else if ( r[l] + r[h] > k )   h--;   
            else l++;
        }
        return false;
    }
};