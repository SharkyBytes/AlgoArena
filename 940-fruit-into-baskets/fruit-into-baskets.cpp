class Solution {
public:
    int totalFruit(vector<int>& arr) {

        int ans=INT_MIN;
        int n=arr.size();
        map<int,int> mp;

        int i=0;
        int j=0;
        while(j < n && i < n ){
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                i++;
            }
            mp[arr[j]]++;
            if(mp.size()<=2){
                ans=max(ans, (j-i+1));
            }
            j++;

        }

        if(mp.size()<=2){
            ans=max(ans, (j-i));
        }
        return ans;
    }
};