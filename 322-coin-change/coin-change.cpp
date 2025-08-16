class Solution {
public:

int recur(int ind, vector<int> & arr, int sum,vector<vector<int>> & dp){
   if(sum==0)return 0;
    if(ind==arr.size()){
        return INT_MAX;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    long long take=INT_MAX;

    if(arr[ind]<=sum){
        int x=recur(ind, arr, sum-arr[ind], dp);
        if(x!=INT_MAX)
        take=1+x;
    }
    long long notake= recur(ind+1,arr, sum, dp);

    return dp[ind][sum]=min(notake, take);

}
    int coinChange(vector<int>& coins, int sum) {

        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1 , INT_MAX));
        // int p= recur(0, coins, amount, dp);
        // if(p==INT_MAX)return -1;
        // return p;

        for(int j=1; j<=sum ; j++){
            if(j%coins[0]==0)
            dp[0][j]= j/coins[0];
        }
        for(int i=0; i< n ; i++){
            dp[i][0]=0;
        }

        for(int i=1 ; i< n ; i++){
            for(int j=1; j<=sum; j++){
                int take=INT_MAX;
                if(coins[i]<=j){
                    if(dp[i][j-coins[i]]!=INT_MAX)
                    take=1+dp[i][j-coins[i]];
                } 
                int notake= dp[i-1][j];  
               dp[i][j]=min(take, notake);
            }
        }

        return dp[n-1][sum]>=INT_MAX? -1: dp[n-1][sum];
    }
};