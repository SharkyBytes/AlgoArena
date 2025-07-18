class Solution {
public:
int ans=0;
vector<int> dx={-1, 0, 1, 0};
vector<int> dy={0, 1,0,-1};

int dfs(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
       int n= arr.size();
       int m=arr[0].size();
       int ans=0;

       for(int p=0; p< 4; p++){
        int x= dx[p]+i;
        int y= dy[p]+j;

        if(x<0 || y<0 || y>=m || x>=n || arr[x][y]<=arr[i][j]){
            continue;
        }
        else if(dp[x][y]!=-1){
            ans=max(ans, dp[x][y]);
        }
        else{
            ans=max(ans, dfs(x,y,arr, dp));
        }
       }


return dp[i][j]=1+ans;
      
}
    int longestIncreasingPath(vector<vector<int>>& arr) {
        
        int n= arr.size();
        int m=arr[0].size();
        int ans=0;

        vector<vector<int>> dp(n, vector<int> (m , -1));
        for(int i=0; i< n; i++){
            for(int j=0; j< m ; j++){
                if(dp[i][j]==-1){
                  ans=max(ans,dfs(i, j ,arr, dp));  
                }
            }
            
        }

        return ans;


    }
};