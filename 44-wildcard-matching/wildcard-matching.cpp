class Solution {
public:

bool recur(int i, int j, string s , string p , int n , int m, vector<vector<int>> &dp ){
    if(i==n&& j==m )return true;
    if(i == n) {
            // remaining pattern must be all '*'
            for(int k = j; k < m; k++) {
                if(p[k] != '*') return false;
            }
            return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    bool ans=0;
   
    if(s[i]==p[j] || p[j]=='?'){
        ans= recur(i+1, j+1, s, p, n , m,dp);
    }

    if(p[j]=='*') {
        ans= recur(i,j+1, s, p, n , m,dp) || recur(i+1, j,s, p, n , m, dp);
    }

    return dp[i][j]= ans;
}
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1 ,-1));

        return recur(0, 0,s, p, n, m, dp);
        
    }
};