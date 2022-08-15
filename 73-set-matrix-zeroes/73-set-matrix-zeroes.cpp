class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool x[200] = {0}, y[200] = {0};
        for ( int i = 0; i<matrix.size(); i++ ){
            for ( int j = 0; j<matrix[i].size(); j++ ){
                if ( matrix[i][j] == 0 ){
                    x[i] = 1; y[j] = 1;
                }
            }
        }
        for ( int i = 0; i<matrix.size(); i++ ){
            for ( int j = 0; j<matrix[i].size(); j++ ){
                if ( x[i] == 1 || y[j] == 1 ){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};