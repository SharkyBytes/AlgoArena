class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n+1, 0);
        for(int i=0; i<n; i++) {
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
        if(pu == pv) return ; // Cycle detected
        
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

    int check(){
        int cnt=0;
        for(int i=0; i<parent.size() ; i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& arr) {

        //   if(arr.size() < n-1)
        //     return -1; // Not enough cables

        

        DisjointSet ds(n);
        int cnt=0;
        for(int i=0; i<arr.size() ; i++){
            int u= arr[i][0];
            int v=arr[i][1];
            if(ds.find(u)==ds.find(v)){
                cnt++;
            }
            else{
                ds.unionFind(u,v);
            }
        }

        int req=ds.check()-1;
        return cnt>=req ? req: -1; 
        
    }
};