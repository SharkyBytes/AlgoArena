class Solution {
public:
int recur(int ind, int n, vector<int> & nums, vector<int> & dp){
    if(ind==n){
        return 0; 
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }

    int pick=nums[ind];
    int notpick=0;
    if(ind+1<n){
        pick+=recur(ind+2, n, nums, dp);
    }
    notpick=recur(ind+1, n, nums, dp);

    return dp[ind]=max(notpick, pick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int> dp(n, -1);
        // return recur(0, n, nums, dp);

        dp[0]=nums[0];
        for(int i=1; i< n ; i++){
            int pick=nums[i];
            if(i>1)pick+=dp[i-2];
            dp[i]=max(dp[i-1], pick);
        }

        return dp[n-1];
    }
};