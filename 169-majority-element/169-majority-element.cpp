class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = -1, cnt = 0;
        for ( int i = 0; i<nums.size(); i++ ){
            if ( nums[i] == num ) cnt++;
            else if ( cnt == 0 ){
                num = nums[i];
                cnt += 1;
            } else {
                cnt -= 1;
            }
        }
        return num;
    }
};