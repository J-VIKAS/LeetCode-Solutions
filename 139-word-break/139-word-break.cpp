class Solution {
public:
    
    int dp[301][301];
    
    bool rec(int i, string s, map<string,bool> &p, string curr, int l){
        curr += s[i];
        if ( i == s.size()-1 ) return p[curr];
        if ( dp[i][l] != -1 ) return dp[i][l];
        if ( p[curr] )  return dp[i][l] = rec(i+1,s,p,curr,l) || rec(i+1,s,p,"",i+1);
        return dp[i][l] = rec(i+1,s,p,curr,l);
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for ( int i = 0; i<301; i++ ){
            for ( int j = 0; j<301; j++ )   dp[i][j] = -1;
        }
        
        map<string,bool> p;
        for ( int i = 0; i<wordDict.size(); i++ )   p[wordDict[i]] = true;
        return rec(0,s,p,"",0);
       
    }
};