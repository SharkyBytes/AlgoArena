class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<n){
          
            while((curr & nums[j])!=0){
                    curr^=nums[i];
                    i++;
            }
            curr|=nums[j];
            maxi=max(j-i+1, maxi);
            j++;
            
        }

        return maxi;
        
    }
};