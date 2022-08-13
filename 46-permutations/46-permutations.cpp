class Solution {
public:
    void findpermutations(vector<int>& nums,vector<vector<int>>&result, vector<int>&temp,int vis[]){
        if(temp.size() == nums.size()){
            result.push_back(temp);
        }
        for(int i=0;i<nums.size();i++){
             if(vis[i]!=1){
                temp.push_back(nums[i]);
                vis[i] = 1;
                findpermutations(nums,result,temp,vis);
                vis[i] = 0;
                temp.pop_back();
            }   
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        int index = 0;
        int n = nums.size();
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i] == 0;
        }
        vector<int> temp;
        findpermutations(nums,result,temp, vis);
        return result;
    }
};