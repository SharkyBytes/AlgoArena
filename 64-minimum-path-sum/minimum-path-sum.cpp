class Solution {
public:


int recur(int i , int j, int n , int m , vector<vector<int>> & grid, vector<vector<int>> & dp){
    if(i==n-1 && j==m-1) return grid[i][j];
    if(i>=n || j>=m )return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    int x=INT_MAX, y=INT_MAX;

    if(i+1< n){
        x= recur(i+1, j, n, m , grid, dp);
    }
    if(j+1<m){
        y= recur(i, j+1, n, m , grid,dp);
    }

    return dp[i][j]= grid[i][j]+ min(x,y);

}
    int minPathSum(vector<vector<int>>& grid) {

        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m ,0));
        // return recur(0, 0, n,m, grid, dp);
        dp[0][0]=grid[0][0];
        for(int i=0; i< n ; i++){
            for(int j=0; j< m ; j++){
                int x=INT_MAX;int y=INT_MAX;
                if(i==0 && j==0)continue;
                if(i-1>=0)
                x= dp[i-1][j];
                if(j-1>=0)
                y=dp[i][j-1];

                dp[i][j]=grid[i][j]+min(x,y);
            }
        }
        return dp[n-1][m-1];
        
    }
};