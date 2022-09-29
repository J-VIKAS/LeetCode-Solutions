class Solution {
public:
    
    static bool cmp( pair<int,int> a, pair<int,int> b ){
        if ( a.first < b.first ) return true;
        if ( a.first == b.first && a.second < b.second ) return true;
        return false;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<int> ans;
        vector<pair<int,int>> v;
        for ( int i = 0; i<n; i++ ) v.push_back({abs(arr[i]-x),arr[i]});
        sort(v.begin(),v.end(),cmp);
        for ( int i = 0; i<k; i++ ) ans.push_back(v[i].second);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};