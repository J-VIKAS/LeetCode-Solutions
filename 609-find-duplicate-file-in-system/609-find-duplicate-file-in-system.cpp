class Solution {
public:
    
    string addstring( string &root, string &file ){
        string res = "";
        for ( int i = 0; i<root.size(); i++ ) res += root[i];
        res += '/';
        for ( int i = 0; i<file.size(); i++ ) res += file[i];
        return res;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        int n = paths.size(), in = 1;
        map<string,int> ind;
        map<int,vector<string>> content_paths;
        
        for ( int i = 0; i<n; i++ ){
            string content = "";
            bool checkc = false, checkk = true;
            string k = "";
            vector<pair<string,string>> temp;
            for ( int j = 0; j<paths[i].size(); j++ ){
                
                if ( paths[i][j] == ')' )   checkc = false;
                if ( checkc ) content += paths[i][j];
                if ( paths[i][j] == '(' )   checkc = true;
                
                if ( paths[i][j] == ' ' ){
                    if ( ind[ content ] == 0 ) ind[ content ] = in++;
                    temp.push_back({k,content});
                    content = "";
                    k = "";
                    continue;
                }
                
                if ( paths[i][j] == '(' ) checkk = false;
                if ( checkk )   k += paths[i][j];
                if ( paths[i][j] == ')' ) checkk = true;
                
            }
            
            if ( ind[ content ] == 0 ) ind[ content ] = in++;
            temp.push_back({k,content});
            
            for ( int j = 1; j<temp.size(); j++ ){
                string res = addstring(temp[0].first,temp[j].first);
                cout << temp[j].second << " -> " << res << "\n";
                content_paths[ ind[temp[j].second] ].push_back( res );
            }
            
        }
        
        vector<vector<string>> ans;
        for ( int i = 0; i<in; i++ ){
            if ( content_paths[i].size() > 1 )
                ans.push_back(content_paths[i]);
        }
        
        return ans;        
    }
};