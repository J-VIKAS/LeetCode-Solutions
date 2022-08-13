class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string,int> present;
        vector<int> ans;
        
        for ( int i = 0; i<m; i++ ){
            present[ words[i] ]++;
        }
        
        for ( int i = 0; i<n-(len*m)+1; i++ ){
            unordered_map<string,int> temp;
            for ( int j = i; j<i+(len*m); j+=len ){
                temp[ s.substr(j,len) ]++;                
            }
            if ( temp == present ){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};