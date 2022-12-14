class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size(), count = 1, ans = 0;
        if ( n == 0 ) return 0;
        sort(nums.begin(),nums.end());
        for ( int i = 1; i<n; i++ ){
            if ( nums[i]-1 == nums[i-1] )
                count++;
            else if ( nums[i] == nums[i-1] )
                continue;
            else if ( nums[i]-1 != nums[i-1] ){ 
                ans = max(ans,count);
                count = 1;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};