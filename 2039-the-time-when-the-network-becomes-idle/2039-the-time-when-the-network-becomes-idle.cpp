class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = edges.size(), m = patience.size();
        map<int,vector<int>> adj;
        for ( int i = 0; i<n; i++ ){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n+1,false);
        vector<int> distance(m,0);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        int dist = -1;
        while( !q.empty() ){
            
            queue<int> p;
            dist += 1;
            while ( !q.empty() ){
                int node = q.front();
                
                if ( node != 0 ){
                    distance[node] = dist;
                }
                
                q.pop();
                for ( auto i : adj[node] ){
                    if ( !vis[i] ){
                        vis[i] = true;
                        p.push(i);
                    }
                }
            }
            q = p;
            
        }
        
        int ans = INT_MIN;
        for ( int i = 1; i<m; i++ ){
            int t = 2*distance[i] + patience[i]*((2*distance[i]-1)/patience[i]) + 1;
            ans = max(ans,t);
        }
        
        return ans;
    }
};