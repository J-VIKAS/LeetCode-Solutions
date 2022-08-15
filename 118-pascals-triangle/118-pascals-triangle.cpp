class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pascals;
        pascals.push_back({1});
        if ( numRows == 1 ) return pascals;
        pascals.push_back({1,1});
        for ( int i = 2; i<numRows; i++ ){
            vector<int> p(i+1,1);
            for ( int j = 1; j<i; j++ )
                p[j] = pascals[i-1][j-1]+pascals[i-1][j];
            pascals.push_back(p);
        }
        return pascals;        
    }
};