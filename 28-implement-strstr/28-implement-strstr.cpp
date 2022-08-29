class Solution {
public:
    
    vector<int> computeLPS(string &p, int m){
        int len = 0, i = 1;
        vector<int> lps(m,0);
        while ( i < m ){
            if ( p[i] == p[len] ){
                lps[i] = len + 1;
                len++; i++;
            } else {
                if ( len != 0 ){
                    len = lps[len-1];
                } else {
                    i++;
                }
            }
        }
        return lps;
    }

    int KMPSearch(string &s, string &p){
        int n = s.size(), m = p.size(), i = 0, j = 0;
        vector<int> lps = computeLPS(p,m);
        while ( i < n ){
            if ( s[i] == p[j] ){
                i++; j++;
            } else {
                if ( j != 0 ){
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
            if ( j == m ){
                return i-j;
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return KMPSearch(haystack,needle);
    }
};