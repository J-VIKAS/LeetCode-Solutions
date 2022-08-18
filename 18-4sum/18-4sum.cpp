class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int len = 0;
        map<vector<int>,bool> p;
        sort(nums.begin(),nums.end());
        for ( int i = 0; i<nums.size(); i++ ){
            for ( int j = i+1; j<nums.size()-1; j++ ){
                long long int t = (long long int)target - nums[i] - nums[j];
                int l = j+1, r = nums.size()-1;
                if ( p[{nums[i],nums[j]}] )
                    continue;
                while ( l < r ){
                    if ( nums[l] + nums[r] == t ){
                        vector<int> temp = {nums[i],nums[j],nums[l],nums[r]};
                        if ( len == 0 || (len != 0 && ans[len-1] != temp ) ){
                            ans.push_back(temp);
                            len += 1;
                        }
                        l += 1;
                    } else if ( nums[l] + nums[r] < t ){
                        l += 1;
                    } else {
                        r -= 1;
                    }
                }
                p[{nums[i],nums[j]}] = true;
            }
        }
        
        return ans;
    }
};