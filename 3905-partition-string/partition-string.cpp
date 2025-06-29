class Solution {
public:
    vector<string> partitionString(string s) {

        int n=s.length();
        int i=0;
        map<string, int> mp;

        string temp="";
        vector<string> ans;
        while(i<n){
            temp+=s[i];
            if(mp.find(temp)==mp.end()){
                mp[temp]=true;
                ans.push_back(temp);
                temp="";
                
            }
            i++;

        } 
        return  ans;      
    }
};