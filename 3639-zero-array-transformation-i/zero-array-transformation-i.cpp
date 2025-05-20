class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int sz=1e5+1;
        vector<int> arr(sz,0);
        for(auto it : queries){
            arr[it[0]]++;
            arr[it[1]+1]--;
        }

        vector<int> cnt(sz,0);
        int curr=0;
        for(int i=0; i< sz; i++){
            curr+=arr[i];
            cnt[i]=curr;
        }

int n=nums.size();
        for(int i=0; i< n; i++){

            if(nums[i]>cnt[i]){
                return false;
            }

        }

        return true;
        
    }
};