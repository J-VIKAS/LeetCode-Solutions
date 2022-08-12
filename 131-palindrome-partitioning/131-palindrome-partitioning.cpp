class Solution {
public:
    
    bool check( string s, int l, int r ){
        while ( l <= r ){
            if ( s[l++] != s[r--] ){
                return false;
            }
        }
        return true;
    }
    
    
    void rec( int i, string s, vector<string> a, vector<vector<string>> &ans){
        
        if ( i == s.size() ){
            ans.push_back(a);
            return;
        }
        
        for ( int j = i; j<s.size(); j++ ){
            if ( check(s,i,j) ){
                a.push_back(s.substr(i,j+1-i));
                rec(j+1,s,a,ans);
                a.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> a;
        vector<vector<string>> ans;
        rec(0,s,a,ans);
        return ans;
    }
};