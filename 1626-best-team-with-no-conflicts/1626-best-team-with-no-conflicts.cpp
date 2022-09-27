class Solution {
public:
    
    int dp[1001][1002];
    int n;
    
    int rec( int i, vector<pair<int,int>> &vec, int j ){
        if ( i == n )   return 0;
        if ( dp[i][j] != -1 )  return dp[i][j];
        if ( j == 0 || vec[i].second >= vec[j-1].second )  return dp[i][j] = max( vec[i].second + rec(i+1,vec,i+1), rec(i+1,vec,j) );
        return dp[i][j] = rec(i+1, vec, j);
    }
    
    static bool cmp( pair<int,int> &a, pair<int,int> &b ){
        if ( a.first < b.first ) return true;
        else if ( a.first == b.first && a.second < b.second )   return true;
        return false;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        for ( int i = 0; i<1001; i++ ){
            for ( int j = 0; j<1001; j++ )  dp[i][j] = -1;
        }
        
        n = scores.size();
        vector<pair<int,int>> vec;
        for ( int i = 0; i<n; i++ ) vec.push_back({ages[i],scores[i]});
        sort(vec.begin(),vec.end(),cmp);
        
        return rec(0,vec,0);
        
    }
};