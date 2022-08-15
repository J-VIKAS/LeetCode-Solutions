class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        
        int n = s.size();
        int ans = value[s[n-1]];
        for ( int i = n-2; i>=0; i-- ){
            if ( value[s[i]] >= value[s[i+1]] ){
                ans += value[s[i]];
            } else {
                ans -= value[s[i]];
            }
        }
        
        return ans;
    }
};