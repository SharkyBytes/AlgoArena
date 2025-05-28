class Solution {
public:

int bfs(vector<vector<int>> & adj, int node, int n, int k)
{
    vector<int> vis(n, 0);
    vis[node]=true;
    queue<int> q;
    int cnt=0;
    q.push(node);
    int tot=0;
    while(!q.empty() && cnt<k){
       int size=q.size();
       for(int i=0; i<size; i++){

        int node=q.front();
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                tot++;
                q.push(it);
                vis[it]=true;
            }
        }

       }
       cnt++;


    }
    return tot;
}

int max_nodes(vector<vector<int>> & edges, int k){
    int n= edges.size()+1;
    vector<vector<int>> adj(n);
    for(auto it: edges){
        int u= it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int best=INT_MIN;
    for(int i=0; i<n ; i++){
        best=max(best, bfs(adj, i,n, k));

    }

    return best+1;

}

vector<int> target_nodes(vector<vector<int>> & edges, int k, int maxi){
    int n= edges.size()+1;
    vector<vector<int>> adj(n);
    for(auto it: edges){
        int u= it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    for(int i=0; i< n; i++){
        int x= bfs(adj, i ,n,k );
        cout<<maxi<<endl;
        if(k>0){
             ans.push_back(x+maxi+1);

        }
        else{
            ans.push_back(x+1);
        }
       
    }

    return ans;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        int maxi=max_nodes(edges2, k-1);

        return target_nodes(edges1, k, maxi);

        
    }
};