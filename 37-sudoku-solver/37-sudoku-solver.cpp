class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, int i, int j, char ch){
        for ( int a = 0; a<9; a++ ){
            if ( board[a][j] == ch )
                return false;
            if ( board[i][a] == ch )
                return false;
            if ( board[3*(i/3)+a/3][3*(j/3)+a%3] == ch )
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int n){
        
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<n; j++ ){
                if ( board[i][j] == '.' ){
                    for ( char ch = '1'; ch<='9'; ch++ ){
                        if ( isSafe(board,i,j,ch) ){
                            board[i][j] = ch;
                            if ( !solve(board,n) ){
                                board[i][j] = '.';
                            } else {
                                return true;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,board.size());
    }
};