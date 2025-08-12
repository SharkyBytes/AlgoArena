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
        for(int i=1; i<=n ; i++){
            int temp= pow(i,x);
            if(temp>n)break;
            nums.push_back(temp);
        }

        int sz=nums.size();

       vector<vector<int>> dp(sz+1, vector<int> (n+1, -1));

     return   recur(0, dp, nums, n, x, sz, 0);

    
    }
};