class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n=nums.size();
        sort(nums.begin(), nums.end());
        long long x= nums[n-1];
        if(n==2){
            return 2;
        }
        if(n==1){
            return 1;
        }
        int last=0;
        int cnt=0;
        for(int i=0; i<=32; i++){
            long long p=(x>>i) & 1;
            if(p==1){
                last=i;
            }
            else if(p==0){
                cnt++;
            }
        }

        int ans=0;

        while(last>=0){
            ans+=(pow(2,last));
            last--;
        }
        ans+=1;

        return ans;
        
    }
};