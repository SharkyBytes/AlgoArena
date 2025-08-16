class Solution {
public:

int recur(int i, int j, int n, int m, vector<vector<int>> & dp){
   
    if(i==n-1 && j==m-1)return 1;
    if(i>=n || j>=m)return 0;
     if(dp[i][j]!=-1)return dp[i][j];

    int x= recur(i+1, j, n, m, dp);
    int y= recur(i, j+1, n, m, dp);
    return dp[i][j]= x+y;
}
    int uniquePaths(int n, int m) {

        vector<vector<int>>dp(n, vector<int> (m ,-1));

        // return recur(0, 0, n, m, dp);
        dp[0][0]=1;
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(i==0 && j==0)continue;
               int ans=0;
               if(i>0)ans+=dp[i-1][j];
               if(j>0) ans+=dp[i][j-1];
               dp[i][j]=ans;
            }
        }
        return dp[n-1][m-1];
        
    }
};