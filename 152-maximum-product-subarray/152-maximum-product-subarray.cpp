class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], n = nums.size(), Min = 1, Max = 1;
        for ( int i = 0; i<n; i++ ){
            int m = Max;
            Max = max({ nums[i], Max*nums[i], Min*nums[i] });
            Min = min({ nums[i], m*nums[i], Min*nums[i] });
            ans = max(ans,Max);
        }
        return ans;
    }
};