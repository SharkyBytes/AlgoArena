class Solution {
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {

        queue<int> q;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i< arr.size() ; i++){
            adj[arr[i][0]].push_back({arr[i][1], arr[i][2]});

        }
        vector<int> dist(n+1, 1e5);
        dist[k]=0;
        q.push(k);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[it.first]> dist[node]+it.second){
                    q.push(it.first);
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }

        int maxi=-1e5;

        for(int i=1; i<=n ; i++){
            maxi=max(dist[i], maxi);

        }



return maxi==1e5 ? -1: maxi;
        
    }
};