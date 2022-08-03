class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        map<int,vector<pair<int,int>>> adj;
        for ( int i = 0; i<roads.size(); i++ ){
            adj[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }
        
        vector<long long> time(n+1,LONG_MAX);
        time[0] = 0;
        vector<long long> ways(n+1,0);
        ways[0] = 1;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> q;
        q.push({0,0});
        
        while ( !q.empty() ){
            pair<long, long> p = q.top();
            q.pop();
            for(auto j : adj[p.second]){
                if(j.first + p.first < time[j.second]){
                    time[j.second] = j.first + p.first;
                    ways[j.second]= ways[p.second];
                    q.push({j.first + p.first,j.second });
                }
                else if(j.first + p.first == time[j.second]){
                    ways[j.second]= (ways[j.second] + ways[p.second])%1000000007;
                }
            }
        }
        
        return ways[n-1];
    }
};