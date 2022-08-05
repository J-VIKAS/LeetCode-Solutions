class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size(), ans = 0, j = 0;
        for ( int i = 0; i<n; i++ ){
            j = max(i,j);
            while ( j < n && nums[j] == 1 ){
                j += 1;
            }
            ans = max(ans,j-i);
        }

        return ans;
    }
};