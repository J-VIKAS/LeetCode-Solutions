class Solution {
public:
    
    static bool cmp ( vector<int> &a, vector<int> &b ){
        if ( a[0] < b[0] ) return true;
        else if ( a[0] == b[0] && a[1] > b[1] ) return true;
        return false;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort( properties.begin(), properties.end(), cmp );
        int n = properties.size(), ans = 0;

        int MAX = properties[n-1][1];        
        for ( int i = n-2; i>=0; i-- ){
            
            if ( properties[i][1] < MAX ){
                ans += 1;
            }

            MAX = max( MAX, properties[i][1] );
        }
        
        return ans;        
    }
};