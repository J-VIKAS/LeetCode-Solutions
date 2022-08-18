class Solution {
public:
    
    static bool cmp ( pair<int,int> a, pair<int,int> b ){
        return a.first > b.first;    
    }
    
    int minSetSize(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int n = arr.size(), count = 1, ans = 0;
        vector<pair<int,int>> v;
        for ( int i = 1; i<n; i++ ){
            if ( arr[i] != arr[i-1] ){
                v.push_back({count,arr[i-1]});
                count = 1;
            } else {
                count += 1;
            }
        }
        v.push_back({count,arr[n-1]});
        sort(v.begin(),v.end(),cmp);
        
//         cout << "v : \n";
//         for ( int i = 0; i<v.size(); i++ ){
//             cout << v[i].first << " " << v[i].second << "\n";
//         } cout << "\n";
        
        count = 0;
        for ( int i = 0; i<v.size(); i++ ){
            if ( count + v[i].first < n/2 ){
                ans += 1;
                count += v[i].first;
            } else {
                count += v[i].first;
                ans += 1;
                break;
            }
        }
        
        return ans;
    }
};