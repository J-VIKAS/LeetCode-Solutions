class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        sort(nums.begin(),nums.end());
        for ( int i = 1; i<nums.size(); i++ ){
            if ( nums[i] != nums[i-1] ){
                if ( count > nums.size()/2 ){
                    return nums[i-1];
                }
                count = 0;
            }
            count++;
        }
        if ( count > nums.size()/2 ){
            return nums[nums.size()-1];
        } else {
            return -1;
        }
    }
};