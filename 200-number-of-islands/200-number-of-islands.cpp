class Solution {
public:
    
    vector<vector<int>> d = {{-1,0},{1,0},{0,1},{0,-1}};
    int count = 0;
    
    bool check1( int i, int j, int n, int m, vector<vector<char>> &grid ){
        if ( i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '1' && grid[i][j] != '0' ) return true;
        return false;
    }
    
    bool check2( int i, int j, int n, int m, vector<vector<char>> &grid ){
        if ( i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1' ) return true;
        return false;
    }
    
    void dfs( int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid, int n, int m ){
        if ( !vis[i][j] ){
            vis[i][j] = true;
            bool check = false;
            for ( int k = 0; k<4; k++ ){
                if ( check1(i+d[k][0],j+d[k][1],n,m,grid) ){
                    grid[i][j] = grid[i+d[k][0]][j+d[k][1]];
                    check = true;
                }
            }
            if ( !check ) {
                grid[i][j] = 'd';
                count++;
            }
            for ( int k = 0; k<4; k++ ){
                if ( check2(i+d[k][0],j+d[k][1],n,m,grid) ){
                    dfs(i+d[k][0],j+d[k][1],vis,grid,n,m);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<m; j++ ){
                if ( !vis[i][j] && grid[i][j] == '1' ){
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        
        return count;
    }
};