class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        // Step 1. Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for (auto &d: dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        // Step 2. Max-min path using priority queue
        vector<vector<int>> best(n, vector<int>(n, -1));
        priority_queue<array<int,3>> pq; 
        // {safety, x, y} - max heap by safety
        
        best[0][0] = dist[0][0];
        pq.push({dist[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto [safety, x, y] = pq.top(); pq.pop();
            if (x == n-1 && y == n-1) return safety; // reached goal
            
            for (auto &d: dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newSafety = min(safety, dist[nx][ny]);
                    if (newSafety > best[nx][ny]) {
                        best[nx][ny] = newSafety;
                        pq.push({newSafety, nx, ny});
                    }
                }
            }
        }
        
        return -1; // should not happen (since thieves exist, a path always exists)
    }
};
