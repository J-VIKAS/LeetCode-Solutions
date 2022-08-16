class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        for ( int i = 0; i<n; i++ ){
            if ( nums[i] <= 0 || nums[i] > n ){
                nums[i] = INT_MAX;
            }
        }
        
        for ( int i = 0; i<n; i++ ){
            if ( nums[i] != INT_MAX && nums[i] != (-1)*INT_MAX  ){
                if ( nums[abs(nums[i])-1] > 0 )
                    nums[abs(nums[i])-1] *= (-1);
            }
        }
        
        for ( int i = 1; i<=n; i++ ){
            if ( nums[i-1] > 0 ){
                return i;
            }
        }
        
        return n+1;
    }
};