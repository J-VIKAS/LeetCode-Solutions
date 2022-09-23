class Solution {
public:
    
    long long MOD = 1000000000 + 7;
         
    int concatenatedBinary(int n) {
               
        long long ans = 0;
        for ( long long i = 1; i<=n; i++ ){
            ans = ((ans<<(int)log2(i)+1)%MOD + i)%MOD;
        }
        return (int)ans%MOD;
        
    }
};