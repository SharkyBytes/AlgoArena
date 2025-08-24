class Solution {
public:

vector<int> dp;

int recur(int  i , vector<int> & arr, int k, int n){
    if(i>=n)return 0;

    if(dp[i]!=-1)return dp[i];

    int maxi= i+k;
    int maxele=arr[i];
    int sum=0;
    int maxsum=INT_MIN;

    for(int j=i; j<min(maxi, n); j++){
        maxele=max(maxele, arr[j]);
       int sum = (j-i+1)* maxele + recur(j+1, arr, k, n);
        maxsum=max(maxsum,  sum);

    }

    return  dp[i]=maxsum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        dp.assign(n+1, -1);
        return recur(0, arr, k ,n);
        
    }
};