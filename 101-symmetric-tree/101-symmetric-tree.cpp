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
    
    void bfs1( TreeNode* root, vector<int> &a ){
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ){
            int k = q.size();
            bool check = false;
            while ( k-- ){
                TreeNode* p = q.front();
                q.pop();
                if (p) a.push_back(p->val);
                else a.push_back(-101);
                if ( p != NULL && ( p->left || p->right ) ) check = true;
                if (p != NULL && p->left) q.push(p->left);
                else q.push(NULL);
                if (p != NULL && p->right) q.push(p->right);
                else q.push(NULL);
            }
            if ( !check ) break;
        }
    }
    
    void bfs2( TreeNode* root, vector<int> &a ){
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ){
            int k = q.size();
            bool check = false;
            while ( k-- ){
                TreeNode* p = q.front();
                q.pop();
                if (p) a.push_back(p->val);
                else a.push_back(-101);
                if ( p != NULL && ( p->left || p->right ) ) check = true;
                if (p != NULL && p->right) q.push(p->right);
                else q.push(NULL);
                if (p != NULL && p->left) q.push(p->left);
                else q.push(NULL);
            }
            if ( !check ) break;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> l, r;
        bfs1(root->left,l);
        bfs2(root->right,r);
        // cout << "l : ";
        // for ( int i = 0; i<l.size(); i++ ){
        //     cout << l[i] << " ";
        // } cout << "\n";
        // cout << "r : ";
        // for ( int i = 0; i<r.size(); i++ ){
        //     cout << r[i] << " ";
        // } cout << "\n";
        return l == r; 
    }
};