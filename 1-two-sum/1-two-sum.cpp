class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        map<int,vector<int>> ind;
        for ( int i = 0; i<n; i++ ){
            ind[nums[i]].push_back(i);
        }
        
        for ( int i = 0; i<n; i++ ){
            int val = target - nums[i];
            if ( val != nums[i] && ind[val].size() > 0 ){
                return {i,ind[val][0]};
            } else if ( val == nums[i] && ind[val].size() >= 2 ){
                return {i,ind[val][1]};
            }
        }
        return {};

    }
};