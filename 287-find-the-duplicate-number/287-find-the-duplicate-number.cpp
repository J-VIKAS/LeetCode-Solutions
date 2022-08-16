class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[nums[0]], f = nums[nums[nums[0]]];
        while ( s != f ){
            s = nums[s];
            f = nums[nums[f]];
        }
        f = nums[0];
        while ( s != f ){
            s = nums[s];
            f = nums[f];
        }
        return f;
    }
};