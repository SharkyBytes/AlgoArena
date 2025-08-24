class Solution {
public:
vector<int> vis;
bool check(vector<vector<pair<int,int>>> & adj , int mid){

    queue<int> q;
    q.push(0);
    int n=adj.size();
    vis.assign(n, 0);
    vis[0]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        vis[node]=true;
        for(auto it : adj[node]){
            if(!vis[it.first] && it.second<=mid ){
                vis[it.first]=true;
                q.push(it.first);
            }
        }
    }

    for(auto it: vis){
        if(it==0)return false;
    }

    return true;

}
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<pair<int,int>>> adj(n);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it : edges){
            int u= it[0];
            int v= it[1];
            int w= it[2];
            adj[v].push_back({u,w});
            mini=min(w, mini);
            maxi=max(w, maxi);
        }

        int s=mini;
        int e= maxi;
        int ans=-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(check(adj , mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};