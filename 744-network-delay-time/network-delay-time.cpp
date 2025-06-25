class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist(n+1, 1e9);
        dist[k]=0;
        int p=n;

       vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        int maxi=INT_MIN;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            int d=q.top().first;
            int node=q.top().second;
            q.pop();

            for(auto it : adj[node]){
                if(it.second+d<dist[it.first]){
                    dist[it.first]=it.second+d;
                   
                    q.push({dist[it.first], it.first});
                }
            }
        }
        for(int i=1; i<=n ; i++){
            maxi=max(maxi, dist[i]);
        }
return maxi==1e9 ? -1:maxi;

        
    }
};