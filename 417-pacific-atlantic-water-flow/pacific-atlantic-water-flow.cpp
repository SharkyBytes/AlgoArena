class Solution {
public:
vector<int> dx={-1, 0, 1, 0};
vector<int> dy={0, -1, 0, 1};

void dfs(int i, int j , vector<vector<int>> & pac, vector<vector<int>> & arr){
    int n = arr.size();
    int m = arr[0].size();

    pac[i][j]=1;
    for(int p=0; p<4; p++){
        int x=dx[p]+i;
        int y= dy[p]+j;

        if(x<0 || x>=n || y<0 || y>=m){
            continue;
        }
        else if(pac[x][y]!=1 && arr[i][j]<=arr[x][y]){
            pac[x][y]=1;
            dfs(x, y, pac, arr);                  
        }
        else continue;

    }

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            pac[0][i] = 1;
            atl[n - 1][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            pac[i][0] = 1;
            atl[i][m - 1] = 1;
        }

        for(int i=0; i< n; i++){
            for(int j=0; j<m; j++)
            {
                if(pac[i][j]==1){
                    dfs(i, j, pac, arr);
                }
                if(atl[i][j]==1){
                    dfs(i, j, atl, arr);
                }
            }
        }

vector<vector<int>> ans;
for(int i=0; i< n; i++){
    for(int j=0; j< m ; j++)
    {
        if(pac[i][j]==1 && atl[i][j]==1){
            ans.push_back({i, j});
        }
    }
}
return ans;

        
    }
};