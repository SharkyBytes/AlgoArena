class Solution {
public:
    int numRabbits(vector<int>& arr) {

        int n=arr.size();
        set<int> st;
        map<int,int> mp;
        int cnt=0;

        for(int i=0;  i< n; i++){

            if(arr[i]!=0){
            mp[arr[i]]++;
            if(mp[arr[i]]==arr[i]+1){
                cnt+=arr[i]+1;
                mp[arr[i]]=0;
            }
            }

            else{
                cnt++;
            }
        }

        for(auto it: mp){
            if(it.second!=0){
                cnt+=it.first+1;
            }
        }

        
return cnt;


        
    }
};