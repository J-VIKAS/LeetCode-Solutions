class Solution {
public:
    vector<vector<string>> solutions;
    
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        int i = row-1,j = col-1;
        while ( i >= 0 && j >= 0 ){
            if ( board[i--][j--] == 'Q' ) return false;
        }
        
        i = row-1,j = col+1;
        while ( i >= 0 && j < n ){
            if ( board[i--][j++] == 'Q' ) return false;
        }
        
        i = row-1,j = col;
        while ( i >= 0 ){
            if ( board[i--][j] == 'Q' ) return false;
        }
        
        return true;
    }
    
    void solve(vector<string> &board, int row, int n)
    {
        if ( row == n ){
            solutions.push_back(board);
            return;
        }
        
        for ( int i = 0; i<n; i++ ){
            if ( isSafe(board,row,i,n) ){
                board[row][i] = 'Q';
                solve(board,row+1,n);
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int m) {
        string s;
        for ( int i = 0; i<m; i++ )
            s += '.';
        vector<string> board(m,s);
        solve(board,0,m);
        
        return solutions;
    }
};