class Solution {
public:

map<int,int> frst;
map<int,int> sec;


int even_node(vector<vector<int>> & adj, int n, int node){

    vector<int> vis(n, 0);
    vis[node]=true;
    sec[node]=1;

    queue<int> q;
    q.push(node);
    int k=0;
    int cnt=0;
    while(!q.empty())
    {
        int size=q.size();
        if(k%2==0)cnt+=size;
        for(int i=0; i< size; i++){
            int front=q.front();
            if(k%2==0){
                sec[front]=1;
            }
            q.pop();
            for(auto it: adj[front]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);

                }
            }


        }
        k++;
        
    }

    return cnt;
}


int odd_node(vector<vector<int>> & adj, int n, int node){

    vector<int> vis(n, 0);
    vis[node]=true;
    frst[node]=1;
    queue<int> q;
    q.push(node);
    int k=0;
    int cnt=0;
    while(!q.empty())
    {
        int size=q.size();
        if(k%2!=0){cnt+=size;}
        for(int i=0; i< size; i++){
            
            int front=q.front();
            if(k%2!=0){
                frst[front]=1;
            }
            q.pop();
            for(auto it: adj[front]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);

                }
            }


        }
        k++;
        
    }

    return cnt;



}

int max_even(vector<vector<int>> & edges){
    int n= edges.size()+1;
    vector<vector<int>> adj(n);

    for(auto it: edges){
        int u= it[0];
        int v= it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x= odd_node(adj, n, 0);
    int y= n-x;

    return max({x,y});
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int maxi=max_even(edges2);

        int n= edges1.size()+1;

        vector<vector<int>> adj(n);

        for(auto it : edges1){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        int x= even_node(adj, n, 0);
        for(int i=0; i< n; i++){
            if(sec.find(i)!=sec.end()){
                ans.push_back(x+maxi);
            }
            else{
                ans.push_back(n-x+maxi);
            }
        }

        return ans;

      
        
    }
};