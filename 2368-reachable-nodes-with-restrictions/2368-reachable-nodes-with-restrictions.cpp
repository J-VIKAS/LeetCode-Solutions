class Solution {
public:
    
    int ans = 1;
    
    void dfs(int node, map<int,vector<int>> &adj, vector<bool> &vis){
        if ( !vis[node] ){
            vis[node] = true;
            for ( auto i : adj[node] ){
                if ( !vis[i] ){
                    ans += 1;
                    dfs(i,adj,vis);
                }
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        map<int,vector<int>> adj;
        for ( int i = 0; i<edges.size(); i++ ){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n+1,false);
        for ( int i = 0; i<restricted.size(); i++ ){
            vis[restricted[i]] = true;
        }
        
        dfs(0,adj,vis);
        
        return ans;
    }
};