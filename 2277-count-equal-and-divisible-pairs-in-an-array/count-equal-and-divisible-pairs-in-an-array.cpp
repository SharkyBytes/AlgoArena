class Solution {
public:
    int countPairs(vector<int>& arr, int k) {

        vector<int> divisors;
        for(int i=1; i*i<=k;  i++){
            if(k%i==0){
                int d= k/i;
                divisors.push_back(i);
                if(d!=i){
                divisors.push_back(d);
                }
            }


        }

        for(auto it: divisors){
            cout<<it<<" ";
        }

        unordered_map<int, vector<int>> mp;
        for(int i=0; i< arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        int ans=0;
     

        for(auto it: mp){
          unordered_map<int, int> mp2;
            int key= it.first;
            vector<int> temp=it.second;

            for(auto i : temp){
                int gcdd= gcd(i,k);
                int need= k/gcdd;
                ans+= mp2[need];

                for(auto p: divisors){
                    if(i%p==0){
                        mp2[p]++;
                    }
                }


            }


        }
        return ans;
    }
};