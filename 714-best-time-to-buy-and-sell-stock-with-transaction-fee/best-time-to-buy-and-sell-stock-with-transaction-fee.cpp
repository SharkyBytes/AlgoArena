class Solution {
public:

vector<vector<int>> dp;

int recur(int i , int  n, vector<int> & prices, int state, int fee){
    if(i==n)return 0;
    if(dp[i][state]!=-1){
        return dp[i][state];
    }
    int ans=0;
    if(state==0){
        int buy= -prices[i]+ recur(i+1, n, prices, 1, fee);
        int notbuy= recur(i+1, n , prices, 0,fee);
        ans=max(buy, notbuy);

    }
    else if(state==1){
        int sell= prices[i]-fee+recur(i+1, n , prices, 0, fee);
        int hold= recur(i+1, n , prices, 1, fee);
        ans=max(sell, hold);
    }

    return dp[i][state]= ans;
}
    int maxProfit(vector<int>& prices, int fee) {

        int n=prices.size();

        // dp.assign(n, vector<int>(2,-1));

        // return recur(0, n , prices, 0 , fee);
        dp.assign(n, vector<int>(2,0));


        dp[0][0]=-prices[0];
        for(int i=1; i< n ; i++){
            //state==0
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]-prices[i]);
            //state==1
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);
        }

        return dp[n-1][1];
        
    }
};