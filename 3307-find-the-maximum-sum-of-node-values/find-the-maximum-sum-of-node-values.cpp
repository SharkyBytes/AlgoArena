class Solution {
public:
    void dfs(int node, vector<int>& arr, vector<int>& vis, vector<int> adj[], vector<int>& delta, int k) {
        vis[node] = 1;
        delta[node] = (arr[node] ^ k) - arr[node];
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, arr, vis, adj, delta, k);
            }
        }
    }

    long long maximumValueSum(vector<int>& arr, int k, vector<vector<int>>& edges) {
        int n = arr.size();
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> delta(n, 0);
 long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, arr, vis, adj, delta, k);
            }
            sum+=arr[i]*1l;
        }

       
     sort(delta.begin(), delta.end(), greater<int>());
        for(int i=0;i<n-1;i+=2) {
            if((delta[i] + delta[i+1])>0) {
                sum+=(delta[i] + delta[i+1])*1l;
            }
        }

        return sum;
    }
};