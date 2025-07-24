class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n , 0);
        for(int i=0; i< n ; i++){
            parent[i]=i;
        }
        size.resize(n,1);
    }

    int findp(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=findp(parent[node]);
    }

    void uni(int u, int v){
        int pu=findp(u);
        int pv=findp(v);
        if(pu==pv){
            return ;
        }
        if(size[pu]< size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    int getsize(int u){
        int x=findp(u);
        return size[x];
    }
};

class Solution {
public:
bool check(int a, int b){
    return __gcd(a, b) > 1;
}
// int dfs(int node, vector<int> & vis, vector<vector<int>> & adj){
// vis[node]=1;
// int ans=1;
//     for(auto it : adj[node]){
//         if(!vis[it]){
//             ans+=dfs(it, vis, adj);
//         }
//     }

//     return ans;
    
// }

void getfact(vector<int> & fac, int node){
    for(int i=2; i*i<=node; i++){
        if(node%i==0){
            fac.push_back(i);
             while(node % i == 0) {
                    node /= i;
                }
        }
    }
    if(node>1){
        fac.push_back(node);
    }
}
    int largestComponentSize(vector<int>& arr) {

        int n=arr.size();
        int maxi= *max_element(arr.begin(), arr.end());
        DisjointSet ds(maxi+1);
        for(int i=0; i< n ; i++){
           vector<int> fac;
           getfact(fac, arr[i]);
           for(auto it :fac){
            ds.uni(arr[i], it);
           }
        }
        // int ans=0;

        // for(int i=0; i< n; i++){
        //     int node=ds.findp(i);
        //     ans=max(ds.getsize(node), ans);
        // }

        unordered_map<int, int> count;
        int ans = 0;

        // // \U0001f534 Corrected final counting loop
        for (int i = 0; i < n; i++) {
            int p = ds.findp(arr[i]);
            count[p]++;
            ans = max(ans, count[p]);
        }


        
        return ans;
        
        
    }
};