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
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1 , -1));
        int p= recur(0, coins, amount, dp);
        if(p==INT_MAX)return -1;
        return p;
        
        
    }
};