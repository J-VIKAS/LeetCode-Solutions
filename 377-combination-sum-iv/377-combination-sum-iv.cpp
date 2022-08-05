class Solution {
public:
        
    int rec(vector<int> &nums, int sum, int target, vector<int> &dp){
        
        if ( target-sum == 0 ){
            return 1;
        }
        
        if ( dp[sum] != -1 ){
            return dp[sum];
        }
        
        int total = 0;
        for ( int i = 0; i<nums.size(); i++ ){
            if ( nums[i] <= target-sum ){
                total += rec(nums,sum+nums[i],target,dp);
            }
        }
        
        return dp[sum] = total;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1,-1);
        return rec(nums,0,target,dp);
        
    }
};