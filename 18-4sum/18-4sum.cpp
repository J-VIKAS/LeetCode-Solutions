class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        map<vector<int>,bool> p;
        sort(nums.begin(),nums.end());
        for ( int i = 0; i<nums.size(); i++ ){
            for ( int j = i+1; j<nums.size()-1; j++ ){
                long long int t = (long long int)target - nums[i] - nums[j];
                int l = j+1, r = nums.size()-1;
                while ( l < r ){
                    if ( nums[l] + nums[r] == t ){
                        if ( !p[{nums[i],nums[j],nums[l],nums[r]}] )
                            ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        p[{nums[i],nums[j],nums[l],nums[r]}] = true;
                        l += 1;
                    } else if ( nums[l] + nums[r] < t ){
                        l += 1;
                    } else {
                        r -= 1;
                    }
                }
            }
        }
        
        return ans;
    }
};