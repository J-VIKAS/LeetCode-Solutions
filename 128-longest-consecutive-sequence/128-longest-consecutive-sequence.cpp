class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int ans = 0;
        unordered_map<int,bool> p;
        for ( int i = 0; i<nums.size(); i++ ){
            p[nums[i]] = true;
        }
        for ( int i = 0; i<nums.size(); i++ ){
            if ( !p[nums[i]-1] ){
                int j = 1;
                while ( p[nums[i]+j] ){
                    j++;
                }
                ans = max(ans,j);
            }
        }
        return ans;
    }
};