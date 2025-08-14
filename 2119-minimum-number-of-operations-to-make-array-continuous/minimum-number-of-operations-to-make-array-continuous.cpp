class Solution {
public:
    int minOperations(vector<int>& temp) {

        int n=temp.size();
        int maxi=INT_MAX;
        set<int> st(temp.begin(), temp.end());
        vector<int> nums(st.begin(), st.end());
        for(int i=0; i< nums.size() ; i++){
            int left=nums[i];
            int right= left+ n-1;
            int j= upper_bound(nums.begin(),  nums.end(), right)-nums.begin();
            int in= (j-i);
            int out = (n-in);
            maxi=min(maxi, out);
        }

        return maxi;


        
    }
};