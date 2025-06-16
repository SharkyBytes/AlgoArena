class Solution {
public:
    int maximumDifference(vector<int>& nums) {
int mini=INT_MAX;
int maxi=INT_MIN;
        for(auto it : nums){
            if(it<mini){
                mini=it;
            }
            else if(it>mini && mini!=INT_MAX){
                maxi=max(it-mini, maxi);
            }
        }

        return maxi==INT_MIN? -1: maxi;
        
    }
};