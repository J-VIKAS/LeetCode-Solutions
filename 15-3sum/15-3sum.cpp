class Solution {
public:
    
    void binary_search( int target, vector<int> &nums, int l, int r, vector<vector<int>> &ans ){
        
        int n = nums.size();
        while ( l < r ){
            if ( nums[l] + nums[r] == target ){
                
                ans.push_back({-(target),nums[l],nums[r]});
                int left = nums[l];
                int right = nums[r];
                while ( nums[l] == left && nums[r] == right && l < r ){
                    l++;
                    r--;
                }
        
            } else if ( nums[l] + nums[r] > target ){
                r--;
            } else {
                l++;
            }
        }
        
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        nums.push_back(INT_MIN);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for ( int i = 1; i<n; i++ ){
            if ( nums[i] != nums[i-1]  ){
                binary_search(-(nums[i]),nums,i+1,n-1,ans);
            }
        }
        
        return ans;
    }
};