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
    map<int,int> freq;
    
    bool check ( int depth ){
        
        int count = 0;
        for ( int i = 1; i<10; i++ ){
            count += ( freq[i]%2 != 0 );
        }
        
        if ( count == 1 && depth%2 != 0 ) return true;
        if ( count == 0 && depth%2 == 0 ) return true;
        return false;
        
    }
    
    void rec( TreeNode* root, int depth ){
        
        if ( root == NULL ) return;
        freq[root->val]++;
        
        rec( root->left, depth + 1 );
        rec( root->right, depth + 1 );
        
        if ( root->left == NULL && root->right == NULL && check(depth) ){
            ans += 1;
        }
        
        freq[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        rec( root , 1);
        return ans;
    }
};