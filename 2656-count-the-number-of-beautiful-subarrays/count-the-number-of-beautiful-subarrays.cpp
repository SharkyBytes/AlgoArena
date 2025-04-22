

class Solution {
public:
    long long beautifulSubarrays(vector<int>& arr) {

        map<long,long> mp;
        long  n=arr.size();

        long ans=0;
        long cnt=0;
        mp[0]=1;
        for(int i=0; i< n; i++){
            long x= ans^arr[i];
            ans=x;
            cout<<ans<<endl;

            if(mp.find(x)!=mp.end()){
                cnt+=mp[x];
            }
            mp[x]++;
            
        }

        return cnt;
        
    }
};