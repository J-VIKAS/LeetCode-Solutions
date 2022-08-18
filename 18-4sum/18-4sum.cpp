class Solution {
public:
    
    void binary_search(vector<int>& nums, int i, int j, long long target, int a, int b, vector<vector<int>>& ans){
        map<vector<int>,bool> p;
        while ( i < j ){
            if ( nums[i] + nums[j] == target && !p[{nums[i],nums[j]}] ){
                ans.push_back({a,b,nums[i],nums[j]});
                p[{nums[i],nums[j]}] = true;
                i += 1;
            } else if ( nums[i] + nums[j] < target ){
                i += 1;
            } else {
                j -= 1;
            }
        } 
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        map<vector<int>,bool> p;
        vector<vector<int>> ans;
        for ( int i = 0; i<nums.size(); i++ ){
            for ( int j = i+1; j<nums.size(); j++ ){
                if ( !p[{nums[i],nums[j]}] )
                    try { 
                        binary_search(nums,j+1,nums.size()-1,((long long)target-nums[i]-nums[j]),nums[i],nums[j],ans);
                    } catch (int k){
                        continue;
                    }
                p[{nums[i],nums[j]}] = true;
            }
        }
        return ans;
        
    }
};