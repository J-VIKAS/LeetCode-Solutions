class Solution {
public:
    
    string convert( string s ){
        string ans = "";
        int count = 1;
        for ( int i = 1; i<s.size(); i++ ){
            if ( s[i] != s[i-1] ){
                ans += to_string(count) + s[i-1];
                count = 0;
            }
            count += 1;
        }
        ans += to_string(count) + s[s.size()-1];
        return ans;
    }
    
    string countAndSay(int n) {
        
        if ( n == 1 ) return "1";
        
        string ans = "1";
        for ( int i = 1; i<n; i++ ){
            ans = convert(ans);
        }
        
        return ans;        
    }
};