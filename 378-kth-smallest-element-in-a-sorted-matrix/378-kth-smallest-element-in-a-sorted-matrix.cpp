class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> a(n,0);
        for ( int i = 0; i<n; i++ ){
            matrix[i].push_back(INT_MAX);
        }
        
        int ans;
        for ( int i = 0; i<k; i++ ){
            int ind = 0, val = matrix[0][a[0]];
            for ( int j = 1; j<n; j++ ){
                if ( val > matrix[j][a[j]] ){
                    ind = j;
                    val = matrix[j][a[j]];
                }
            }
            ans = matrix[ind][a[ind]];
            a[ind]++;
        }
        return ans;
    }
};