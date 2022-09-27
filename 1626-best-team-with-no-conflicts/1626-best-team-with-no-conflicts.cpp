class Solution {
public:
    
    static bool cmp( pair<int,int> &a, pair<int,int> &b ){
        if ( a.first < b.first ) return true;
        else if ( a.first == b.first && a.second < b.second )   return true;
        return false;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> vec;
        int l[1001] = {0};
        for ( int i = 0; i<n; i++ ) vec.push_back({ages[i],scores[i]});
        sort(vec.begin(),vec.end(),cmp);
        for ( int i = 0; i<n; i++ ) l[i] = vec[i].second;
        int ans = INT_MIN;
        for ( int i = 0; i<n; i++ ){
            int k = 0;
            for ( int j = i-1; j>=0; j-- ){
                if ( vec[i].second >= vec[j].second )   k = max(k,l[j]);
            }
            ans = max(ans,l[i] += k);
        }
        return ans;
    }
};