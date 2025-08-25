class Solution {
public:
    string minWindow(string s, string t) {

        map<char,int> mp;
        for(auto it :t){
            mp[it]++;
        }
        int req=mp.size();
        int n=s.length();

        map<char,int> window;
        int l=0;
        int r=0;
        int len=INT_MAX;
        int start=0;
        int cnt=0;

        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                window[s[r]]++;
                if(mp[s[r]]==window[s[r]])cnt++;
            }
           

            while(l<n && cnt==req){
                if(r-l+1<len){
                    len=r-l+1;
                    start=l;
                }
                char left= s[l];
                if(window.find(s[l])!=window.end()){
                    window[s[l]]--;
                    if(window[s[l]]< mp[s[l]]){
                        cnt--;
                    }
                }

                l++;
                

            }
            r++;
            

        }


        return len==INT_MAX ? "" : s.substr(start, len);

        
    }
};