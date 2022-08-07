class Solution {
public:
    
    long long int rec( int i, char ch, int n, vector<vector<long long>> &dp){
        if ( i == n ){
            return 1;
        }
        
        if ( dp[i][ch-'a'] != -1 ){
            return dp[i][ch-'a'];
        }
        
        if ( ch == 'a' ){
            dp[i][ch-'a'] = rec(i+1,'e',n,dp);
            dp[i][ch-'a'] = dp[i][ch-'a']%(1000000007);
            return dp[i][ch-'a'];
        } else if ( ch == 'e' ){
            dp[i][ch-'a'] = rec(i+1,'a',n,dp) + rec(i+1,'i',n,dp);
            dp[i][ch-'a'] = dp[i][ch-'a']%(1000000007);
            return dp[i][ch-'a'];
        } else if ( ch == 'i' ){
            dp[i][ch-'a'] = rec(i+1,'a',n,dp) + rec(i+1,'e',n,dp) + rec(i+1,'o',n,dp) + rec(i+1,'u',n,dp);
            dp[i][ch-'a'] = dp[i][ch-'a']%(1000000007);
            return dp[i][ch-'a'];
        } else if ( ch == 'o' ){
            dp[i][ch-'a'] = rec(i+1,'i',n,dp) + rec(i+1,'u',n,dp);
            dp[i][ch-'a'] = dp[i][ch-'a']%(1000000007);
            return dp[i][ch-'a'];
        } else {
            dp[i][ch-'a'] = rec(i+1,'a',n,dp);
            dp[i][ch-'a'] = dp[i][ch-'a']%(1000000007);
            return dp[i][ch-'a'];        
        }
        
    }
    
    int countVowelPermutation(int n) {
        
        vector<vector<long long>> dp(n,vector<long long>(26,-1));
        vector<char> vowels = {'a','e','i','o','u'};
        int total = 0;
        for ( int i = 0; i<vowels.size(); i++ ){
            total += dp[0][vowels[i]-'a'] = rec(1,vowels[i],n,dp);
            total = total%(1000000007);
        }
        
        return total;
    }
};