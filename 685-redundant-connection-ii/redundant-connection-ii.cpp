class DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1,0);
        for(int i=0; i<=n ;i++){
            parent[i]=i;
        }
    }

    int findp(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findp(parent[node]);
    }

    void uni(int u, int v){
        int p_u= findp(u);
        int p_v=findp(v);
        if(p_u==p_v){
            return;
        }
        if(rank[p_u]<rank[p_v]){
            parent[p_u]=p_v;
        }
        else if(rank[p_v]<rank[p_u]){
            parent[p_v]=p_u;
        }
        else{
            rank[p_v]++;
            parent[p_u]=p_v;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> cand1, cand2;

        // Step 1: Check for two parents
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                cand1 = {parent[v], v};
                cand2 = e;
                e[1] = 0; // temporarily remove edge cand2
            }
        }

        // Step 2: Union-Find to check for cycle
        for (int i = 0; i <= n; i++) parent[i] = i;

        for (auto& e : edges) {
            if (e[1] == 0) continue;
            int u = e[0], v = e[1];
            int pu = find(parent, u);
            if (pu == find(parent, v)) {
                // Cycle detected
                if (cand1.empty()) return e;
                return cand1;
            }
            parent[v] = pu;
        }

        return cand2;
    }

    int find(vector<int>& parent, int u) {
        if (parent[u] != u) parent[u] = find(parent, parent[u]);
        return parent[u];
    }
};
