class Solution {
public:

int dia(vector<vector<int>>& adj , int start, int n) {
    queue<int> q;
    q.push(start);
    vector<int> vis(n, 0);
    vis[start] = 1;
    int node = start;

    // First BFS to find farthest node
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

    // Second BFS from farthest node
    fill(vis.begin(), vis.end(), 0);
    q.push(node);
    vis[node] = 1;
    int cnt = -1;

    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            int curr = q.front(); q.pop();
            for (auto it : adj[curr]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        cnt++;
    }

    return cnt;
}

int diam(vector<vector<int>> & edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    return dia(adj, 0, n);
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int d1 = diam(edges1);
    int d2 = diam(edges2);

     int merged_diameter = max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
        return merged_diameter;
}
};
