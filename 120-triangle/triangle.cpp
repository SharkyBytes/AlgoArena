class Solution {
public:
int ans= INT_MAX;
int recur(int i, int j, vector<vector<int>> & arr, int n , int m, vector<vector<int>> & dp){
    if(i>=n || j>=arr[i].size() || j<0)return 0;
    if(i==n-1){
        return arr[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int x=INT_MAX, y=INT_MAX;
    x=recur(i+1, j, arr, n , m, dp);
    if(j+1<m)
    y=recur(i+1, j+1, arr,  n , m, dp);

    return dp[i][j]=arr[i][j]+min(x,y);
}
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int> (m , INT_MAX));
        // return recur(0,0,triangle, n ,n, dp);
        dp[0][0]=triangle[0][0];
        if(n==1) return dp[0][0];
        int mini=INT_MAX;
        for(int i=1; i<n ; i++){
            for(int j=0; j<triangle[i].size(); j++){

                int x=INT_MAX, y=INT_MAX;
                if(j>0) x= dp[i-1][j-1];
                y=dp[i-1][j];
                dp[i][j]= triangle[i][j]+min(x,y);
                if(i==n-1){
                    mini=min(mini, dp[i][j]);
                }
            }
        }
        return mini;
        
    }
};