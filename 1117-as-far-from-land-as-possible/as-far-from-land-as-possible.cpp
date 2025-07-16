class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    void bfs( vector<vector<int>>& arr,vector<vector<int>>& dist) {
        queue<pair<int, int>> q;
        int n = arr.size();
        int m = arr[0].size();

         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()) {

            auto it = q.front();
            q.pop();
            for (int p = 0; p < 4; p++) {

                int x = dx[p] + it.first;
                int y = dy[p] + it.second;
            if (x < 0 || y < 0 || x >= n || y >= m) {
                    continue;
        }

            if(arr[x][y]==0 && dist[x][y]>=dist[it.first][it.second]+1){
                    dist[x][y] = 1 + dist[it.first][it.second];
                    arr[x][y]=1;
                    q.push({x, y});
                                                
            }
            }
        }
    }
    int maxDistance(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e5));

        bfs(arr ,dist);

       

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(dist[i][j], maxi);
            }
        }
        if(maxi==0)return -1;

        return maxi==1e5 ? -1: maxi;
    }
};