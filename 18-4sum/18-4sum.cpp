class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for ( int i = 0; i<nums.size(); i++){
            for ( int j = i+1; j<nums.size(); j++){
                int l = j+1, r = nums.size()-1;
                while ( l < r ){
                    if ( nums[l] + nums[r] == (long long int)target - nums[i] - nums[j] ){
                        vector<int> temp = {nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(temp);
                        int val3 = nums[l], val4 = nums[r];
                        while ( l < r && val3 == nums[l] ) l++;
                        while ( l < r && val4 == nums[r] ) r--;
                    } else if ( nums[l] + nums[r] < (long long int)target - nums[i] - nums[j] ){
                        l += 1;
                    } else {
                        r -= 1;
                    }
                }
                while ( j+1 < nums.size() && nums[j+1] == nums[j] ) ++j;
            }
            while ( i+1 < nums.size() && nums[i+1] == nums[i] ) ++i;
        }
        
        return ans;
    }
};