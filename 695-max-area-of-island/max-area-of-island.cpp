class Solution {
public:
int dfs(int i, int j, int n , int m, vector<vector<int>>& arr, vector<vector<int>> & vis){
    vector<int> dr={-1, 1, 0, 0};
    vector<int> dy ={0,0,-1,1};
    vis[i][j]=1;
     int cnt=1;

    for(int p=0; p< 4; p++){
        int x= dr[p]+i;
        int y=dy[p]+j;
        if(x>=0 && x<n && y>=0 && y<m && arr[x][y]==1 && !vis[x][y]){
            
           cnt+=dfs(x, y, n, m , arr, vis);
        }
    }

    return cnt;
}
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();

        int maxi=0;
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i=0; i< n; i++){
            for(int j=0; j<m ; j++){
                if(arr[i][j]==1 && !vis[i][j]){
                  
                   int cnt= dfs(i, j ,n, m , arr, vis);
                    maxi=max(cnt,maxi);

                }
            }
        }

        return maxi;
    }
};