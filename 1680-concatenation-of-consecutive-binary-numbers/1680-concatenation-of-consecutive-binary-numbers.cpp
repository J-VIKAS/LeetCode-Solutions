class Solution {
public:
    
    long long MOD = 1000000000 + 7;
    
    long long to_binary( int n ){
        long len = 0;
        while ( n > 0 ){
            len++;
            n /= 2;
        } return len;
    }
         
    int concatenatedBinary(int n) {
        
        long long ans = 0;
        for ( long long i = 1; i<=n; i++ ){
            ans <<= to_binary(i);
            ans %= MOD;
            ans += i;
            ans %= MOD;
        }
        return (int)ans%MOD;
        
    }
};