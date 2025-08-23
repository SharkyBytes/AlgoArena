class Solution {
public:
vector<int> dp;
// int recur()
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ind=-1;
        int maxi=0;
        // return recur(0, nums, 0);
        dp.assign(n, 1);
        vector<int> prev(n, -1);
        for(int i=0; i< n ; i++){
            prev[i]=i;
            for(int j=0; j< i ; j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }

        vector<int> res;
        while(prev[ind]!=ind){
            res.push_back(nums[ind]);
            ind=prev[ind];
        }
        res.push_back(nums[ind]);

        reverse(res.begin(), res.end());
        return res;


        
    }
};