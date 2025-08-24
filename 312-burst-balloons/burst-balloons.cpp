class Solution {
public:
  vector<vector<int>> dp;
int recur(int i, int j, vector<int> & nums, int n){
    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int mini=INT_MIN;

    for(int k=i; k<=j ; k++){
        int cost= (nums[i-1]*nums[k]*nums[j+1])+ recur(i, k-1, nums, n)+ recur(k+1, j , nums, n);
        mini=max(cost, mini);
    }
    return dp[i][j]= mini;

}
    int maxCoins(vector<int>& nums) {

        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

       dp.assign(n+2, vector<int> (n+2, -1));

        return recur(1, n, nums, n);
        
    }
};