class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pascals;
        pascals.push_back({1});
        if ( numRows == 1 ) return pascals;
        pascals.push_back({1,1});
        for ( int i = 2; i<numRows; i++ ){
            vector<int> p = {1};
            for ( int j = 1; j<i; j++ ){
                p.push_back(pascals[i-1][j-1]+pascals[i-1][j]);
            }
            p.push_back(1);
            pascals.push_back(p);
        }
        return pascals;        
    }
};