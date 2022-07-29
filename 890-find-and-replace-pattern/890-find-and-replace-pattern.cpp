class Solution {
public:
    
    vector<int> convert(string s){
        int n = s.size(), num = 1;
        vector<int> tonum;
        map<char,int> index;
        for ( int i = 0; i<n; i++ ){
            if ( index[s[i]] != 0 ){
                tonum.push_back(index[s[i]]);
            } else {
                tonum.push_back(index[s[i]]);
                index[s[i]] = num;
                num++;
            }
        }
        return tonum;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<vector<int>> tonumwords;
        vector<string> ans;
        vector<int> tonumpattern = convert(pattern);
        
        for ( int i = 0; i<n; i++ ){
            tonumwords.push_back(convert(words[i]));
        }
        for ( int i = 0; i<n; i++ ){
            if ( tonumpattern == tonumwords[i] )
                ans.push_back(words[i]);
        }
        return ans;
    }
};