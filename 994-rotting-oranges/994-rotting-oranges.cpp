class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> q;
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( grid[i][j] == 2 ){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        
        vector<vector<int>> d = { {-1,0}, {1,0}, {0,-1}, {0,1} };
        
        int time = -1;
        if ( q.empty() ) time = 0;
        while ( !q.empty() ){
            time += 1;
            int k = q.size();
            while ( k-- ){
                pair<int,int> p = q.front();
                q.pop();
                for ( int i = 0; i<d.size(); i++ ){
                    int a = p.first + d[i][0], b = p.second + d[i][1];
                    if ( a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1 && !vis[a][b] ){
                        vis[a][b] = true;
                        grid[a][b] = 2;
                        q.push({a,b});
                    }
                }
            }
        }
        
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( grid[i][j] == 1 ) return -1;
            }
        }
        
        return time;
    }
};