class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int ans = 0;
        set<int> p;
        for ( int i = 0; i<nums.size(); i++ ){
            p.insert(nums[i]);
        }
        for ( int i = 0; i<nums.size(); i++ ){
            if ( !p.count(nums[i]-1) ){
                int j = 1;
                while ( p.count(nums[i]+j) ){
                    j++;
                }
                ans = max(ans,j);
            }
        }
        return ans;
    }
};