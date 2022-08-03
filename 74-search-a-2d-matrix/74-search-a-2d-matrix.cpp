class Solution {
public:
    
    bool binary_search(vector<int> &v, int n, int target){
        int i = 0, j = n-1;
        while ( i <= j ){
            int mid = (i+j)/2;
            if ( v[mid] == target )
                return true;
            else if ( v[mid] > target )
                j = mid - 1;
            else
                i = mid + 1; 
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> v;
        for ( int i = 0; i<matrix.size(); i++ ){
            for ( int j = 0; j<matrix[0].size(); j++ ){
                v.push_back(matrix[i][j]);
            }
        }
        
        return binary_search(v,v.size(),target);
        
    }
};