class Solution {
public:
    
    bool onedif( string &a, string &b ){
        int count = 0;
        for ( int i = 0; i<a.size(); i++ ){
            if ( a[i] != b[i] ){
                count += 1;
            }
        }
        return count == 1;
    }
    
    int shortest_path(string &beginWord, string &endWord, unordered_map<string,vector<string>> &adj){
        
        queue<string> q;
        unordered_map<string,bool> vis;
        bool found = false;
        q.push(beginWord);
        int m = 1;
        
        while ( !q.empty() ){
            int k = q.size();
            m += 1;
            while ( k-- ){
                string p = q.front();
                q.pop();
                if ( vis[p] )
                    continue;
                vis[p] = true;
                for ( auto j : adj[p] ){
                    if ( j == endWord )
                        found = true;
                    if (found) break;
                    if ( !vis[j] )
                        q.push(j);
                }
                if (found) break;
            }
            if (found) break;
        }
        
        if (found) return m;
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        bool check = false;
        for ( int i = 0; i<n; i++ ){
            if ( endWord == wordList[i] ){
                check = true;
                break;
            }
        }
        
        unordered_map<string,vector<string>> adj;
        for ( int i = 0; i<n; i++ ){
            if ( onedif(beginWord,wordList[i]) ){
                adj[beginWord].push_back(wordList[i]);
            }
        }
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<n; j++ ){
                if ( onedif(wordList[i],wordList[j]) && wordList[i] != beginWord ){
                    adj[wordList[i]].push_back(wordList[j]);
                }
            }
        }
    
        int len = shortest_path(beginWord,endWord,adj);
        
        return len;        
    }
};