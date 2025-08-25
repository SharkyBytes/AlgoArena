class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n=nums.size();
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        vector<int> ans(n, 0);
        pref[0]=nums[0];
        for(int i=1;  i< n ; i++){
            pref[i]= max(pref[i-1], nums[i]);
        }

        suff[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i]=min(suff[i+1], nums[i]);
        }

    
        ans[n-1]= pref[n-1];
        for(int i=n-2; i>=0; i--){
            if(pref[i]<=suff[i+1]){
                ans[i]=pref[i];
            }

            else{
                ans[i]=ans[i+1];
            }
        }

        return ans;
        
    }
};