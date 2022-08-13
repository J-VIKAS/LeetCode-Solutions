class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool check(int i, int j, int n, vector<string> &board){
        
        int a, b;
        
        a = i-1, b = j-1;
        while ( a >= 0 && b >= 0 ){
            if ( board[a--][b--] == 'Q' ){
                return false;
            }
        }
        
        a = i+1, b = j-1;
        while ( a < n && b >= 0 ){
            if ( board[a++][b--] == 'Q' ){
                return false;
            }
        }
        
        a = i-1, b = j+1;
        while ( a >= 0 && b < n ){
            if ( board[a--][b++] == 'Q' ){
                return false;
            }
        }
        
        a = i+1, b = j+1;
        while ( a < n && b < n ){
            if ( board[a++][b++] == 'Q' ){
                return false;
            }
        }
        
        a = 0;
        while ( a < n ){
            if ( board[a++][j] == 'Q' ){
                return false;
            }
        }
        
        b = 0;
        while ( b < n ){
            if ( board[i][b++] == 'Q' ){
                return false;
            }
        }
        
        return true;
    }
    
    void rec(int i, int n, vector<string> &board){
        
        if ( i == n ){
            ans.push_back(board);
            return;
        }
        
        for ( int j = 0; j<n; j++ ){
            if ( check(i,j,n,board) ){
                board[i][j] = 'Q';
                rec(i+1,n,board);
                board[i][j] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s = "";
        for ( int i = 0; i<n; i++ )
            s += '.';
        vector<string> board(n,s);
        rec(0,n,board);
        
        return ans;
    }
};