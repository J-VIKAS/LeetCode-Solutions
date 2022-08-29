class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int n = s.size();
        int max_len = 1, start = 0;
        
        // ODD
        for ( int i = 0; i<n; i++ ){   
            int len = 1, l = i-1, r = i+1;
            while ( l >= 0 && r < n ){
                if ( s[l] != s[r] ){
                    break;
                }
                l--; r++;
                len += 2;
            }
            if ( len > max_len ){
                max_len = len;
                start = l+1;
            }
        }
        
        // EVEN
        for ( int i = 0; i<n; i++ ){   
            int len = 0, l = i, r = i+1;
            while ( l >= 0 && r < n ){
                if ( s[l] != s[r] ){
                    break;
                }
                l--; r++;
                len += 2;
            }
            
            if ( len > max_len ){
                max_len = len;
                start = l+1;
            }
        }
        
        return s.substr(start,max_len);        
    }
};