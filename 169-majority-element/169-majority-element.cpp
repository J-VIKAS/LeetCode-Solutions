class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, n = nums.size();
        sort(nums.begin(),nums.end());
        for ( int i = 1; i<n; i++ ){
            if ( nums[i] != nums[i-1] ){
                if ( count > n/2 ){
                    return nums[i-1];
                }
                count = 0;
            }
            count++;
        }
        if ( count > n/2 ){
            return nums[n-1];
        } else {
            return -1;
        }
    }
};