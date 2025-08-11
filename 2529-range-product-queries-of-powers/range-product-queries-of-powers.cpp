

class Solution {
public:
int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        int last=0;
        for(int i=0; i<32; i++){
            int x= (n>>i)&1;
            if(x==1){
                last=i;
            }   
        }

        vector<long long> ans;
        int curr=0;
        while(n>0){
            while((1<<last)>n){
                last--;
            }
            ans.push_back((1<<last));
            n-=(1<<last);
        }
        reverse(ans.begin(), ans.end());
        // long long product=1;
        // for(int i=1; i<ans.size() ; i++){
        //     ans[i]= (product*ans[i])%mod;
        //     product=ans[i]%mod;
        // }
        // for(auto it: ans){
        //     cout<<it<<" ";
        // }
        

        vector<int> to_give;

        for(auto it: queries){
            long long product=1;
            for(int i=it[0]; i<=it[1]; i++){
                product*=(ans[i]%mod); 
                product%=mod;              
            }
            to_give.push_back(product%mod);
        }
return to_give;

        
    }
};