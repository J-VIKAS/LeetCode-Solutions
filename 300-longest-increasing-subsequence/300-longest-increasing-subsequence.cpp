class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for ( int i = 1; i<n; i++ ){
            if ( nums[i] > temp.back() ){
                temp.push_back(nums[i]);
            } else {
                vector<int>::iterator ind = lower_bound(temp.begin(),temp.end(),nums[i]);
                temp[ind-temp.begin()] = nums[i];
            }
        }
        
        return temp.size();        
    }
};