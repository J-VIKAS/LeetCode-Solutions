class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string ans = "";
        for ( int i = 0; i<strs[0].size(); i++ ){
            bool check = false;
            for ( int j = 0; j<n; j++ ){
                if ( strs[j][i] != strs[0][i] ){
                    check = true;
                    break;
                }
            }
            if ( check )
                break;
            else
                ans += strs[0][i];
        }
        
        return ans;        
    }
};