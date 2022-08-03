class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        vector<pair<double,int>> v;
        for ( int i = 0; i<n; i++ ){
            double dist = pow( pow(points[i][0],2) + pow(points[i][1],2) , 0.5) ;
            v.push_back({dist,i});
        }
        
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for ( int i = 0; i<k; i++ ){
            ans.push_back({ points[v[i].second][0], points[v[i].second][1] });
        }
        
        return ans;
        
    }
};