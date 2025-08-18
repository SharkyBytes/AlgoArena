class Solution {
public:

vector<vector<vector<int>>> dp;
int recur(int i , vector<int> & prices, int n , int state, int k, int curr){
    if(i==n)return 0;
    // if(curr==k)return 0;
    int ans=0;
    if(dp[i][curr][state]!=-1)return dp[i][curr][state];

    if(state==0 && curr<k){
        int buy= -prices[i]+ recur(i+1, prices, n, 1, k, curr+1);
        int notbuy= recur(i+1, prices, n, 0, k, curr);

        ans= max(buy, notbuy);
        
    }
    else if(state==1){
        int sell= prices[i]+ recur(i+1, prices, n, 0,k, curr);
        int hold= recur(i+1, prices, n, 1, k, curr);

        ans= max(sell,hold);
    }

    return dp[i][curr][state]= ans;

}

    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();
        dp.assign(n, vector<vector<int>> (k+1, vector<int> (2, -1)));
        return recur(0, prices, n ,0,  k, 0);
        
    }
};