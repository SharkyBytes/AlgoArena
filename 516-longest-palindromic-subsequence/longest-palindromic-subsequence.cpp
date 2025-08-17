class Solution {
public:

int recur(int i, int j, string s, string p , int n ){
    if(i==n || j==n){
        return 0;
    }

    int ans=0;

    if(s[i]==p[j]){
        ans= 1+ recur(i+1, j+1, s, p, n);

    }
    else{
        ans=max(recur(i+1, j, s, p, n), recur(i, j+1, s, p, n));
    }

    return ans;
}
    int longestPalindromeSubseq(string s) {

        int n=s.length();
        string p=s;
        reverse(p.begin(), p.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        // return recur(0, 0,s, p, n);
        for(int i=1; i<=n ; i++){
            for(int j=1; j<=n ; j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
        
    }
};