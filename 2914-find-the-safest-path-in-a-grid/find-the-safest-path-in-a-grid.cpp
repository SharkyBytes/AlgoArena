#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int,int>> q;

       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny] > dist[x][y]+1){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        // Dijkstra / max-heap path search
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({dist[0][0], {0,0}});

        vector<vector<int>> vis(n, vector<int>(m,0));

        while(!pq.empty()){
            auto [d, pos] = pq.top(); pq.pop();
            int x=pos.first, y=pos.second;
            if(vis[x][y]) continue;
            vis[x][y]=1;

            if(x==n-1 && y==m-1) return d;

            for(int k=0;k<4;k++){
                int nx=x+dx[k], ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    pq.push({min(d, dist[nx][ny]), {nx,ny}});
                }
            }
        }

        return 0; // no path
    }
};
