class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {

        int n=arr.size();
        map<int,int> mp;
        int i=0, j=0;
        int sum=0;
        int mx=0;
        while(i< n && j< n ){
            while(mp.find(arr[j])!=mp.end() && mp[arr[j]]>=1){
                mp[arr[i]]--;
                sum-=arr[i];
                i++;
            }
            sum+=arr[j];
            mp[arr[j]]++;
            mx=max(mx, sum);
            j++;
        }

        return mx;
        
    }
};