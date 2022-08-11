class Solution {
public:
    
    vector<vector<int>> ans;
    
    void rec(int i, int Sum, int N, int T, vector<int> &nums, vector<int> a){
        
        if ( Sum == T ){
            ans.push_back(a);
        }
        
        if ( i == N ){
            return;
        }
        
        if ( Sum + nums[i] <= T ){
            rec(i+1,Sum,N,T,nums,a);
            a.push_back(nums[i]);
            rec(i,Sum+nums[i],N,T,nums,a);
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        
        int N = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> a;
        rec(0,0,N,target,candidates,a);
        return ans;
    }
};