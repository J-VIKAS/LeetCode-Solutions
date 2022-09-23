class Solution {
public:
    
    long long MOD = 1000000000 + 7;
         
    int concatenatedBinary(int n) {
        
        long long ans = 0;
        for ( long long i = 1; i<=n; i++ ){
            ans <<= ((int)log2(i)+1);
            ans %= MOD;
            ans += i;
            ans %= MOD;
        }
        return (int)ans%MOD;
        
    }
};