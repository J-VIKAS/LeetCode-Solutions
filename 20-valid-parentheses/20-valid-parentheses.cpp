class Solution {
public:
    
    bool isValid(string s) {
        
        int n = s.size();
        stack<int> k;
        for ( int i = 0; i<n; i++ ){
            if ( s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                k.push(s[i]);
            } else {
                char c;
                if ( s[i] == ')' )
                    c = '(';
                else if ( s[i] == '}' )
                    c = '{';
                else
                    c = '[';
                
                if ( !k.empty() && k.top() == c ){
                    k.pop();
                } else {
                    k.push(s[i]);
                }
            }
        }
        
        return k.size() == 0;
    }
};