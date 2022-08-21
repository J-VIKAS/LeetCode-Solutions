class Solution {
public:
    
    bool isPossible( string &stamp, string &target, int s, int n, int m ){
        
        bool notstar = false;
        
        int j = 0;
        for ( int i = s; i<s+n; i++ ){
            if ( target[i] != '?' ){
                notstar = true;
            }
            if ( target[i] == stamp[j] || target[i] == '?' ){
                j++;
            } else {
                return false;
            }
        }
        return true;
        
    }
    
    int update( string &target, int l, int r, int n ){
        
        int count = 0;
        for ( int i = l; i<r; i++ ){
            target[i] = '?';
        }
        for ( int i = 0; i<n; i++ ){
            if ( target[i] == '?' ) count++;
        }
        return count;
        
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        int n = stamp.size(), m = target.size(), count = 0;
        vector<bool> visited(m, false);
        vector<int> ans;
        
        while ( count != m ){
            
            bool anyupdates = false;
            
            for ( int i = 0; i<=m-n; i++ ){
                if ( !visited[i] && isPossible(stamp,target,i,n,m) ){
                    // cout << "i = " << i << "\n";
                    visited[i] = true;
                    anyupdates = true;
                    count = update(target,i,i+n,m);
                    ans.push_back(i);
                    
//                     cout << "vis : ";
//                     for ( int j = 0; j<visited.size(); j++ ){
//                         cout << visited[j] << " ";
//                     } cout << "\n";
                    
//                     cout << "target : " << target << "\n";
//                     cout << "count : " << count << "\n";
                    
//                     cout << "ans : ";
//                     for ( int j = 0; j<ans.size(); j++ ){
//                         cout << ans[j] << " ";
//                     } cout << "\n";
                    
                    if ( count == m )
                        break;
                }
            }
            
            if ( !anyupdates ){
                return {};
            }

        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};