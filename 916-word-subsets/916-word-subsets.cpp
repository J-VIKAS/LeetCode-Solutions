class Solution {
public:
    
    bool check(vector<int> freq, vector<int> v){
        for ( int i = 0; i<26; i++ ){
            if ( v[i] != 0 && ( v[i] > freq[i] ) ){
                return false;
            }
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words2.size();
        
        vector<int> v(26,0);
        for ( int i = 0; i<n; i++ ){
            vector<int> freq(26,0);
            for ( int j = 0; j<words2[i].size(); j++ ){
                freq[ words2[i][j] - 'a' ]++; 
            }
            for ( int j = 0; j<26; j++ ){
                if ( freq[j] > v[j] ){
                    v[j] = freq[j];
                }
            }
        }
        
        n = words1.size();
        vector<string> ans;
        for ( int i = 0; i<n; i++ ){
            vector<int> freq(26,0);
            for ( int j = 0; j<words1[i].size(); j++ ){
                freq[ words1[i][j] - 'a' ]++;
            }

            if ( check(freq,v) ){
                ans.push_back(words1[i]);
            }
        }
        return ans;
        
    }
};