class Solution {
public:
        vector<vector<int>> dp;
int recur(int i, vector<int> & nums, int n, int prev){
    if(i==n)return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];

    int take=0;
    if(prev==-1 || nums[i]>nums[prev]){
        take=1+ recur(i+1, nums, n, i);
    }
    int notake= recur(i+1 , nums, n, prev);

    return dp[i][prev+1]= max(take, notake);
}
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        dp.assign(n, vector<int> (n+1, -1));
        return recur(0, nums, n, -1);
        
    }
};