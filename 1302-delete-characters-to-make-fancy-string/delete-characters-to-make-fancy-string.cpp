class Solution {
public:
    string makeFancyString(string s) {

        string temp="";
        int cnt=0;
        char prev='a';
        for(auto it : s){
            // cnt++;
            if(prev!=it){
                prev=it;
                cnt=0;
            }
            cnt++;
            if(cnt<3){
                temp+=prev;
            }
        }
        return temp;
        
    }
};