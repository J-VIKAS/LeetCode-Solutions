class Solution {
public:
    
    bool ifvalid(int i, int j, int n){
        if ( i >= 0 && j >= 0 && i < n && j < n )
            return true;
        return false;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<n; j++ ){
                if ( grid[i][j] == 1 ){
                    q.push(make_pair(i,j));
                    vis[i][j] = true;
                }
            }
        }
        
        int dist = -1;
        while ( !q.empty() ){
            queue<pair<int,int>> p;
            dist += 1;
            while ( !q.empty() ){
                pair<int,int> point = q.front();
                q.pop();
                if ( ifvalid(point.first,point.second+1,n) && !vis[point.first][point.second+1] ){
                    vis[point.first][point.second+1] = true;
                    p.push(make_pair(point.first,point.second+1));
                }
                if ( ifvalid(point.first,point.second-1,n) && !vis[point.first][point.second-1] ){
                    vis[point.first][point.second-1] = true;
                    p.push(make_pair(point.first,point.second-1));
                }
                if ( ifvalid(point.first+1,point.second,n) && !vis[point.first+1][point.second] ){
                    vis[point.first+1][point.second] = true;
                    p.push(make_pair(point.first+1,point.second));
                }
                if ( ifvalid(point.first-1,point.second,n) && !vis[point.first-1][point.second] ){
                    vis[point.first-1][point.second] = true;
                    p.push(make_pair(point.first-1,point.second));
                }
            }
            q = p;
        }
        
        if ( dist == 0 )
            return -1;
        return dist;
        
    }
};