class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& arr) {

        int n = arr.size();
        vector<vector<int>> adj(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                adj[i].push_back(arr[i][j]);
                rank[arr[i][j]]++;
            }
        }
        queue<int> q;
        // vector<int> topo;
        map<int,int> mp;

        q.push(0);
        mp[0]=1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                // rank[it]--;
                if(mp[it]==0){
                
                    q.push(it);
                    mp[it] = 1;
                }
                
            }
        }
        for (int i = 0; i < n; i++) {
            if(mp[i] == 0) { return false; }
        }
        return true;
    }
};