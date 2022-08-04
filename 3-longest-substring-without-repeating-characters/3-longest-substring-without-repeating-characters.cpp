class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), j = 0, ans = 0;
        map<int,int> freq;
        for ( int i = 0; i<n; i++ ){
            while ( j < n && freq[s[j]] == 0 ){
                freq[s[j]]++;
                j++;
            }
            ans = max(ans,j-i);
            freq[s[i]]--;
        }
        return ans;
        
    }
};