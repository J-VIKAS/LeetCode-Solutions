class Solution {
public:
    
    void rec(int i, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> a){
        
        if ( target == 0 ){
            ans.push_back(a);
            return;
        }
        
        for ( int j = i; j<candidates.size(); j++ ){
            if ( j > i && candidates[j] == candidates[j-1] ) continue;
            if ( candidates[j] > target ) break;
            
            a.push_back(candidates[j]);
            rec(j+1,candidates,target-candidates[j],ans,a);
            a.pop_back();
        }
            
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int N = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> a;
        vector<vector<int>> ans;
        rec(0,candidates,target,ans,a);
        
        return ans;
    }
};