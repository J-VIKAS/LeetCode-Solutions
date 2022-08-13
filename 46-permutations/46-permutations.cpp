class Solution {
public:
    
    vector<vector<int>> ans;
    void rec(int n, map<int,bool> &taken, vector<int> nums, vector<int> a){
        
        bool check = false;
        for ( int i = 0; i<n; i++ ){
            if ( !taken[i] ){
                check = true;
                taken[i] = true;
                a.push_back(nums[i]);
                rec(n,taken,nums,a);
                a.pop_back();
                taken[i] = false;
            }
        }
        
        if ( !check ){
            ans.push_back(a);
            return;
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        map<int,bool> taken;
        vector<int> a;
        rec(nums.size(),taken,nums,a);
        return ans;
        
    }
};