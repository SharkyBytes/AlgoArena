class Solution {
public:
int sumof(int n){
    int ans=0;
    while(n>0){
        ans+= n%10;
        n/=10;
    }

    return ans;
}
    int countLargestGroup(int n) {

        map<int,int> mp;
        int maxi=0;
        for(int i=1; i<=n; i++){

            int x= sumof(i);
            mp[x]++;
            maxi=max(maxi, mp[x]);

        }
        int ans=0;

        for(auto it: mp){
            if(it.second==maxi){

                ans++;
            }

        }

        return ans;
        
    }
};