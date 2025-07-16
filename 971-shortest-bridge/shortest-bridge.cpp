class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>> &comp, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        comp.push_back({i,j});

        for(int p=0; p<4; p++){
            int x = i + dx[p];
            int y = j + dy[p];

            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(grid[x][y]==1 && vis[x][y]==0){
                dfs(x, y, grid, comp, vis);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        vector<pair<int,int>> comp1, comp2;

        bool found = false;
        for(int i=0; i<n && !found; i++){
            for(int j=0; j<m && !found; j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,comp1,vis);
                    found = true;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(i,j,grid,comp2,vis);
                }
            }
        }

        queue<pair<pair<int,int>,int>> q; 
        vector<vector<int>> dist(n, vector<int>(m,1e9));

        for(auto &it : comp1){
            q.push({it,0});
            dist[it.first][it.second]=0;
        }

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first.first;
            int j = front.first.second;
            int d = front.second;

            for(int p=0; p<4; p++){
                int x = i + dx[p];
                int y = j + dy[p];

                if(x<0 || y<0 || x>=n || y>=m) continue;

                if(dist[x][y] > d+1){
                    dist[x][y] = d+1;
                    q.push({{x,y}, d+1});
                }
            }
        }

        int ans = 1e9;
        for(auto &it : comp2){
            ans = min(ans, dist[it.first][it.second]-1); 
        }

        return ans;
    }
};
