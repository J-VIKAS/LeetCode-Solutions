class Solution {
public:
    
    static bool cmp ( pair<int,int> a, pair<int,int> b ){
        return a.first > b.first;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size(), count = 1;
        sort(nums.begin(),nums.end());
        
        vector<pair<int,int>> v;
        for ( int i = 1; i<n; i++ ){
            if ( nums[i] != nums[i-1] ){
                v.push_back({count,nums[i-1]});
                count = 1;
            } else {
                count += 1;
            }
        }
        v.push_back({count,nums[n-1]});
        sort(v.begin(),v.end(),cmp);
        
        vector<int> ans;
        for ( int i = 0; i<k; i++ ){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};