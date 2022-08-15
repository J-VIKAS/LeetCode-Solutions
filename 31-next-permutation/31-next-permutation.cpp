class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int l = -1, r = -1;
        for ( int i = nums.size()-2; i>=0; i-- ){
            if ( nums[i] < nums[i+1] ){
                l = i;
                break; }
        }        
        if ( l != -1 ){
            for ( int i = nums.size()-1; i>=0; i-- ){
                if ( nums[i] > nums[l] ){
                    r = i;
                    break; }
            }
            swap(nums[l],nums[r]);
        }
        sort(nums.begin()+l+1,nums.end());
    }
};