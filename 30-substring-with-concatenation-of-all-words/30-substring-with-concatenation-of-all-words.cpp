class Solution {
public:
    
    bool check( string s, int l, int r, int len, unordered_map<string,int> freq  ){
        
        string temp = "";
        int i = l;
        while ( l <= r ){
            temp += s[l];
            l++;
            if ( (l-i)%len == 0 ){
                if ( !( freq[ temp ] > 0) ){
                    return false;
                }
                freq[ temp ]--;
                temp = "";
            }
        }
        return true;
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.size(), m =words.size(), len = words[0].size();
        
        unordered_map<string,int> freq;
        for ( int i = 0; i<m; i++ ){
            freq[ words[i] ]++;
        }
        
        vector<int> ans;
        for ( int i = 0; i<n-len*m+1; i++ ){
            string temp = "";
            for ( int j = i; j<i+len*m; j++ ){
                temp += s[j];
            }
            if ( check(s,i,i+len*m-1,len,freq) ){
                ans.push_back(i);
            }
        }
        
        return ans;        
    }
};