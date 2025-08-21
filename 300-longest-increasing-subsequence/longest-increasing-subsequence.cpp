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
        // dp.assign(n, vector<int> (n+1, -1));

    //   return recur(0, nums, n, -1);

    vector<int> lisDP(n, 1);
    int maxi=INT_MIN;
    for(int i=0; i< n ; i++){
        for(int j=0;  j< i; j++){
            if(nums[j]<nums[i]){
                lisDP[i]=max(lisDP[i], 1+lisDP[j]);
            }
        }
    maxi=max(lisDP[i], maxi);
    }

    return maxi;

  
    }
};