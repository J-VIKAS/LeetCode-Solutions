class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0, j = nums.size()-1, k = nums.size()-1;
        while ( j >= i ){
            if ( nums[j] == 0 ){
                swap(nums[j],nums[i]);
                i++;
            } else if ( nums[j] == 2 ){
                swap(nums[j],nums[k]);
                k--;j--;
            } else {
                j--;
            }
        }
        
    }
};