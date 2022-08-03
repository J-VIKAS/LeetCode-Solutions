class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = 1;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for ( int i = 1; i<nums.size(); i++ ){
            if ( nums[i] != nums[i-1] ){
                if ( count > nums.size()/3 ){
                    ans.push_back(nums[i-1]);
                }
                count = 0;
            }
            count++;
        }
        if ( count > nums.size()/3 ){
            ans.push_back(nums[nums.size()-1]);
        }
        return ans;
    }
};