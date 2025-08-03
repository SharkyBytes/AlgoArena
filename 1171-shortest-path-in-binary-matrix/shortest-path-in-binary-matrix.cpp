class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Edge case: start or end is blocked
        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;


        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1 && grid[0][0]==0){
            return 1;
        }

        // Direction vectors for 8 possible movements
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // Distance matrix to store the shortest distance to each cell
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;

        // BFS queue
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Traverse all 8 possible directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check if the new cell is within bounds and not blocked
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 && dist[nx][ny]>1+dist[x][y]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});

                    // If we reach the bottom-right cell, return the distance
                    // if (nx == n - 1 && ny == m - 1) {
                    //     return dist[nx][ny];
                    // }
                }
            }
        }

        // If we never reach the bottom-right cell
         return dist[n-1][m-1]==INT_MAX? -1 : dist[n-1][m-1];
    }
};
