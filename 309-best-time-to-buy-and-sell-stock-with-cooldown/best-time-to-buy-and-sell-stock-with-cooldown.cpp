class Solution {
public:
        vector<vector<int>> dp;

int recur(int i , vector<int> & prices, int state, int n){
    if(i>=n)return 0;
    int ans;
    if(dp[i][state]!=-1)return dp[i][state];
    if(state==0){
        int buy= -prices[i]+ recur(i+1, prices, 1, n);
        int notbuy= recur(i+1, prices, 0, n);
        ans=max(buy, notbuy);
    }
    else if(state==1){
        int hold= recur(i+1, prices,1, n);
        int sell= prices[i]+ recur(i+2, prices, 0, n);
        ans=max(sell, hold);
    }
    return dp[i][state]= ans;
}
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        dp.assign(n, vector<int> (2, -1));
        return recur(0, prices, 0, n);
        
    }
};