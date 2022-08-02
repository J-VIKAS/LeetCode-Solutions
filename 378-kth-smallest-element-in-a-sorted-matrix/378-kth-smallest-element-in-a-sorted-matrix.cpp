class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> a;
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<n; j++ ){
                a.push_back(matrix[i][j]);
            }
        }
        sort(a.begin(),a.end());
        return a[k-1];
    }
};