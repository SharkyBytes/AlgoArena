class Solution {
public:
int recur(int ind, vector<int> & coins, int amount, vector<vector<int>> & dp){
    int n=coins.size();
    if(ind==n){
       if(amount ==0)return 1;
       return 0;
    }
    if(dp[ind][amount]!=-1){
        return dp[ind][amount];
    }

    int take=0;
    if(coins[ind]<=amount){
        take=recur(ind, coins, amount-coins[ind], dp);
    }
    int notake= recur(ind+1,coins, amount, dp);

    return dp[ind][amount]=take+notake;
    
}

    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return recur(0, coins,amount, dp);
        
    }
};