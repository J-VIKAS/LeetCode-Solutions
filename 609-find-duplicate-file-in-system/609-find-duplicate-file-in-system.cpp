class Solution {
public:
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        int n = paths.size(), in = 1;
        unordered_map<string,vector<string>> content_paths;
        
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
                    temp.push_back({k,content});
                    content = "";
                    k = "";
                    continue;
                }
                
                if ( paths[i][j] == '(' ) checkk = false;
                if ( checkk )   k += paths[i][j];
                if ( paths[i][j] == ')' ) checkk = true;
                
            }
            temp.push_back({k,content});
            
            for ( int j = 1; j<temp.size(); j++ )
                content_paths[ temp[j].second ].push_back( temp[0].first + "/" + temp[j].first );
            
        }
        
        vector<vector<string>> ans;
        for ( auto i : content_paths ){
            if ( i.second.size() > 1 )  ans.push_back(i.second);
        }
        
        return ans;        
    }
};