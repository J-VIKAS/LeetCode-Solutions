class Solution {
public:
    
    void user_sort( int i, int j, vector<vector<int>> &mat, int n, int m ){
        
        while ( i < n && j < m ){
            int a = i, b = j;
            while ( a < n && b < m ){
                if ( mat[i][j] > mat[a][b] ){
                    swap(mat[i][j],mat[a][b]);
                }
                a++;
                b++;
            }
            i++;
            j++;
        }
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        for ( int i = n-1; i>=0; i-- ){
            user_sort(i,0,mat,n,m);
        }
        for ( int j = 0; j<m; j++ ){
            user_sort(0,j,mat,n,m);
        }
        
        return mat;        
    }
};