class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0], last = intervals[0][1];
        vector<vector<int>> ans;
        for ( int i = 1; i<intervals.size(); i++ ){
            if ( last >= intervals[i][0] )  last = max(last,intervals[i][1]);
             else {
                ans.push_back({start,last});
                start = intervals[i][0], last = intervals[i][1];
            }
        }
        ans.push_back({start,last});
        return ans;
    }
};