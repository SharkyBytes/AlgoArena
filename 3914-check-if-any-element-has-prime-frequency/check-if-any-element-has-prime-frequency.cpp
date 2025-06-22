class Solution {
public:

int prime(int x){
    if(x==1)return false;
    for(int i=2; i<x; i++){
        if(x%i==0)return false;
    }
    return true;
}
    bool checkPrimeFrequency(vector<int>& nums) {

       map<int,int> mp;
       for(auto it : nums){
        mp[it]++;
       }
       for(auto it : mp){
        if(prime(it.second))
{return true;}       }

        return false;
    }

};