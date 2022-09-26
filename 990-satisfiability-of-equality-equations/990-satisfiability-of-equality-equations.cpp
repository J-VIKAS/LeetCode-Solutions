class Solution {
public:
    
    int par[26] = {0};
    
    int find( int a ){
        if ( par[a] == a ) return a;
        return par[a] = find( par[a] );
    }
    
    void union_( int a, int b ){
        int pa = find(a);
        int pb = find(b);
        if ( par[pa] < par[pb] ){
            par[pb] = par[pa];
        } else {
            par[pa] = par[pb];
        }
    }
    
    
    bool equationsPossible(vector<string>& equations) {
        
        for ( int i = 0; i<26; i++ ){
            par[i] = i;
        }
        
        int n = equations.size();
        for ( int i = 0; i<n; i++ ){
            if ( equations[i][1] == '=' ){
                int a = equations[i][0] - 97;
                int b = equations[i][3] - 97; 
                union_(a,b);
                // cout << "par a, b = " << par[a] << " " << par[b] << "\n";
            }
        }
        
        for ( int i = 0; i<26; i++ ){
            find(i);
        }
        
        for ( int i = 0; i<n; i++ ){
            int a = equations[i][0] - 97;
            int b = equations[i][3] - 97; 
            if ( equations[i][1] == '!' && par[a] == par[b] ){ return false;
            }
        }
        
        return true;
        
    }
};