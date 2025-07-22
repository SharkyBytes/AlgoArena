class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int node) {
        if(parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }
    
    void unionFind(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return ; 
        
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return ;
    }
};

class Solution {


public:
    vector<int> findRedundantConnection(vector<vector<int>>& arr) {

        int n=arr.size();
        DisjointSet ds(n);
        vector<int> ans;
        for(int i=0; i< n ; i++){
            int u=arr[i][0];
            int v=arr[i][1];

            int pu=ds.find(u);
            int pv=ds.find(v);
            if(pu==pv){
                ans={u,v};
            }
            else{
               ds.unionFind(u, v);
            }

        }
        return ans;
        
    }
};