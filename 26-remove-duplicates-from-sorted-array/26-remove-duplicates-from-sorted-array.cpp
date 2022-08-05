class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int k = 0;
        for ( int i = nums.size()-1; i >= 0; i-- ){
            if ( i == 0 ){
                k += 1;
            }
            else if ( nums[i] != nums[i-1] ){
                k += 1;
            } else {
                nums[i] = INT_MAX;
            }
        }
        
        sort(nums.begin(),nums.end());
        return k;
        
    }
};