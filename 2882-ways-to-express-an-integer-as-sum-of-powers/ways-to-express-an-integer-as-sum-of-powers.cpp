class Solution {
public:

int mod=1e9+7;

int recur(int ind, vector<vector<int>> & dp, vector<int> &temp , int n, int x, int sz, int curr){
    if(curr>n)return 0;
    if(ind==sz){
        if(curr==n)return 1;
        else return 0;
    }

    if(dp[ind][curr]!=-1){
        return dp[ind][curr];
    }
    int ways=0;

    ways=recur(ind+1, dp, temp, n, x, sz, curr)%mod;
   ways=(ways%mod+ recur(ind+1, dp, temp, n, x, sz, curr+temp[ind])) %mod;

   return dp[ind][curr]=ways;

}


   int numberOfWays(int n, int x) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        int p = pow(i, x);
        if (p > n) break;
        nums.push_back(p);
    }

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int val : nums) {
        for (int sum = n; sum >= val; sum--) {
            dp[sum] = (dp[sum] + dp[sum - val]) % 1000000007;
        }
    }
    return dp[n];
}

};