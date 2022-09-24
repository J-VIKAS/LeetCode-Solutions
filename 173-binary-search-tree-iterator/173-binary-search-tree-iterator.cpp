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
class BSTIterator {
public:
    
    vector<TreeNode*> path;
    int i = 0;
    
    void rec( TreeNode* root ){
        if ( root == NULL ) return;
        rec( root->left );
        path.push_back(root);
        rec( root->right );
    }
    
    BSTIterator(TreeNode* root) {
        rec( root );
    }
    
    int next() {
        return path[i++]->val;
    }
    
    bool hasNext() {
        if ( i >= path.size() ) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */