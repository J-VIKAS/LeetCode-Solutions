class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int,bool> present;
        int k = 0;
        for ( int i = 0; i<nums.size(); i++ ){
            if ( !present[nums[i]] ){
                present[nums[i]] = true;
                k += 1;
            } else {
                nums[i] = INT_MAX;
            }
        }
        
        sort(nums.begin(),nums.end());
        return k;
        
    }
};