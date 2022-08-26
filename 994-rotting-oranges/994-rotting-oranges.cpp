class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        map<pair<int,int>,bool> vis;
        queue<pair<int,int>> q;
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( grid[i][j] == 2 ){
                    q.push({i,j});
                    vis[{i,j}] = true;
                }
            }
        }
            
        int time = -1;
        if ( q.empty() ){
            time = 0;
        }
        while ( !q.empty() ){
            time += 1;
            int k = q.size();
                
            while ( k-- ){
                pair<int,int> p = q.front();
                q.pop();
                    
                if ( p.first-1 >= 0 && grid[p.first-1][p.second] == 1 && !vis[{p.first-1,p.second}] ){
                    grid[p.first-1][p.second] = 2;
                    vis[{p.first-1,p.second}] = true;
                    q.push({p.first-1,p.second});
                }
                    
                if ( p.first+1 < n && grid[p.first+1][p.second] == 1 && !vis[{p.first+1,p.second}] ){
                    grid[p.first+1][p.second] = 2;
                    vis[{p.first+1,p.second}] = true;
                    q.push({p.first+1,p.second});
                }
                    
                if ( p.second-1 >= 0 && grid[p.first][p.second-1] == 1 && !vis[{p.first,p.second-1}] ){
                    grid[p.first][p.second-1] = 2;
                    vis[{p.first,p.second-1}] = true;
                    q.push({p.first,p.second-1});
                }
                    
                if ( p.second+1 < m && grid[p.first][p.second+1] == 1 && !vis[{p.first,p.second+1}] ){
                    grid[p.first][p.second+1] = 2;
                    vis[{p.first,p.second+1}] = true;
                    q.push({p.first,p.second+1});
                }
            }
        }
        
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( grid[i][j] == 1 ){
                    return -1;
                }
            }
        }
        
        return time;        
    }
};