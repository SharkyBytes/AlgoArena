class Solution {
public:
    string minWindow(string s, string t) {


int n=s.length();

        map<char,int> mp;
        for(auto it : t){
            mp[it]++;

        }

        int sz=mp.size();
        map<char,int> window;
        int formed=0;
        int start=0;
        int mini=INT_MAX;

        int l=0;
        int r=0;
        while(r<n){
            char ch= s[r];
            window[ch]++;

            if(mp.count(ch) && window[ch]==mp[ch]){
                formed++;
            }
            while(l<=r && formed==sz){
                if(r-l+1<mini){
                    mini=r-l+1;
                    start=l;
                }

                char left= s[l];
                window[left]--;
                if(mp.count(left) && mp[left]> window[left]){
                    formed--;
                }
                l++;
            }

            r++;

        }

        return mini==INT_MAX? "" : s.substr(start, mini);


        
    }
};