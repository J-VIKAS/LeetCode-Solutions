class Solution {
public:
    
    bool check( int x, int y, int n, int m ){
        if ( x >= 0 && x < n && y >= 0 && y < m )   return true;
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int dx[4] = {-1,1,0,0}, dy[4] = {0,0,1,-1}, c = image[sr][sc];
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        while ( !q.empty() ){
            pair<int,int> p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            for ( int i = 0; i<4; i++ ){
                int x = p.first + dx[i], y = p.second + dy[i];
                if ( check(x,y,image.size(),image[0].size()) && !vis[x][y] && image[x][y] == c ){
                    vis[x][y] = true;
                    q.push({x,y});
                }
            }
        }
        
        return image;
    }
};