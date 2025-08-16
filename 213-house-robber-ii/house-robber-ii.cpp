class Solution {
public:

int recur(int ind, int n, vector<int> & nums, vector<int> & dp){
    if(ind==n)return 0;

    if(dp[ind]!=-1){
        return dp[ind];
    }
    
    int pick=nums[ind];
    if(ind+1<n){
        pick+=recur(ind+2, n, nums, dp);

    }
    int nopick= recur(ind+1, n, nums, dp);

    return dp[ind]= max(nopick, pick);
}
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n, -1);
        int x= recur(0, n-1,nums, dp);
        dp.assign(n, -1);
        int y= recur(1, n, nums, dp);

        return max(x,y);
        
    }
};