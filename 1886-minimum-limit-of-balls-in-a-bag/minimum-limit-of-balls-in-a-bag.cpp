class Solution {
public:

    long long count(int mid, vector<int> & nums, int limit, int n){
        long long cnt=0;
        for(int i=0; i< n ; i++){
            if(nums[i]<=mid){
                continue;
            }
            else{
               cnt+= ceil(double(nums[i])/mid)-1;
            }
        }
        return cnt;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {

        int n= nums.size();
        sort(nums.begin(), nums.end());

        int s=1;
        int e= nums[n-1];
        int ans=INT_MAX;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(count(mid, nums, maxOperations,n )<=maxOperations){
                ans=mid;
                e=mid-1;
            }
            else{
               s=mid+1;
            }
        }

        return ans;
        
    }
};