class Solution {
public:
    
    static bool cmp( pair<int,int> a, pair<int,int> b ){
        return a.first > b.first;
    }
    
    int maxPerformance( int n, vector<int>& speed, vector<int>& efficiency, int k ) {
        
        vector<pair<int,int>> v;
        for ( int i = 0; i<n; i++ ){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end(),cmp);
        
        priority_queue<int,vector<int>,greater<int>> q;
        long ans = 0, total_sum = 0;
        
        for ( int i = 0; i<n; i++ ){
            q.push(v[i].second);
            total_sum += v[i].second;
            if ( q.size() > k ){
                total_sum -= q.top();
                q.pop();
            }
            ans = max(ans,v[i].first*total_sum);
        }
        
        return (int)(ans%(1000000000+7));
    }
};