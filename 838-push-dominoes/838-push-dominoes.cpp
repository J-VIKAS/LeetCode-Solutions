class Solution {
public:
    
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size(), tl = 0, tr = 0;
        bool checkl = false, checkr = false;
        int l[100010],  r[100010];
        
        for ( int i = 0; i<n; i++ ){
            l[i] = INT_MAX;
            r[i] = INT_MAX;
        }
        
        for ( int i = n-1; i>=0; i-- ){
            if ( dominoes[i] == 'R' )   checkl = false;
            else if ( dominoes[i] == 'L' ){
                tl = 0;
                checkl = true;
            }
            if ( checkl ){
                l[i] = tl;
                tl += 1;
            }
        }
        
        for ( int i = 0; i<n; i++ ){
            if ( dominoes[i] == 'L' )   checkr = false;
            else if ( dominoes[i] == 'R' ){
                tr = 0;
                checkr = true;
            }
            if ( checkr ){
                r[i] = tr;
                tr += 1;
            }
        }
        
        string ans = "";
        for ( int i = 0; i<n; i++ ){
            if ( l[i] < r[i] )  ans += 'L';
            else if ( l[i] > r[i] ) ans += 'R';
            else    ans += '.';
        }
        
        return ans;
        
    }
};