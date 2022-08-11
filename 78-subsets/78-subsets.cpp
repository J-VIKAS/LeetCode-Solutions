class Solution {
public:
    
    vector<vector<int>> ans;
    
    void rec(int i, vector<int> &nums, int N, vector<int> a){
        
        if ( i == N ){
            ans.push_back(a);
            return;
        }
        
        rec(i+1,nums,N,a);
        a.push_back(nums[i]);
        rec(i+1,nums,N,a);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int N = nums.size();
        vector<int> a;
        rec(0,nums,N,a);
        return ans;
        
    }
};