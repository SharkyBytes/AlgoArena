class Solution {
public:
vector<int> dp;
  bool check(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

int recur(int i , string & s, int n ){
    if(i>=n)return -1;
    if(dp[i]!=-1)return dp[i];
    int mini=INT_MAX;
    for(int j=i; j<n ; j++){
        if(check(i, j, s)){
            mini=min(mini, 1+ recur(j+1, s,n));

        }
    }

    return dp[i]= mini;
}
    int minCut(string s) {

        int n=s.size();

        dp.assign(n, -1);
        return recur(0, s, n);
        
    }
};