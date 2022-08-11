class Solution {
public:
    
    vector<vector<int>> ans;
    
    void rec( int i, vector<int> &nums, int N, vector<int> a){
        
        if ( i == N ){
            bool check = false;
            for ( int j = 0; j<ans.size(); j++ ){
                if ( a == ans[j] ){
                    check = true;
                    break;
                }
            }
            if ( !check ){
                ans.push_back(a);
            }
            return;
        }
        
        rec(i+1,nums,N,a);
        a.push_back(nums[i]);
        rec(i+1,nums,N,a);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int N = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> a;
        rec(0,nums,N,a);
        
        return ans;
    }
};