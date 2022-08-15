class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int XOR = nums[0];
        for ( int i = 1; i<nums.size(); i++ )
            XOR ^= nums[i];
        return XOR;
        
    }
};