class Solution {
public:
    string shortestCommonSupersequence(string s, string p) {


 int n=s.length();
int m=p.length();

        vector<vector<int>> dp(n+1 , vector<int> (m+1,0));

        for(int i=1; i<=n ;i++){
            for(int j=1; j<=m;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int len= dp[n][m];
        // string ans(n, '$');
        int i=n;
        int j=m;
       
        string temp="";
        while(i>0 && j>0 ){
            if(s[i-1]==p[j-1]){
              temp.push_back(s[i-1]);
                i--;
                j--;
                // x--;
            }
            else{
                if(dp[i-1][j]> dp[i][j-1]){
                   temp.push_back(s[i-1]);
                    i--;
                    // x--;
                }
                else{
                   temp.push_back(p[j-1]);
                    j--;
                    // x--;
                }
            }
        }
        
        while(i>0){
            temp.push_back(s[i-1]);
            i--;                        
        }

        while(j>0){
            temp.push_back(p[j-1]);
            j--;
        }
        reverse(temp.begin(), temp.end());
        

return temp;
        
    }
};