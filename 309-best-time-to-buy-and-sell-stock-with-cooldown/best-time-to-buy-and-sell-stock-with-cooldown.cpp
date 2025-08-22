class Solution {
public:
vector<vector<int>> dp;
int recur(int ind, vector<int> & arr, int state, int n){
    if(ind>=n)return 0;
    if(dp[ind][state]!=-1)return dp[ind][state];
    
    if(state==0){
        int buy=-arr[ind]+ recur(ind+1, arr, 1, n);
        int notbuy= recur(ind +1, arr, 0 , n);

        return dp[ind][state]= max(buy, notbuy);
    }

    else{
        int sell= +arr[ind]+recur(ind+2, arr, 0, n);
        int notsell= recur(ind +1, arr, 1, n);

        return dp[ind][state]= max(sell, notsell);
    }

    return 0;

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n, vector<int> (2, -1));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1; i< n ; i++){
            // state==0
            int buy= -prices[i];
            if(i>=2) buy+=dp[i-2][1];
            int notbuy= dp[i-1][0];
            dp[i][0]=max(buy, notbuy);

            int sell= prices[i]+ dp[i-1][0];
            int notsell= dp[i-1][1];

            dp[i][1]=max(sell,  notsell);


        }

        return dp[n-1][1];

        // return recur(0, prices, 0, n);
    }
};