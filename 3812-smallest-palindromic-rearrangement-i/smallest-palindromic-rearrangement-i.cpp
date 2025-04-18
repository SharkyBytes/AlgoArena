class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> abc(26,0);
        int n=s.length();
        for(int i=0; i< n; i++){
            char ch=s[i];
            abc[ch-'a']++;
            
        }
char ch='a';
bool flag=false;
string ans;

        for(int i=0; i< abc.size(); i++){
            if(abc[i]%2!=0){
                int x= abc[i]/2;
                for(int j=0; j<x; j++){
                    ans.push_back(i+'a');
                }
                if(!flag){
                flag=true;
                ch=i+'a';
                }
            }
            else{
                int x= abc[i]/2;
                for(int j=0; j<x; j++){
                    ans.push_back(i+'a');
                }

            }
            // cout<<ans<<" ";
        }

        string temp= ans;
        reverse(ans.begin(), ans.end());
        if(flag) temp+=ch;
        temp+=ans;

        return temp;

    }
};