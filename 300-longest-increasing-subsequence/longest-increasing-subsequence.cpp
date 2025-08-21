class Solution {
public:

vector<vector<int>> dp;

int recur(int ind, vector<int> & nums, int n , int prev){
    if(ind==n)return 0;

    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

    int take=0;
    int notake= recur(ind+1, nums, n, prev);
    
    if(prev==-1 || nums[prev]< nums[ind]){

        take= 1+ recur(ind+1, nums, n, ind);

    }

    return dp[ind][prev+1]= max(take, notake);
}
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        dp.assign(n, vector<int> (n+1, -1));

      return recur(0, nums, n, -1);

        
    }
};