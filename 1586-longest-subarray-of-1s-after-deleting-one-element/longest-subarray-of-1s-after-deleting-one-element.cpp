class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n=nums.size();
        bool zero=false;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<n){
            if(nums[j]==0 && zero==false){
                zero=true;
            }
            else if(nums[j]==0){
                while(i<n){
                    if(nums[i]==0){
                        i++;
                        break;
                    }
                    i++;
                }
            }
            maxi=max(maxi, (j-i));
            j++;


        }
        return maxi;
        
    }
};