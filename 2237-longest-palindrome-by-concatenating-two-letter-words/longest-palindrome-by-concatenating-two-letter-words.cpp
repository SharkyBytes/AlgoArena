class Solution {
public:
    int longestPalindrome(vector<string>& arr) {

        map<string,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        bool flag=false;
        int len=0;

        for(auto it : mp){
            string p=it.first;
            int cnt= it.second;
            reverse(p.begin(), p.end());
            if(it.first[0]!=it.first[1] && mp.find(p)!=mp.end()){
                int mini=min(mp[it.first], mp[p]);
                len+=(mini*2)*2;
                mp[p]-=mini;
                mp[it.first]-=mini;
                
            }
            else if(it.first[0]==it.first[1]){

                while(cnt>=2){
                    len+=4;
                    cnt-=2;
                }
                if(cnt>=1 && !flag){
                    len+=2;
                    flag=true;
                }
            
            }
        }

        return len;
        
    }
};