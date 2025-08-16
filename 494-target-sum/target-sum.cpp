class Solution {
public:
int recur(int ind, vector<int> & nums, int target){
    int n=nums.size();
    if(ind==n){ 
        if(target==0)return 1;
        return 0;
    }

    int pos=recur(ind+1, nums, target+nums[ind]);
    
    int neg= recur(ind+1, nums, target-nums[ind]);

    return pos+neg;

}
    int findTargetSumWays(vector<int>& nums, int target) {

        int n=nums.size();
        
        return recur(0, nums, target);
        
    }
};