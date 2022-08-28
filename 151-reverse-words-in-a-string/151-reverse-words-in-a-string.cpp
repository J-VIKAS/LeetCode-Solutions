class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "", temp = "";
        int n = s.size(), size = 0;
        for ( int i = 0; i<n; i++ ){
            if ( s[i] == ' ' ){
                if ( size != 0 )    ans = temp + " " + ans;
                temp = "";
                size = 0;
            } else {
                temp += s[i];
                size++;
            }
        }
        if ( size != 0 ) ans = temp + " " + ans;
        return ans.substr(0,ans.size()-1);
    }
};