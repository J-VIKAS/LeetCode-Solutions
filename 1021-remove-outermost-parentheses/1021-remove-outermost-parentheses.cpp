class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        int count = 0;
        for ( int i = 0; i<s.size(); i++ ){
            if ( s[i] == '(' ){
                if ( count != 0 ){
                    ans += '(';
                }
                count += 1;
            } else {
                count -= 1;
                if ( count != 0 ){
                    ans += ')';
                }
            }
        }
        
        return ans;
    }
};