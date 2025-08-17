class Solution {
public:

int recur(int i, vector<int> & prices , int n , int state, vector<vector<int>> & dp){
    if(i==n)return 0;

    if(dp[i][state]!=-1){
        return dp[i][state];
    }

    int ans=0;
    if (state == 0) {
            int buy = -prices[i] + recur(i+1, prices, n, 1, dp);
            int skip = recur(i+1, prices,n, 0, dp);
            ans = max(buy, skip);
    } 
    else {
            int sell = prices[i] + recur(i+1, prices, n, 0 , dp); // state=2 means done
            int skip = recur(i+1, prices, n, 1, dp);
            ans = max(sell, skip);
    }

    return dp[i][state]= ans;
}
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return recur(0, prices, n, 0, dp);
        
    }
};