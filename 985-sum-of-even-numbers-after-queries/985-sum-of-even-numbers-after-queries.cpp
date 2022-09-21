class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        vector<int> ans;
        for ( int i = 0; i<nums.size(); i++ )   if ( nums[i]%2 == 0 ) sum += nums[i];
        for ( int i = 0; i<queries.size(); i++ ){
            int prev = nums[ queries[i][1] ];
            nums[ queries[i][1] ] += queries[i][0];
            int upd = nums[ queries[i][1] ];
            if ( prev%2 == 0 && upd%2 == 0 ) sum += ( upd - prev );
            else if ( prev%2 == 0 && upd%2 != 0 ) sum += ( - prev );
            else if ( prev%2 != 0 && upd%2 == 0 ) sum += ( upd );
            ans.push_back(sum);
        }
        return ans;
    }
};