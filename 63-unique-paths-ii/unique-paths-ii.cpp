class Solution {
public:

int recur(int i, int j, int n , int m, vector<vector<int>> & grid, vector<vector<int>> & dp){
    if(i==n-1 && j==m-1)return 1;
    if(i>=n || j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int x=0, y=0;
    if(i+1<n && grid[i+1][j]==0){
        x=recur(i+1, j, n, m , grid, dp);
    }
    if(j+1<m && grid[i][j+1]==0){
        y=recur(i, j+1, n,m , grid, dp);
    }

    return dp[i][j]=(x+y);
    
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n= obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1 )return 0;
        vector<vector<int>> dp(n, vector<int> (m , -1));
        // return recur(0, 0, n, m, obstacleGrid, dp);
        dp[0][0]=1;

        for(int i=0; i< n ; i++){
            for(int j=0; j< m ; j++){
                if(i==0 && j==0)continue;
                int ans=0;
                if(i-1>=0 && obstacleGrid[i-1][j]==0){
                    ans+=dp[i-1][j];
                }
                 if(j-1>=0 && obstacleGrid[i][j-1]==0){
                    ans+=dp[i][j-1];
                }

                dp[i][j]=ans;
            }
        }
        return dp[n-1][m-1];
    }
};