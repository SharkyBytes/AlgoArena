class Solution {
public:
    int minDistance(string s, string p) {
        int n=s.length();
        int m=p.length();
        // reverse(p.begin(), p.end());
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // return recur(0, 0,s, p, n);
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=m ; j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return n+m-2*dp[n][m];
        
    }
};