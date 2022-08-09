class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        map<int,long long int> ways;
        for ( int i = 0; i<n; i++ ){
            ways[arr[i]] = 1;
        }
        
        for ( int i = 0; i<n; i++ ){
            long long int count = 0;
            for ( int j = 0; j<i; j++ ){
                if ( arr[i]%arr[j] == 0 ){
                    if ( ways[ arr[i]/arr[j] ] != 0 ){
                        count += ways[ arr[i]/arr[j] ] * ways[ arr[j] ];
                    }
                }
            }
            ways[ arr[i] ] += count;
        }
        
        long long int ans = 0;
        for ( int i = 0; i<n; i++ ){
            ans += ways[ arr[i] ];
        }
        
        return ans%(1000000007);        
    }
};