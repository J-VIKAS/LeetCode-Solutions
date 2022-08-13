class Solution {
public:
    
    int fac( int n ){
        if ( n <= 0 || n == 1 ) return 1;
        return n*fac(n-1);
    }
    
    string getPermutation(int n, int k) {
        
        unordered_map<int,bool> taken;
        string ans = "";
        int total = 0, possible = fac(n-1), count = 1;
        
        while ( total < k ){
            
            bool check = false;
            for ( int i = 1; i<=n; i++ ){
                if ( total + possible < k && !taken[i] ){
                    total += possible;     
                } else if ( !taken[i] ) {
                    char ch = i+48;
                    ans += ch;
                    taken[i] = true;
                    count += 1;
                    possible = fac(n-count);
                    check = true;
                    break;
                }
            }
            
            if ( !check ){
                break;
            }
            
        }
        
        for ( int i = 1; i<=n; i++ ){
            if ( !taken[i] ){
                char ch = i+48;
                ans += ch;
            }
        }
        
        return ans;
    }
};