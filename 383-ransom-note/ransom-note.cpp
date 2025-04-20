class Solution {
public:
    bool canConstruct(string s, string arr) {

        map<char,int> mp;
        for(auto it: arr){
            mp[it]++;
        }


        for(auto it: s){
            if(mp.find(it)!=mp.end() && mp[it]>0){
                mp[it]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};